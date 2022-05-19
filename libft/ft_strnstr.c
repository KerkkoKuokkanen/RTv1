/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:12:16 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:23:05 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	temp_i;
	size_t	i2;

	i = 0;
	i2 = 0;
	temp_i = 0;
	if (little[i2] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		temp_i = i;
		while (big[temp_i] == little[i2] && temp_i < len)
		{
			if (little[i2 + 1] == '\0')
				return ((char *)big + i);
			temp_i++;
			i2++;
		}
		if (big[i] == '\0')
			return (NULL);
		i2 = 0;
		i++;
	}
	return (NULL);
}
