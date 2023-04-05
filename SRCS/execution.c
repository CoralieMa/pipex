/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:29:56 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/05 15:28:18 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static void	ft_first_cmd(t_pipex *data, int fd[2], int fdio[2], int *pids)
{
	pids[0] = fork();
	if (pids[0] == 0)
	{
		dup2(fdio[0], STDIN_FILENO);
		close(fdio[0]);
		dup2(fdio[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve(data->cmds[0], &data->argv[2], data->envp);
		ft_exit(data, 45, data->cmds[0]);
	}
}

static void	ft_last_cmd(t_pipex *data, int fd[2], int fdio[2], int *pids)
{
	pids[1] = fork();
	if (pids[1] == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		dup2(fdio[1], STDOUT_FILENO);
		close(fdio[1]);
		execve(data->cmds[1], &data->argv[3], data->envp);
		ft_exit(data, 43, data->cmds[1]);
	}
}

static void	ft_waitpids(t_pipex *data, int *pids)
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
}

static void	ft_open_files(t_pipex *data, int (*fdio)[2])
{
	*fdio[0] = open(data->infile, O_RDONLY);
	*fdio[1] = open(data->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (*fdio[0] == -1)
		perror(data->infile);
	if (*fdio[1] == -1)
		ft_exit(data, 42, __func__);
}

void	ft_execution(t_pipex *data)
{
	int	fdio[2];
	int	fd[2];
	int	*pids;

	ft_open_files(data, &fdio);
	pids = ft_calloc(sizeof(pids), data->argc - 3);
	if (!pids)
		ft_exit(data, 41, __func__);
	ft_pipe(data, &fd);
	ft_first_cmd(data, fd, fdio, pids);
	ft_last_cmd(data, fd, fdio, pids);
	close(fdio[0]);
	close(fdio[1]);
	ft_waitpids(data, pids);
	free(pids);
	pids = NULL;
}
