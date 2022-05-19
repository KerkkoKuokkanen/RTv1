/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:46:50 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/14 12:16:30 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	count = 0;
	sign = 1;
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			sign = 0;
		else if (sign == 0)
		{
			count++;
			sign = 1;
		}
		i++;
	}
	return (count);
}

static int	count_chr(const char *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static char	**freefree(char **str, int x)
{
	while (x >= 0)
	{
		if (str[x])
			free (str[x]);
		x--;
	}
	free (str);
	return (NULL);
}

static char	**create(const char *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;
	int		x;
	int		y;

	str = create(s, c);
	if (!str)
		return (NULL);
	i = 0;
	x = 0;
	while (x < count_words(s, c) && s[i] != '\0')
	{
		y = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		str[x] = (char *)malloc(sizeof(char) * count_chr(s, i, c) + 1);
		if (!(str[x]))
			return (freefree(str, x));
		while (s[i] != '\0' && s[i] != c)
			str[x][y++] = s[i++];
		str[x][y] = '\0';
		x++;
	}
	str[x] = NULL;
	return (str);
}
