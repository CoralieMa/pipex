/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:23:26 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/11 09:23:27 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ten_power(int pow)
{
	int	nb;

	nb = 1;
	while (pow > 0)
	{
		nb = nb * 10;
		pow--;
	}
	return (nb);
}

static char	*ft_zero(void)
{
	char	*tab;

	tab = (char *) malloc(2 * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

static char	*ft_int_min(int n)
{
	char	*tab;
	int		ten;
	int		i;

	tab = (char *) malloc(12 * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '-';
	tab[1] = '2';
	n = 147483648;
	i = 2;
	ten = 9;
	while (i < 11)
	{
		ten--;
		tab[i] = (n / ft_ten_power(ten)) + '0';
		n -= (tab[i] - '0') * ft_ten_power(ten);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	*ft_fill_tab(char *tab, int ten, int nbr)
{
	int	i;
	int	temp;

	i = 0;
	tab[ten] = '\0';
	temp = ten;
	while (i < temp)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			tab[i] = '-';
			ten--;
			i++;
		}
		ten--;
		tab[i] = (nbr / ft_ten_power(ten)) + '0';
		nbr -= (tab[i] - '0') * ft_ten_power(ten);
		i++;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	int		ten;
	int		temp;
	char	*s;

	if (n == 0)
		return (ft_zero());
	if (n == -2147483648)
		return (ft_int_min(n));
	temp = n;
	if (temp < 0)
		temp = -temp;
	ten = 0;
	while (temp >= 1)
	{
		temp = temp / 10;
		ten++;
	}
	if (n < 0)
		ten++;
	s = (char *) malloc(ten * sizeof(char) + 1);
	if (!s)
		return (NULL);
	return (ft_fill_tab(s, ten, n));
}
