/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:21:02 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/24 11:29:55 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

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
