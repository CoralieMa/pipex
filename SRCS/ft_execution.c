/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:00:20 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/24 14:38:54 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

char	**ft_create_tab(t_pipex *data, int i)
{
	char	**tab;

	tab = malloc (3 * sizeof(tab));
	if (!tab)
		ft_exit(2, data);
	tab[0] = data->cmd[i];
	tab[1] = data->flags[i];
	tab[2] = NULL;
	return (tab);
}

void	ft_last_process(t_pipex *data, int *fd, int *fdio)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(fdio[1], STDOUT_FILENO);
	close(fdio[1]);
	execve(data->cmd[1], ft_create_tab(data, 1), data->envp);
	perror(data->cmd[1]);
	exit(EXIT_FAILURE);
}

void	ft_first_process(t_pipex *data, int *fd, int *fdio)
{
	dup2(fdio[0], STDIN_FILENO);
	close(fdio[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	execve(data->cmd[0], ft_create_tab(data, 0), data->envp);
	perror(data->cmd[0]);
	exit(EXIT_FAILURE);
}

void	ft_waitpid(int pid1, int pid2, t_pipex *data)
{
	int	status1;
	int	status2;

	// faire une boucle while pour les waitpid + https://linux.die.net/man/2/waitpid pour gerer status

	if (waitpid(pid1, &status1, 0) == -1)
	{
		perror("waitpid");
		ft_exit(3, data);
	}
	if (waitpid(pid2, &status2, 0) == -1)
	{
		perror("waitpid");
		ft_exit(3, data);
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
	if (fd[0] == -1 || fd[1] == -1 || fdio[0] == -1 || fdio[1] == -1)
		ft_exit(4, data);
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
