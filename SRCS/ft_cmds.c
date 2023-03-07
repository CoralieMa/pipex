/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:28 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/07 12:39:59 by cmartino         ###   ########.fr       */
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

int ft_cmd_exist(int argc, char **argv, t_pipex data)
{
	char **tab;
	char *cmd;
	int	i;
	int temp = 0;
	int ok = 0;

	//tester cmd directement

	data.cmds = malloc(sizeof(data.cmds) * (argc - 2));
	if (!data.cmds)
		return (-1);
	while (temp < argc - 3)
	{
		tab = get_cmd(argv[temp + 2]);
		// sauvegrader qqu part le reste de la cmd + ? ne pas svgd les paths non necessaire ? 
		cmd = ft_strjoin("/", tab[0]);
		data.cmds[temp] = malloc(sizeof(data.cmds[temp]) * (ft_len_tab(data.paths) + 1));
		if (!data.cmds[temp])
			return (-1);
		i = 0;
		while(data.paths[i])
		{
			data.cmds[temp][i] = ft_strjoin(data.paths[i], cmd);
			if (access(data.cmds[temp][i], F_OK | X_OK) != -1)
				ok = 1;
			++i;
		}
		data.cmds[temp][i] = 0;
		++temp;
		ft_free_ft_cmd(tab, cmd);
	}
	data.cmds[temp] = 0;
	return (ok);
}
