/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:34:02 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:18:41 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	long	x;
	long	i;
	int		count;

	count = 0;
	x = n;
	i = 1;
	if (x <= 0)
	{
		x = x * (-1);
		count++;
	}
	while (x > 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

static long	ft_i(int n)
{
	long	x;

	x = n;
	if (x < 0)
		x = x * (-1);
	return (x);
}

static long	ft_x(long n)
{
	long	x;

	x = 1;
	while (x <= n)
	{
		x = x * 10;
	}
	if (n != 0)
		x = x / 10;
	return (x);
}

char	*ft_itoa(int n)
{
	char	*fresh;
	long	i;
	long	x;
	int		i2;
	int		count;

	i = ft_i(n);
	x = ft_x(i);
	count = ft_count(n);
	i2 = 0;
	fresh = (char *)ft_memalloc(sizeof(char) * count + 1);
	if (!fresh)
		return (NULL);
	if (n < 0)
		fresh[i2++] = '-';
	while (x > 1)
	{
		fresh[i2++] = i / x + '0';
		i = i % x;
		x = x / 10;
	}
	fresh[i2++] = i / x + '0';
	fresh[i2] = '\0';
	return (fresh);
}
