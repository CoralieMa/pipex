/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:23:10 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/11 15:46:11 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

t_pipex	ft_init_data(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.fd[0] = -1;
	data.fd[1] = -1;
	data.infile = argv[1];
	data.outfile = argv[argc - 1];
	data.paths = ft_get_envp_paths(envp);
	data.cmds = ft_calloc(sizeof(data.cmds), argc - 3);
	if (!data.cmds)
		ft_exit(&data, 2, __func__);
	data.flags = ft_calloc(sizeof(data.flags), argc - 3);
	if (!data.flags)
		ft_exit(&data, 2, __func__);
	return (data);
}
