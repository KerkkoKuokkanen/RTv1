/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:56:08 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:21:42 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	int	i;

	i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
