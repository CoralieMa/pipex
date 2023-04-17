/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:26:11 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/17 11:44:46 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
		perror(__func__);
}

void	ft_dup2(t_pipex *data, int fd, int input)
{
	if (dup2(fd, input) == -1)
	{
		ft_exit(data, 2, __func__);
	}
}

void	ft_exit(t_pipex *data, int type_err, const char *funct)
{
	if (type_err == 1)
	{
		write(2, "Wrong number of argument\n", 25);
		exit(EXIT_FAILURE);
	}
	ft_free(data);
	if (type_err == 2)
		perror(funct);
	else if (type_err == 3)
		exit(127);
	else if (type_err == 4)
		exit(128);
	exit(EXIT_FAILURE);
}
