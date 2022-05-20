/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:25:05 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/19 12:08:46 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	check_brightness(t_cl *cl)
{
	if (cl->bright < 0)
		cl->bright *= (-1);
	if (cl->bright > 100)
		cl->bright = 100;
}

int	light_end(int count, t_cl *cl)
{
	if (count != 4)
		return (0);
	check_brightness(cl);
	return (1);
}

int	cone_cyl_data(t_sign *obj, int count, int *i, char *line)
{
	if (((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-') && count < 3)
	{
		if (count < 3)
			get_coords(obj, count, *i, line);
		count += 1;
		while ((line[*i + 1] >= '0'
				&& line[*i + 1] <= '9') || line[*i + 1] == '-')
			*i += 1;
	}
	else if ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-')
	{
		if (count < 6)
			get_angle(obj, count, *i, line);
		else if (obj->shape != 4)
			obj->rad = ft_atoi(&line[*i]);
		count += 1;
		while ((line[*i + 1] >= '0'
				&& line[*i + 1] <= '9') || line[*i + 1] == '-')
			*i += 1;
	}
	return (count);
}

int	cam_things(int count, t_cl *cl, char *line, int *i)
{
	if (((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-') && count < 3)
	{
		if (count < 3)
			coord_cam(count, cl, line, *i);
		count++;
		while ((line[*i + 1] >= '0'
				&& line[*i + 1] <= '9') || line[*i + 1] == '-')
			*i += 1;
	}
	else if ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-')
	{
		if (count < 6)
			angle_cam(count, cl, line, *i);
		count++;
		while ((line[*i + 1] >= '0'
				&& line[*i + 1] <= '9') || line[*i + 1] == '-')
			*i += 1;
	}
	return (count);
}

int	get_light(char *l, t_cl *cl)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (l[i])
	{
		if (((l[i] >= '0' && l[i] <= '9') || l[i] == '-') && count < 3)
		{
			get_coord_light(cl, count, i, l);
			count++;
			while ((l[i + 1] >= '0' && l[i + 1] <= '9') || l[i + 1] == '-')
				i++;
		}
		else if ((l[i] >= '0' && l[i] <= '9') || l[i] == '-')
		{
			cl->bright = ft_atoi(&l[i]);
			count++;
			while ((l[i + 1] >= '0' && l[i + 1] <= '9') || l[i + 1] == '-')
				i++;
		}
		i++;
	}
	cl->cl += 3;
	return (light_end(count, cl));
}
