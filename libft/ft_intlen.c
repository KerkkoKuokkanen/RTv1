/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:30:21 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/01/31 14:02:14 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_intlen(int n)
{
	long	x;
	int		i;

	if (n == 0)
		return (1);
	x = ft_abs(n);
	i = 0;
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}
