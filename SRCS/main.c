/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:59:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/05 15:24:51 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		ft_exit(NULL, 1, __func__);
	data = ft_init_data(argc, argv, envp);
	ft_cmd_exist(&data);
	// ft_execution(&data);
	// ft_free(&data);
}
