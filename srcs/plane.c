/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:52:48 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 19:11:21 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dot	make_normal(t_sign sign)
{
	t_dot	vec;
	double	degree;
	double	x;
	double	y;
	double	z;

	degree = 2.f / 360.f;
	x = 0;
	y = 1;
	z = 0;
	if (sign.a_x != 0)
		angle_x_axis(&y, &z, degree * (double)sign.a_x);
	if (sign.a_y != 0)
		angle_y_axis(&x, &z, degree * (double)sign.a_y);
	if (sign.a_z != 0)
		angle_z_axis(&x, &y, degree * (double)sign.a_z);
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

static void	cam_light_vec(t_cl cl, t_dot *vec)
{
	double	len;
	double	x;
	double	y;
	double	z;

	x = cl.cam_x - cl.light_x;
	y = cl.cam_y - cl.light_y;
	z = cl.cam_z - cl.light_z;
	len = sqrt(x * x + y * y + z * z);
	vec->x = x / len;
	vec->y = y / len;
	vec->z = z / len;
}

double	cam_to_light(t_cl cl, t_sign sign)
{
	t_dot	vec;
	t_dot	xyz;
	double	t;
	double	temp;

	cam_light_vec(cl, &vec);
	temp = vec.x * sign.vector.x
		+ vec.y * sign.vector.y + vec.z * sign.vector.z;
	if (temp < 0.00001)
		return (-1);
	xyz.x = cl.cam_x - sign.x;
	xyz.y = cl.cam_y - sign.y;
	xyz.z = cl.cam_z - sign.z;
	t = (xyz.x * sign.vector.x
			+ xyz.y * sign.vector.y + xyz.z * sign.vector.z) / temp;
	return (t);
}

int	plane_intersect(t_screen *point, t_sign *sign, t_cl cl)
{
	t_dot	vec;
	t_dot	xyz;
	double	t;
	double	temp;

	cyl_vec_calc(*point, &vec, cl);
	temp = vec.x * sign->vector.x + vec.y
		* sign->vector.y + vec.z * sign->vector.z;
	xyz.x = (-1) * (cl.light_x - sign->x);
	xyz.y = (-1) * (cl.light_y - sign->y);
	xyz.z = (-1) * (cl.light_z - sign->z);
	t = (xyz.x * sign->vector.x + xyz.y
			* sign->vector.y + xyz.z * sign->vector.z) / temp;
	if (t == 0.f)
		return (0);
	return (1);
}

void	cam_to_plane(t_xy xy, t_screen *point, t_sign *sign, t_cl cl)
{
	t_dot	vec;
	t_dot	xyz;
	double	t;
	double	temp;

	vec_from_cam(&vec, xy.x, xy.y, cl);
	temp = vec.x * sign->vector.x + vec.y * sign->vector.y
		+ vec.z * sign->vector.z;
	if (temp == 0)
		return ;
	xyz.x = (-1) * (cl.cam_x - sign->x);
	xyz.y = (-1) * (cl.cam_y - sign->y);
	xyz.z = (-1) * (cl.cam_z - sign->z);
	t = (xyz.x * sign->vector.x + xyz.y * sign->vector.y
			+ xyz.z * sign->vector.z) / temp;
	if (t >= 0.f)
		return ;
	point->tru = 1;
	get_coord(vec, t, point, cl);
}
