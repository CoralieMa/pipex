/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:17:01 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/05 15:28:54 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static void	ft_get_cmd(t_pipex *data)
{
	int		i;
	char	**tab;

	i = 0;
	while (i < data->argc - 3)
	{
		tab = ft_split(data->argv[i + 2], ' ');
		if (!tab)
			ft_exit(data, 2, __func__);
		data->cmds[i] = ft_strdup(tab[0]);
		ft_free_all(tab, data->argc - 3);
		tab = NULL;
		++i;
	}
}

int	ft_test_cmd(t_pipex *data, int i, int j)
{
	int		cmd_ok;
	char	*cmd;

	cmd_ok = 0;
	cmd = ft_strjoin("/", data->argv[i + 2]);
	if (!cmd)
		ft_exit(data, 2, __func__);
	data->cmds[i] = ft_strjoin(data->paths[j], cmd);
	free(cmd);
	if (!data->cmds[i])
		ft_exit(data, 2, __func__);
	if (access(data->cmds[i], F_OK | X_OK) == 0)
		return (0);
	else
	{
		free(data->cmds[i]);
		data->cmds[i] = NULL;
	}
	return (1);
}

void	ft_cmd_exist(t_pipex *data)
{
	int	i;
	int	j;

	i = 0;
	ft_get_cmd(data);
	while (i < data->argc - 3)
	{
		if (access(data->cmds[i], F_OK | X_OK) != 0)
		{
			free(data->cmds[i]);
			data->cmds[i] = NULL;
			j = 0;
			while (data->paths && data->paths[j] && ft_test_cmd(data, i, j))
				++j;
		}
		++i;
	}
}
