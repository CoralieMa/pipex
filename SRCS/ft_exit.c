/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:49:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/27 13:26:12 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	ft_exit(t_pipex *data, int err_code, int exit_stat, const char *funct)
{
	if (err_code == 1)
		write(2, "Wrong number of argument\n", 25);
	else if (err_code == 2)
		perror(funct);
	else if (err_code == 3)
		perror(funct);
	else if (err_code == 4)
		perror(data->outfile);
	if (data)
		ft_free(data);
	exit(exit_stat);
}
