/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:19 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/15 15:18:41 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		return (ft_exit(1));
	data = ft_init();
	data.paths = ft_get_envp_paths(envp);
	if (data.check != 1)
		return (ft_exit(1));
	data = ft_cmd_exist(argc, argv, data);
	if (data.check != 1)
		return (ft_exit(1));
	printf("%s  %s\n", data.cmd[0], data.cmd[1]);
	printf("%d\n", data.check);
	ft_free_all(data.paths, ft_len_tab(data.paths));
	// system("leaks pipex");
	return (0);
}
