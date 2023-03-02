/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:59:36 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/10 11:59:39 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*final_s;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		start = 0;
		len = 0;
	}
	if (len > len_s - start)
		len = len_s - start;
	final_s = (char *) malloc (len * sizeof(char) + 1);
	if (!final_s)
		return (NULL);
	i = ft_strlcpy(final_s, &s[start], len + 1);
	while (i < len + 1)
	{
		final_s[i] = '\0';
		i++;
	}
	return (final_s);
}
