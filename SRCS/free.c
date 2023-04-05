/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:44:11 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/05 15:25:00 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_free_all(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
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
	if (data->paths)
		ft_free_all(data->paths, ft_len_tab(data->paths));
	if (data->cmds)
		ft_free_all(data->cmds, data->argc - 3);
}
