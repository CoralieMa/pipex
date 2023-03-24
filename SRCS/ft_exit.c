/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:49:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/24 14:43:04 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	ft_exit(int err_code, t_pipex *data)
{
	if (err_code == 1)
		write(1, "Wrong number of argument\n", 25);
	else if (err_code == 2)
		write(1, "Error : malloc\n", 26);
	if (data)
		ft_free(data);
	exit(EXIT_FAILURE);
}
