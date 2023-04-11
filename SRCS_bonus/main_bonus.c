/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:20:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/11 15:39:35 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		ret_value;
	int		fdio[2];

	if (argc < 5)
		ft_exit(NULL, 1, __func__);
	data = ft_init_data(argc, argv, envp);
	ft_open_files(&data, fdio);
	ft_cmd_exist(&data, fdio);
	ft_execution(&data, &ret_value, fdio);
	ft_free(&data);
	return (ret_value);
}
