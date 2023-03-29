/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:19:29 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/29 11:29:38 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes_bonus/pipex_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc < 5)
		ft_exit(NULL, 1, EXIT_FAILURE, __func__);
	data = ft_init(argc, argv, envp);
	data.paths = ft_get_envp_paths(envp);
	ft_cmd_exist(argc, argv, &data);
	int i = 0;
	while (data.cmd[i])
	{
		printf("%s\n", data.cmd[i]);
		i++;
	}
	// ft_cmd_execution(&data);
	// ft_free(&data);
	return (0);
}
