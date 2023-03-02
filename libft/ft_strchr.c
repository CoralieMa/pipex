/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:18:08 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/04 09:18:10 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&temp[i]);
		i++;
	}
	if (c == '\0')
		return (&temp[i]);
	return (NULL);
}
