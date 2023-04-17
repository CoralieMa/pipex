/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:20:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/17 11:15:30 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		ret_value;
	int		fdio[2];
	int		hc;

	hc = 0;
	if (argc < 5 || argc > 4099)
		ft_exit(NULL, 1, __func__);
	if (!ft_strncmp(argv[1], "here_doc", 8) && ft_strlen(argv[1]) == 8)
	{
		hc = 1;
		if (argc < 6 || argc > 4100)
			ft_exit(NULL, 10, __func__);
		ft_here_doc(argv);
		data = ft_init_data_here_doc(argc, argv, envp);
	}
	else
		data = ft_init_data(argc, argv, envp);
	ft_open_files(&data, fdio);
	ft_cmd_exist(&data, fdio);
	ft_execution(&data, &ret_value, fdio);
	if (data.hd == 1)
		unlink("/Users/cmartino/Desktop/pipex/infile");
	ft_free(&data);
	return (ret_value);
}
