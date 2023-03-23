/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:28 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/23 16:57:45 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static char	**get_cmd(char *cmd)
{
	char	**tab;

	tab = ft_split(cmd, ' ');
	if (!tab)
		exit(1);
	return (tab);
}

static void	ft_free_ft_cmd(char **tab, char *cmd)
{
	if (tab)
		ft_free_all(tab);
	if (cmd)
		free(cmd);
}

static int	ft_input_exist(t_pipex *data, char *cmd, int i)
{
	char	**tab;

	tab = ft_split(cmd, ' ');
	if (!tab)
		exit(1);
	data->cmd[i] = ft_my_strcpy(tab[0], data->cmd[i]);	//a changer !!!!!
	ft_free_all(tab);
	if (access(data->cmd[i], F_OK | X_OK) != -1)
		return (1);
	return (0);
}

void	ft_cmd_exist(int argc, char **argv, t_pipex *data)
{
	char	**tab;
	char	*cmd;
	int		i;
	int		j;
	int		ok;

	j = -1;
	while (++j < argc - 3)
	{
		tab = get_cmd(argv[j + 2]);
		cmd = ft_strjoin("/", tab[0]);
		if (!cmd)
			exit(1);
		data->flags[j] = ft_get_flags(argv[j + 2]);
		i = 0;
		ok = ft_input_exist(data, argv[j + 2], j);
		while (data->paths[i] && ok != 1)
		{
			data->cmd[j] = ft_strjoin(data->paths[i], cmd);
			if (!data->cmd[j])
				exit(0);
			if (access(data->cmd[j], F_OK | X_OK) != -1)
				ok = 1;
			++i;
		}
		ft_free_ft_cmd(tab, cmd);
	}
}
