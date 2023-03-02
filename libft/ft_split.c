/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:32:30 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/02 14:41:54 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_tab(char const *s, char c)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 1;
	if (s[0] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i == 0)
			{
				while (s[i] == c)
				{
					if (!s[++i])
						return (1);
				}
			}
			else if (s[i + 1] && s[i +1] != c)
				cpt++;
		}
		i++;
	}
	return (cpt + 1);
}

char	**ft_free_all(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_last_tab(char **tab, size_t j)
{
	tab[j] = NULL;
	return (tab);
}

static char	**ft_fill_tab(char const *s, char c, char **tab, size_t	cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		cnt = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i + 1] != c && s[i + 1])
			{
				cnt++;
				i++;
			}
			tab[j] = (char *) malloc(cnt * sizeof(char) + 2);
			if (!tab[j])
				return (ft_free_all(tab, j));
			tab[j][cnt + 1] = '\0';
			ft_memcpy(tab[j], &s[i - cnt], cnt + 1);
			j++;
		}
		i++;
	}
	return (ft_last_tab(tab, j));
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	cnt;

	cnt = 0;
	if (!s)
		return (NULL);
	tab = (char **) malloc(ft_len_tab(s, c) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_fill_tab(s, c, tab, cnt));
}
