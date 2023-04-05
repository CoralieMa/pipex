/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:59:16 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/05 12:31:26 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	ft_len_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void	ft_pipe(t_pipex *data, int (*fd)[2])
{
	pipe(*fd);
	if (*fd[0] == -1 || *fd[1] == -1)
		ft_exit(data, 4, __func__);
}
