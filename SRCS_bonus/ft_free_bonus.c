/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:20:23 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/29 10:37:10 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes_bonus/pipex_bonus.h"

void	ft_free_all(char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len_tab(tab);
	while (i < len)
		free(tab[i++]);
	free(tab);
}

void	ft_free(t_pipex *data)
{
	if (data->paths)
		ft_free_all(data->paths);
	if (data->cmd)
		ft_free_all(data->cmd);
}