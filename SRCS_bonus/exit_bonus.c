/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:22:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/11 10:35:34 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

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
