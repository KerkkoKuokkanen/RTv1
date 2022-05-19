/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:36 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:22:14 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = ft_strlen(dst);
	x = 0;
	y = i;
	if (i > size)
		return (ft_strlen(src) + size);
	while (i < (size - 1) && src[x] != '\0')
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (y + ft_strlen(src));
}
