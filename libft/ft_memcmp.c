/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:04:47 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:19:22 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	while (i < n)
	{
		x = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
		if (x != 0)
			return (x);
		i++;
	}
	return (x);
}
