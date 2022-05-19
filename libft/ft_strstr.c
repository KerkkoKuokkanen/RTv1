/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:53:55 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:23:20 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	tmp_i;
	int	i2;

	i = 0;
	i2 = 0;
	tmp_i = 0;
	if (needle[i2] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		tmp_i = i;
		while (haystack[tmp_i] == needle[i2])
		{
			if (needle[i2 + 1] == '\0')
				return ((char *)haystack + tmp_i - i2);
			tmp_i++;
			i2++;
		}
		i++;
		i2 = 0;
	}
	return (NULL);
}
