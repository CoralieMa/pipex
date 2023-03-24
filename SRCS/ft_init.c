/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:25:49 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/24 11:30:15 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

t_pipex	ft_init(char **argv, char **envp)
{
	t_pipex	data;

	data.paths = NULL;
	data.cmd = ft_calloc(sizeof(data.cmd), 3);
	if (!data.cmd)
		exit(0);
	data.flags[0] = NULL;
	data.flags[1] = NULL;
	data.flags[2] = NULL;
	data.infile = argv[1];
	data.outfile = argv[4];
	data.envp = envp;
	return (data);
}
