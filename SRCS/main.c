/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:59:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/07 14:51:49 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

// note -> proeteger strdup
static void	ft_open_files(t_pipex *data, int fdio[2])
{
	fdio[0] = open(data->infile, O_RDONLY);
	fdio[1] = open(data->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fdio[0] == -1)
		perror(data->infile);
	if (fdio[1] == -1)
		ft_exit(data, 2, __func__);
}

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
	return (ret_value);
}
