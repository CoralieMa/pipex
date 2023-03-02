/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:55:46 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/06 10:55:47 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ptr1;
	const char	*ptr2;
	size_t		i;

	if (n == 0)
		return (0);
	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (i < n - 1 && ptr1[i] == ptr2[i])
		i++;
	return ((unsigned char) ptr1[i] - (unsigned char) ptr2[i]);
}
