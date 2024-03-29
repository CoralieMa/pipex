/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:29:56 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/17 11:51:17 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static void	ft_first_cmd(t_pipex *data, int fd[2], int fdio[2], int *pids)
{
	pids[0] = fork();
	if (pids[0] == -1)
		ft_exit(data, 2, __func__);
	if (pids[0] == 0)
	{
		if (fdio[0] == -1 || !data->cmds[0])
			ft_exit(data, 0, __func__);
		ft_dup2(data, fdio[0], STDIN_FILENO);
		ft_close(fdio[0]);
		ft_dup2(data, fd[1], STDOUT_FILENO);
		ft_close(fd[1]);
		ft_close(fd[0]);
		execve(data->cmds[0], data->flags[0], data->envp);
		ft_exit(data, 2, data->cmds[0]);
	}
}

static void	ft_last_cmd(t_pipex *data, int fd[2], int fdio[2], int *pids)
{
	pids[1] = fork();
	if (pids[1] == -1)
		ft_exit(data, 2, __func__);
	if (pids[1] == 0)
	{
		if (!data->cmds[1])
			ft_exit(data, 3, __func__);
		ft_dup2(data, fd[0], STDIN_FILENO);
		ft_close(fd[0]);
		ft_dup2(data, fdio[1], STDOUT_FILENO);
		ft_close(fdio[1]);
		execve(data->cmds[1], data->flags[1], data->envp);
		ft_exit(data, 2, data->cmds[1]);
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
	int	fd[2];
	int	pids[2];

	pids[0] = 0;
	pids[1] = 0;
	ft_pipe(data, &fd);
	ft_first_cmd(data, fd, fdio, pids);
	if (fdio[0] != -1)
		ft_close(fdio[0]);
	ft_close(fd[1]);
	ft_last_cmd(data, fd, fdio, pids);
	ft_close(fdio[1]);
	ft_close(fd[0]);
	ft_waitpids(data, pids, ret_value);
}
