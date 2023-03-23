/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:00:20 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/22 14:36:09 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

char	**ft_create_tab(t_pipex data, int i)
{
	char **tab;

	tab = malloc (3 * sizeof(tab));
	if (!tab)
		exit(0);
	tab[0] = data.cmd[i];
	tab[1] = data.flags[i];
	tab[2] = NULL;
	return (tab);
}

void	ft_last_process(t_pipex data, int *fd, int *autrefd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(autrefd[1], STDOUT_FILENO);
	close(autrefd[1]);
	execve(data.cmd[1], ft_create_tab(data, 1), data.envp);

}

void	ft_first_process(t_pipex data, int *fd, int *autrefd)
{
	dup2(autrefd[0], STDIN_FILENO);
	close(autrefd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	execve(data.cmd[0], ft_create_tab(data, 0), data.envp);
	// perror()   -> ?
	// exit();
}

void	ft_cmd_execution(t_pipex data)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int autrefd[2];
	// int	status1;
	// int	status2;

	pipe(fd);
	printf("fd = %d et %d\n", fd[0], fd[1]);
	autrefd[0] = open(data.infile, O_RDONLY);
	autrefd[1] = open(data.outfile, O_WRONLY | O_CREAT, 777);
	printf("autrefd = %d et %d\n", autrefd[0], autrefd[1]);
	pid1 = fork();
	printf("pid1 = %d\n", pid1);
	if (pid1 != 0)
		ft_first_process(data, fd, autrefd);
	wait(NULL);
	pid2 = fork();
	printf("pid2 = %d\n", pid2);
	if (pid2 != 0)
		ft_last_process(data, fd, autrefd);
	// wait(NULL);
	// faire une boucle while pour les waitpid + https://linux.die.net/man/2/waitpid pour gerer status
	// wait(NULL);
	
	// if (waitpid(pid1, &status1, 0) == -1)
	// {
	// 	perror("waitpid");
    //     exit(EXIT_FAILURE);
	// }
	// if (waitpid(pid2, &status2, 0) == -1)
	// {
	// 	perror("waitpid");
    //     exit(EXIT_FAILURE);
	// }
}

// pipe() -> int[2]
// pid = fork();
// if (!pid) // child
// {
// 	dup2(fichierin, STDIN_FILENO);
// 	close(fichierin);
// 	dup2(pipe[1], STDOUT_FILENO);
// 	close(pipe[0])
// 	close(pipe[1])
// 	execve("/bin/ls" , [/bin/ls, -l, NULL], envp);
// 	perror()
// 	exit();
// }
// ..

// fork()
// if (!pid)
// {
// 	dup2(pipe[0], STDIN_FILENO);
// 	close(pipe[0])
// 	close(pipe[1])
// 	dup2(fichierout, STDOUT_FILENO);
// 	close(fichierout)
// }

// while ()
// 	waitpid(pid1)