/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:17:01 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/12 14:29:59 by cmartino         ###   ########.fr       */
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
		if (tab[0])
			ft_exit(data, 2, __func__);
		ft_get_flag(data, tab, i);
		ft_free_all(tab, ft_len_tab(tab));
		tab = NULL;
		++i;
	}
}

int	ft_test_cmd(t_pipex *data, int i, int j)
{
	int		cmd_ok;
	char	*cmd;
	char	*test;

	cmd_ok = 0;
	cmd = ft_strjoin("/", data->cmds[i]);
	if (!cmd)
		ft_exit(data, 2, __func__);
	test = ft_strjoin(data->paths[j], cmd);
	free(cmd);
	if (!test)
		ft_exit(data, 2, __func__);
	if (access(test, X_OK) == 0)
	{
		free(data->cmds[i]);
		data->cmds[i] = test;
		return (0);
	}
	free(test);
	test = NULL;
	return (1);
}

void	ft_fct(t_pipex *data, int i)
{
	int	j;

	j = 0;
	if (access(data->cmds[i], X_OK) != 0)
	{
		if (!data->paths)
			j = -1;
		while (data->paths && data->paths[j] && ft_test_cmd(data, i, j))
			++j;
	}
	if (j == -1 || (j && !data->paths[j]) || !data->argv[i + 2][0])
	{
		ft_notfound(data->argv[2 + i]);
		free(data->cmds[i]);
		data->cmds[i] = NULL;
	}
	else if (data->flags[i] && data->flags[i][0])
	{
		free(data->flags[i][0]);
		data->flags[i][0] = ft_strdup(data->cmds[i]);
		if (!data->flags[i][0])
			ft_exit(data, 2, __func__);
	}
}

void	ft_cmd_exist(t_pipex *data, int fdio[2])
{
	int	i;

	i = (fdio[0] == -1);
	ft_get_cmd(data);
	while (i < data->argc - 3)
	{
		ft_fct(data, i);
		++i;
	}
}
