/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:20:12 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/29 10:13:07 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes_bonus/pipex_bonus.h"

t_pipex	ft_init(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data.paths = NULL;
	data.infile = argv[1];
	data.outfile = argv[4];
	data.envp = envp;
	data.cmd = ft_calloc(sizeof(data.cmd), argc - 2);
	data.flags = ft_calloc(sizeof(data.flags), argc - 2);
	if (!data.cmd || !data.flags)
		ft_exit(&data, 2, EXIT_FAILURE, __func__);
	return (data);
}