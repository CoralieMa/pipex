/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:42:40 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/04 10:42:41 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long		nb;
	int					i;
	int					count;

	count = 0;
	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = ft_sign(str[i]);
		i++;
	}
	while (str[i] == '0')
		i ++;
	while (str[i] >= '0' && str[i] <= '9' && ++count)
		nb = nb * 10 + (str[i ++] - 48);
	if (nb > 9223372036854775807 || count >= 20)
		nb = ft_long(sign);
	return (nb * sign);
}
