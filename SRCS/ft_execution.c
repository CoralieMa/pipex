/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:00:20 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/20 11:59:29 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

t_pipex	ft_cmd_execution(t_pipex data)
{
	
}

pipe() -> int[2]
pid = fork();
if (!pid) // child
{
	dup2(fichierin, STDIN_FILENO);
	close(fichierin);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0])
	close(pipe[1])
	execve("/bin/ls" , [/bin/ls, -l, NULL], envp);
	perror()
	exit();
}
..

fork()
if (!pid)
{
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0])
	close(pipe[1])
	dup2(fichierout, STDOUT_FILENO);
	close(fichierout)
}

while ()
	waitpid()