/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:28 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/15 15:39:54 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static char	**get_cmd(char *cmd)
{
	char	**tab;

	tab = ft_split(cmd, ' ');
	return (tab);
}

static void	ft_free_ft_cmd(char **tab, char *cmd)
{
	ft_free_all(tab, ft_len_tab(tab));
	free(cmd);
}

t_pipex ft_cmd_exist(int argc, char **argv, t_pipex data)
{
	char **tab;
	char *cmd;
	int	i;
	int j;
	int ok;

	//tester cmd directement + faire fonction pour les flags + reduire fct
	j = 0;
	while (j < argc - 3 && data.check != 0)
	{
		tab = get_cmd(argv[j + 2]);
		cmd = ft_strjoin("/", tab[0]);
		i = 0;
		ok = 0;
		while(data.paths[i] && ok != 1)
		{
			data.cmd[j] = ft_strjoin(data.paths[i], cmd);
			if (access(data.cmd[j], F_OK | X_OK) != -1)
				ok = 1;
			++i;
		}
		data.check = ok;
		++j;
		ft_free_ft_cmd(tab, cmd);
	}
	return (data);
}

