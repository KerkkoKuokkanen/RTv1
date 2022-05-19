/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:26:02 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:19:49 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;

	if (!str1 && !str2)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)str1)[i] = ((unsigned char *)str2)[i];
		i++;
	}
	return (str1);
}
