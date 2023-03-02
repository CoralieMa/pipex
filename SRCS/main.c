/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:19 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/02 15:10:48 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	(void)argv;
	if (argc != 5)
	{
		write(1, "Wrong number of argument\n", 25);
		return (1);
	}
	paths = ft_get_envp_paths(envp);
	ft_free_all(paths, ft_len_tab(paths));
	system("leaks pipex");
}
