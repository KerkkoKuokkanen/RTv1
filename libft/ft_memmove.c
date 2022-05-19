/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:01:40 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:20:01 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s2 < s1)
	{
		while (++i <= n)
			((unsigned char *)s1)[n - i] = ((unsigned char *)s2)[n - i];
	}
	else
	{
		while (n-- > 0)
		{
			((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
			i++;
		}
	}
	return (s1);
}
