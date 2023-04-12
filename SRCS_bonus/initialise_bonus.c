/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:23:10 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/12 14:25:30 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

t_pipex	ft_get_in_order(int argc, char **argv)
{
	t_pipex	data;
	int		i;

	i = 2;
	data.hd = 1;
	data.argc = argc - 1;
	data.argv = argv;
	data.argv[1] = "infile";
	while (i < data.argc)
	{
		data.argv[i] = argv[i + 1];
		++i;
	}
	data.argv[i] = NULL;
	return (data);
}

t_pipex	ft_init_data_here_doc(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data = ft_get_in_order(argc, argv);
	data.envp = envp;
	data.fd[0] = -1;
	data.fd[1] = -1;
	data.infile = "infile";
	data.outfile = argv[argc - 2];
	data.paths = ft_get_envp_paths(envp);
	data.cmds = ft_calloc(sizeof(data.cmds), argc - 3);
	if (!data.cmds)
		ft_exit(&data, 2, __func__);
	data.flags = ft_calloc(sizeof(data.flags), argc - 3);
	if (!data.flags)
		ft_exit(&data, 2, __func__);
	return (data);
}

t_pipex	ft_init_data(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data.hd = 0;
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
