/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:10:14 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 18:33:20 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	make_c_for_cone(t_sign *sign)
{
	sign->cone.x = sign->x - sign->vector.x * CONE_H_HEIGHT;
	sign->cone.y = sign->y - sign->vector.y * CONE_H_HEIGHT;
	sign->cone.z = sign->z - sign->vector.z * CONE_H_HEIGHT;
}

double	cone_m(t_sign sign)
{
	double	h;
	t_dot	ch;

	ch.x = sign.cone.x - sign.x;
	ch.y = sign.cone.y - sign.y;
	ch.z = sign.cone.z - sign.z;
	h = sqrt(ch.x * ch.x + ch.y * ch.y + ch.z * ch.z);
	return ((sign.rad * sign.rad) / (h * h));
}

t_dot	cone_abc(t_dot vec, t_dot xyz, t_sign sign, double m)
{
	t_dot	abc;
	double	vh;
	double	wh;

	vh = vec.x * sign.vector.x + vec.y * sign.vector.y + vec.z * sign.vector.z;
	wh = xyz.x * sign.vector.x + xyz.y * sign.vector.y + xyz.z * sign.vector.z;
	abc.x = (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z)
		- (m * (vh * vh)) - (vh * vh);
	abc.y = 2 * ((vec.x * xyz.x + vec.y * xyz.y + vec.z * xyz.z)
			- (m * (vh * wh)) - (vh * wh));
	abc.z = (xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z)
		- (m * (wh * wh)) - (wh * wh);
	return (abc);
}

int	cone_intersect(t_screen *point, t_sign *sign, t_cl cl)
{
	t_dot	xyz;
	t_dot	vec;
	t_dot	abc;
	t_dot	mtt;

	xyz.x = point->x - sign->x;
	xyz.y = point->y - sign->y;
	xyz.z = point->z - sign->z;
	mtt.x = cone_m(*sign);
	cyl_vec_calc(*point, &vec, cl);
	abc = cone_abc(vec, xyz, *sign, mtt.x);
	if ((abc.y * abc.y - 4 * abc.x * abc.z) < 0)
		return (2);
	else if (abc.x == 0.f)
		return (0);
	mtt.y = (-abc.y + sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	mtt.z = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	return (sign_check(point, sign, mtt.z, cl));
}

void	cone_cam(t_xy xy, t_screen *point, t_sign *sign, t_cl *cl)
{
	t_dot	xyz;
	t_dot	vec;
	t_dot	abc;
	t_dot	mtt;

	xyz.x = cl->cam_x - sign->x;
	xyz.y = cl->cam_y - sign->y;
	xyz.z = cl->cam_z - sign->z;
	mtt.x = cone_m(*sign);
	vec_from_cam(&vec, xy.x, xy.y, *cl);
	abc = cone_abc(vec, xyz, *sign, mtt.x);
	if ((abc.y * abc.y - 4.f * abc.x * abc.z) < 0 || abc.x == 0.f)
		return ;
	mtt.y = (-abc.y + sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	mtt.z = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	if (mtt.y > 0 && mtt.z > 0)
		return ;
	point->tru = 1;
	if (mtt.y < 0 && mtt.z < 0)
	{
		get_coord(vec, mtt.y, point, *cl);
		return ;
	}
	get_coord(vec, mtt.z, point, *cl);
}
