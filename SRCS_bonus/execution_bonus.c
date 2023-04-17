/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:21:36 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/17 11:56:39 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

static void	ft_first_cmd(t_pipex *data, int fdio[2])
{
	data->pids[0] = fork();
	if (data->pids[0] == -1)
		ft_exit(data, 2, __func__);
	if (data->pids[0] == 0)
	{
		if (fdio[0] == -1 || !data->cmds[0])
			ft_exit(data, 0, __func__);
		ft_dup2(data, fdio[0], STDIN_FILENO);
		ft_close(fdio[0]);
		ft_dup2(data, data->fd[1], STDOUT_FILENO);
		ft_close(data->fd[1]);
		ft_close(data->fd[0]);
		execve(data->cmds[0], data->flags[0], data->envp);
		ft_exit(data, 2, data->cmds[0]);
	}
}

static void	ft_middle_cmd(t_pipex *data, int fdio[2], int i)
{
	ft_pipe(data);
	data->pids[i] = fork();
	if (data->pids[i] == -1)
		ft_exit(data, 2, __func__);
	if (data->pids[i] == 0)
	{
		if (!data->cmds[i])
			ft_exit(data, 3, __func__);
		ft_dup2(data, fdio[0], STDIN_FILENO);
		ft_close(fdio[0]);
		ft_close(fdio[1]);
		ft_dup2(data, data->fd[1], STDOUT_FILENO);
		ft_close(data->fd[0]);
		ft_close(data->fd[1]);
		execve(data->cmds[i], data->flags[i], data->envp);
		ft_exit(data, 2, data->cmds[i]);
	}
}

static void	ft_last_cmd(t_pipex *data, int fdio[2], int i)
{
	data->pids[i] = fork();
	if (data->pids[i] == -1)
		ft_exit(data, 2, __func__);
	if (data->pids[i] == 0)
	{
		if (!data->cmds[i])
			ft_exit(data, 3, __func__);
		ft_dup2(data, data->fd[0], STDIN_FILENO);
		ft_close(data->fd[0]);
		ft_dup2(data, fdio[1], STDOUT_FILENO);
		ft_close(fdio[1]);
		execve(data->cmds[i], data->flags[i], data->envp);
		ft_exit(data, 2, data->cmds[i]);
	}
}

static void	ft_waitpids(t_pipex *data, int *ret_value)
{
	int	status;
	int	i;

	i = 0;
	while (i < data->argc - 3)
	{
		if (waitpid(data->pids[i], &status, 0) == -1)
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
	int	i;

	ft_pipe(data);
	ft_first_cmd(data, fdio);
	if (fdio[0] != -1)
		ft_close(fdio[0]);
	ft_close(data->fd[1]);
	i = 0;
	while (++i < data->argc - 4)
	{
		fdio[0] = data->fd[0];
		ft_middle_cmd(data, fdio, i);
		ft_close(fdio[0]);
		ft_close(data->fd[1]);
	}
	ft_last_cmd(data, fdio, i);
	ft_close(fdio[1]);
	ft_close(data->fd[0]);
	ft_waitpids(data, ret_value);
}
