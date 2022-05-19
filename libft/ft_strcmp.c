/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:05:21 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:21:36 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		sign = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
		if (sign != 0)
			return (sign);
		i++;
	}
	return (sign);
}
