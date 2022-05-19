/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:30:52 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:23:46 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	size_t	start;
	size_t	end;
	int		i;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (end != start && (s[end] == ' '
			|| s[end] == '\n' || s[end] == '\t' || s[end] == '\0'))
		end--;
	str = (char *)ft_memalloc(sizeof(char) * (end - start) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i++] = s[start];
		start++;
	}
	str[i] = '\0';
	return (str);
}
