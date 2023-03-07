/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:19 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/07 10:34:14 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		return (ft_exit(1));
	data.paths = ft_get_envp_paths(envp);
	if (ft_cmd_exist(argc, argv, data) != 1)
		return (ft_exit(2));
	ft_free_all(data.paths, ft_len_tab(data.paths));
	system("leaks pipex");
	return (0);
}
