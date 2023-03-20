/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:19 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/20 12:10:49 by cmartino         ###   ########.fr       */
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
	data = ft_cmd_exist(argc, argv, data);
	printf("%s\n%s\n", data.cmd[0], data.cmd[1]);
	// data = ft_cmd_execution(data);
	ft_free(data);
	// system("leaks pipex");
	return (0);
}
