/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:26:11 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/07 13:46:30 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

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
	exit(EXIT_FAILURE);
}
