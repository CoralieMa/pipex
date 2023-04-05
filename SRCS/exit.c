/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:26:11 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/05 14:10:43 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_exit(t_pipex *data, int type_err, const char *funct)
{
	printf("%d\n", type_err);
	if (type_err == 1)
	{
		write(2, "Wrong number of argument\n", 25);
		exit(EXIT_FAILURE);
	}
	else if (type_err == 2)
		perror(funct);
	ft_free(data);
	exit(EXIT_FAILURE);
}
