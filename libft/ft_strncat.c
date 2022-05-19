/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:22:36 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:22:38 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	while (i < n && src[i] != '\0')
	{
		dest[len++] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
