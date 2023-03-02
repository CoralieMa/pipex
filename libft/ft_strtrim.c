/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:32:40 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/19 15:26:51 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_empty(void)
{
	char	*s;

	s = (char *) malloc(sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

static char	*ft_fill(char *s, char const *s1, size_t i, size_t j)
{
	size_t	cpt;

	s[j + 1] = '\0';
	cpt = 0;
	while (cpt <= j)
	{
		s[cpt] = s1[i];
		cpt++;
		i++;
	}
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (ft_is_in_set(s1[i], set) == 1)
		i++;
	if (i - 1 == j)
		return (ft_empty());
	while (ft_is_in_set(s1[j], set) == 1)
		j--;
	j = j - i;
	s = (char *) malloc((j) * sizeof(char) + 2);
	if (!s)
		return (NULL);
	ft_fill(s, s1, i, j);
	return (s);
}
