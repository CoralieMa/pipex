/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:20:33 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/29 10:32:06 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes_bonus/pipex_bonus.h"

char	*ft_get_flags(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != ' ' && tab[i])
		++i;
	while (tab[i] == ' ' && tab[i])
		++i;
	if (tab[i])
		return (&tab[i]);
	return (NULL);
}
