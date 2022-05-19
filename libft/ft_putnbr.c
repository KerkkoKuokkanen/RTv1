/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:35:06 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:20:38 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	looks(int n)
{
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}

void	ft_putnbr(int n)
{
	long	i;
	long	x;
	int		ch;

	i = 1;
	x = n;
	if (looks(n))
		return ;
	if (x < 0)
	{
		ft_putchar('-');
		x = x * (-1);
	}
	while (i <= x)
		i = i * 10;
	i = i / 10;
	while (i != 1)
	{
		ch = x / i;
		ft_putchar(ch + '0');
		x = x % i;
		i = i / 10;
	}
	ch = x / i;
	ft_putchar(ch + '0');
}
