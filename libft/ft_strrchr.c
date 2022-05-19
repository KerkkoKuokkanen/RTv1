/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:45:12 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:23:12 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i != 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == c)
		return ((char *)str + i);
	return (NULL);
}
