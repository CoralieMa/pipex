/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:00:20 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/03 12:18:01 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_last_process(t_pipex *data, int *fd, int *fdio)
{
	char	*tab[3];

	tab[0] = data->cmd[1];
	tab[1] = data->flags[1];
	tab[2] = NULL;
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(fdio[1], STDOUT_FILENO);
	close(fdio[1]);
	execve(data->cmd[1], tab, data->envp);
	ft_exit(data, 5, EXIT_FAILURE, data->cmd2);
}

void	ft_first_process(t_pipex *data, int *fd, int *fdio)
{
	char	*tab[3];

	tab[0] = data->cmd[0];
	tab[1] = data->flags[0];
	tab[2] = NULL;
	dup2(fdio[0], STDIN_FILENO);
	close(fdio[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	execve(data->cmd[0], tab, data->envp);
	ft_exit(data, 5, EXIT_FAILURE, data->cmd1);
}

void	ft_waitpid(int pid1, int pid2, t_pipex *data)
{
	int	status1;
	int	status2;

	if (waitpid(pid1, &status1, 0) == -1)
	{
		perror("waitpid");
		ft_exit(data, 2, WEXITSTATUS(status1), __func__);
	}
	if (waitpid(pid2, &status2, 0) == -1)
	{
		perror("waitpid");
		ft_exit(data, 2, WEXITSTATUS(status2), __func__);
	}
}

void	ft_cmd_execution(t_pipex *data)
{
	int	fd[2];
	int	fdio[2];
	int	pid1;
	int	pid2;

	pipe(fd);
	fdio[0] = open(data->infile, O_RDONLY);
	fdio[1] = open(data->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fdio[0] == -1)
		perror(data->infile);
	if (fd[0] == -1 || fd[1] == -1 || fdio[1] == -1)
		ft_exit(data, 4, EXIT_FAILURE, __func__);
	pid1 = fork();
	if (pid1 == 0)
		ft_first_process(data, fd, fdio);
	close(fd[1]);
	close(fdio[0]);
	pid2 = fork();
	if (pid2 == 0)
		ft_last_process(data, fd, fdio);
	close(fd[0]);
	close(fdio[1]);
	ft_waitpid(pid1, pid2, data);
}
