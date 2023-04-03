/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:25:49 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/03 11:41:18 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

t_pipex	ft_init(char **argv, char **envp)
{
	t_pipex	data;

	data.paths = NULL;
	data.cmd1 = argv[2];
	data.cmd2 = argv[3];
	data.flags[0] = NULL;
	data.flags[1] = NULL;
	data.flags[2] = NULL;
	data.infile = argv[1];
	data.outfile = argv[4];
	data.envp = envp;
	data.cmd = ft_calloc(sizeof(data.cmd), 3);
	if (!data.cmd)
		ft_exit(&data, 2, EXIT_FAILURE, __func__);
	return (data);
}
