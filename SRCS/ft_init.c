/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:25:49 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/15 15:25:50 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

t_pipex	ft_init()
{
	t_pipex	data;

	data.paths = NULL;
	data.flags = NULL;
	data.check = 1;
	data.cmd = malloc(sizeof(data.cmd) * 3);
	if (!data.cmd)
		data.check = 0;
	else 
		data.cmd[2] = NULL;
	return (data);
}
