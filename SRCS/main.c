/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:19 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/29 14:22:53 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		ft_exit(NULL, 1, EXIT_FAILURE, __func__);
	data = ft_init(argv, envp);
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
