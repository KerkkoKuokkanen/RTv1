/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:19:25 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:22:09 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	int		i;
	int		is;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s))
		return (NULL);
	i = 0;
	is = 0;
	while (s1[is] != '\0')
		s[i++] = s1[is++];
	is = 0;
	while (s2[is] != '\0')
		s[i++] = s2[is++];
	s[i] = '\0';
	return (s);
}
