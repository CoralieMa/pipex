/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:22:26 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/17 10:47:42 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	ft_free_all(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
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
		ft_free_all(data->cmds, data->argc - 3);
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
	free(data->pids);
}
