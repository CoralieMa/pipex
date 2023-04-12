/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:59:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/12 15:22:20 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

// note -> proteger dup2

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		ret_value;
	int		fdio[2];

	if (argc != 5)
		ft_exit(NULL, 1, __func__);
	data = ft_init_data(argc, argv, envp);
	ft_open_files(&data, fdio);
	ft_cmd_exist(&data, fdio);
	ft_execution(&data, &ret_value, fdio);
	ft_free(&data);
	// system("lsof -c pipex");
	return (ret_value);
}
