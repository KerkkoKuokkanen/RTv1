/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_and_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:52:00 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/17 14:52:32 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	vec_from_cam(t_dot *vec, int x, int y, t_cl cl)
{
	double	len;
	double	x1;
	double	y1;
	double	z1;

	add_angle(vec, x, y, cl);
	len = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x = vec->x / len;
	vec->y = vec->y / len;
	vec->z = vec->z / len;
}

void	get_coord(t_dot vec, double t, t_screen *point, t_cl cl)
{
	point->x = cl.cam_x + vec.x * t;
	point->y = cl.cam_y + vec.y * t;
	point->z = cl.cam_z + vec.z * t;
}

void	cyl_vec_calc(t_screen point, t_dot *vec, t_cl cl)
{
	double	len;
	t_dot	xyz;

	xyz.x = point.x - (double)cl.light_x;
	xyz.y = point.y - (double)cl.light_y;
	xyz.z = point.z - (double)cl.light_z;
	len = sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z);
	vec->x = xyz.x / len;
	vec->y = xyz.y / len;
	vec->z = xyz.z / len;
}
