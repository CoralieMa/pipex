/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:14:04 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/17 15:01:38 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

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
