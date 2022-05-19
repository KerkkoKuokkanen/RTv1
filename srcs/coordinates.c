/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:20:45 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/17 15:01:09 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_coords(t_sign *obj, int count, int i, char *line)
{
	if (count == 0)
		obj->x = ft_atoi(&line[i]);
	else if (count == 1)
		obj->y = ft_atoi(&line[i]);
	else if (count == 2)
		obj->z = ft_atoi(&line[i]);
}

void	get_angle(t_sign *obj, int count, int i, char *line)
{
	if (count == 3)
		obj->a_x = ft_atoi(&line[i]);
	else if (count == 4)
		obj->a_y = ft_atoi(&line[i]);
	else if (count == 5)
		obj->a_z = ft_atoi(&line[i]);
}

void	coord_cam(int count, t_cl *cl, char *line, int i)
{
	if (count == 0)
		cl->cam_x = ft_atoi(&line[i]);
	else if (count == 1)
		cl->cam_y = ft_atoi(&line[i]);
	else
		cl->cam_z = ft_atoi(&line[i]);
}

void	angle_cam(int count, t_cl *cl, char *line, int i)
{
	if (count == 3)
		cl->a_x = ft_atoi(&line[i]);
	else if (count == 4)
		cl->a_y = ft_atoi(&line[i]);
	else
		cl->a_z = ft_atoi(&line[i]);
}

void	get_coord_light(t_cl *cl, int count, int i, char *line)
{
	if (count == 0)
		cl->light_x = ft_atoi(&line[i]);
	else if (count == 1)
		cl->light_y = ft_atoi(&line[i]);
	else
		cl->light_z = ft_atoi(&line[i]);
}
