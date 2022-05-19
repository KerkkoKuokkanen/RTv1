/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:33:39 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/13 15:18:19 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_whitespace(const char *str, int i)
{
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		return (1);
	return (0);
}

static int	make_i(const char *str)
{
	int	i;

	i = 0;
	while (check_whitespace(str, i))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	atoi;
	int	plusminus;

	atoi = 0;
	plusminus = 1;
	i = make_i(str);
	if (str[i] == '-')
	{
		plusminus = (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			atoi = atoi * 10 + str[i] - '0';
		else
			return (atoi * plusminus);
		i++;
	}
	return (atoi * plusminus);
}
