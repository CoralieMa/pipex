/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:25:49 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/20 12:11:26 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

t_pipex	ft_init(void)
{
	t_pipex	data;

	data.paths = NULL;
	data.cmd = ft_calloc(sizeof(data.cmd), 3);
	data.flags = ft_calloc(sizeof(data.flags), 3);
	if (!data.cmd || !data.flags)
		exit(0);
	return (data);
}
