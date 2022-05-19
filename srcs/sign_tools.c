/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:15:45 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/17 15:04:41 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sign	*allocate_more(int *num, t_sign *obj)
{
	int		i;
	int		temp;
	t_sign	*new;

	i = 0;
	temp = *num;
	*num = *num * 2;
	new = (t_sign *)malloc(sizeof(t_sign) * *num);
	if (!new)
		mem_error();
	while (i < (temp - 1))
	{
		new[i] = obj[i];
		i++;
	}
	free(obj);
	return (new);
}

void	mem_error(void)
{
	write(1, "memory error\n", 13);
	exit (0);
}

void	file_error(void)
{
	write(1, "file error\n", 11);
	exit(0);
}

void	file_init(int *check, t_xy *in, t_sign **obj)
{
	in->x = 0;
	in->y = 4;
	*check = 1;
	*obj = (t_sign *)malloc(sizeof(t_sign) * in->y);
	if (!obj)
		mem_error();
}

void	get_fd(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		file_error();
}
