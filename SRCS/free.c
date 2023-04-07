/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:44:11 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/07 15:00:31 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_free_all(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		++i;
	}
	free(tab);
	tab = NULL;
}

void	ft_free(t_pipex *data)
{
	int	i;

	if (data->paths)
		ft_free_all(data->paths, ft_len_tab(data->paths));
	if (data->cmds)
	{
		if (!data->cmds[0] && data->cmds[1])
			free(data->cmds[1]);
		ft_free_all(data->cmds, data->argc - 3);
	}
	i = 0;
	if (data->flags)
	{
		while (i < data->argc - 3)
		{
			ft_free_all(data->flags[i], ft_len_tab(data->flags[i]));
			++i;
		}
		free(data->flags);
		data->flags = NULL;
	}
}
