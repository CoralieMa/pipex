/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:19 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/23 17:17:08 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		return (ft_exit(1));
	data = ft_init(argv, envp);
	data.paths = ft_get_envp_paths(envp);
	ft_cmd_exist(argc, argv, &data);
	ft_cmd_execution(&data);
	ft_free(&data);
	system("leaks pipex");
	return (0);
}

/* ameliorer ft_exit pour ne plus avoir de leaks*/