/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:21:36 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/12 15:19:25 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

static void	ft_first_cmd(t_pipex *data, int fdio[2], int *pids)
{
	pids[0] = fork();
	if (pids[0] == 0)
	{
		if (fdio[0] == -1 || !data->cmds[0])
			ft_exit(data, 0, __func__);
		dup2(fdio[0], STDIN_FILENO);
		close(fdio[0]);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[1]);
		close(data->fd[0]);
		execve(data->cmds[0], data->flags[0], data->envp);
		ft_exit(data, 2, data->cmds[0]);
	}
}

static void	ft_middle_cmd(t_pipex *data, int fdio[2], int *pids, int i)
{
	ft_pipe(data);
	pids[i] = fork();
	if (pids[i] == 0)
	{
		if (!data->cmds[i])
			ft_exit(data, 3, __func__);
		dup2(fdio[0], STDIN_FILENO);
		close(fdio[0]);
		close(fdio[1]);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		execve(data->cmds[i], data->flags[i], data->envp);
		ft_exit(data, 2, data->cmds[i]);
	}
}

static void	ft_last_cmd(t_pipex *data, int fdio[2], int *pids, int i)
{
	pids[i] = fork();
	if (pids[i] == 0)
	{
		if (!data->cmds[i])
			ft_exit(data, 3, __func__);
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[0]);
		dup2(fdio[1], STDOUT_FILENO);
		close(fdio[1]);
		execve(data->cmds[i], data->flags[i], data->envp);
		ft_exit(data, 2, data->cmds[i]);
	}
}

static void	ft_waitpids(t_pipex *data, int *pids, int *ret_value)
{
	int	status;
	int	i;

	i = 0;
	while (i < data->argc - 3)
	{
		if (waitpid(pids[i], &status, 0) == -1)
		{
			perror("waitpid");
			ft_exit(data, WEXITSTATUS(status), __func__);
		}
		++i;
	}
	*ret_value = WEXITSTATUS(status);
}

void	ft_execution(t_pipex *data, int *ret_value, int fdio[2])
{
	int	*pids;
	int	i;

	pids = ft_calloc(sizeof(int), data->argc - 3);
	if (!pids)
		ft_exit(data, 41, __func__);
	ft_pipe(data);
	ft_first_cmd(data, fdio, pids);
	close(fdio[0]);
	close(data->fd[1]);
	i = 0;
	while (++i < data->argc - 4)
	{
		fdio[0] = data->fd[0];
		ft_middle_cmd(data, fdio, pids, i);
		close(fdio[0]);
		close(data->fd[1]);
	}
	ft_last_cmd(data, fdio, pids, i);
	close(fdio[1]);
	close(data->fd[0]);
	ft_waitpids(data, pids, ret_value);
	free(pids);
	pids = NULL;
}
