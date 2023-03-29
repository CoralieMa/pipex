/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:19:46 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/29 10:36:36 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes_bonus/pipex_bonus.h"

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

char	*ft_my_strcpy(char *src, char *dst)
{
	size_t	i;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dst = ft_calloc(len + 1, sizeof(dst));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		++i;
	}
	return (dst);
}