/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:08:49 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/04 11:08:51 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	c = (char)c;
	temp = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (&temp[i]);
	while (i >= 0)
	{
		if (s[i] == c)
			return (&temp[i]);
		i--;
	}
	return (NULL);
}
