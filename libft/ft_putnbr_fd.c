/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:17:12 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:20:31 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checks(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	long	x;
	int		ch;

	i = 1;
	x = n;
	if (checks(n, fd))
		return ;
	if (x < 0)
	{
		write (fd, "-", 1);
		x = x * (-1);
	}
	while (i <= x)
		i = i * 10;
	i = i / 10;
	while (i != 1)
	{
		ch = x / i;
		ft_putchar_fd(ch + '0', fd);
		x = x % i;
		i = i / 10;
	}
	ch = x / i;
	ft_putchar_fd(ch + '0', fd);
}
