/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_and_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:29:40 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/19 12:09:25 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	get_cam(char *line, t_cl *cl)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		count = cam_things(count, cl, line, &i);
		i++;
	}
	if (count != 6)
		return (0);
	cl->cl += 2;
	return (1);
}

int	obj_plane(char *line, t_sign *obj)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	obj->shape = 4;
	while (line[i])
	{
		count = cone_cyl_data(obj, count, &i, line);
		i++;
	}
	if (count != 6)
		return (0);
	return (1);
}

int	obj_cylinder(char *line, t_sign *obj)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	obj->shape = 3;
	while (line[i])
	{
		count = cone_cyl_data(obj, count, &i, line);
		i++;
	}
	if (count != 7)
		return (0);
	return (1);
}

int	obj_cone(char *line, t_sign *obj)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	obj->shape = 2;
	while (line[i])
	{
		count = cone_cyl_data(obj, count, &i, line);
		i++;
	}
	if (ft_abs(obj->rad) > 590)
		obj->rad = 590;
	if (count != 7)
		return (0);
	return (1);
}

int	obj_sphere(char *line, t_sign *obj)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	obj->shape = 1;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (count < 3)
				get_coords(obj, count, i, line);
			else
				obj->rad = ft_atoi(&line[i]);
			count++;
			while ((line[i + 1] >= '0' && line[i + 1] <= '9')
				|| line[i + 1] == '-')
				i++;
		}
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}
