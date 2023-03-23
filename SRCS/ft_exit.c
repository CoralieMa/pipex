/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:49:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/23 12:42:07 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	ft_exit(int code)
{
	if (code == 1)
		write(1, "Wrong number of argument\n", 25);
	else if (code == 2)
		write(1, "Error : command not found\n", 26);
	exit(0);
}
