/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:01:55 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 18:33:35 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	dist_from_cyl(t_cl *cl, t_sign sign, int s)
{
	double	angle;
	double	len;
	double	dist;

	angle = calculate_angle_vectors(sign, *cl, &len, s);
	if (angle < 0.0001f)
		return (1);
	dist = sin(angle) * len;
	if (rad_c(cl, dist, sign.rad))
		return (1);
	return (0);
}

void	cyl_s(t_cl *cl, t_sign sign)
{
	int	light;
	int	cam;

	light = dist_from_cyl(cl, sign, 0);
	cam = dist_from_cyl(cl, sign, 1);
	if ((light == 1 && cam == 0) || (light == 0 && cam == 1))
		cl->light_seen = 0;
}

static void	make_cyl_abc(t_dot *abc, t_dot vec, t_dot xyz, t_sign sign)
{
	double	v_h;
	double	w_h;
	double	rad;

	rad = sign.rad;
	v_h = vec.x * sign.vector.x + vec.y * sign.vector.y + vec.z * sign.vector.z;
	w_h = xyz.x * sign.vector.x + xyz.y * sign.vector.y + xyz.z * sign.vector.z;
	abc->x = (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z) - (v_h * v_h);
	abc->y = 2 * ((vec.x * xyz.x + vec.y * xyz.y + vec.z * xyz.z)
			- (v_h * w_h));
	abc->z = (xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z) - (w_h * w_h)
		- (rad * rad);
}

int	cylinder_intersect(t_screen *point, t_sign *sign, t_cl cl)
{
	t_dot	xyz;
	t_dot	vec;
	t_dot	abc;
	double	t1;
	double	t2;

	xyz.x = point->x - sign->x;
	xyz.y = point->y - sign->y;
	xyz.z = point->z - sign->z;
	cyl_vec_calc(*point, &vec, cl);
	make_cyl_abc(&abc, vec, xyz, *sign);
	if ((abc.y * abc.y - 4 * abc.x * abc.z) < 0)
		return (2);
	else if (abc.x == 0.f)
		return (0);
	t1 = (-abc.y + sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	t2 = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	return (sign_check(point, sign, t2, cl));
}

void	cam_to_cylinder(t_xy xy, t_screen *point, t_sign *sign, t_cl *cl)
{
	t_dot	xyz;
	t_dot	vec;
	t_dot	abc;
	double	t1;
	double	t2;

	xyz.x = cl->cam_x - sign->x;
	xyz.y = cl->cam_y - sign->y;
	xyz.z = cl->cam_z - sign->z;
	vec_from_cam(&vec, xy.x, xy.y, *cl);
	make_cyl_abc(&abc, vec, xyz, *sign);
	if ((abc.y * abc.y - 4.f * abc.x * abc.z) < 0 || abc.x == 0.f)
		return ;
	t1 = (-abc.y + sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	t2 = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	if (t1 > 0 && t2 > 0)
		return ;
	point->tru = 1;
	if (t1 < 0 && t2 < 0)
	{
		get_coord(vec, t1, point, *cl);
		return ;
	}
	get_coord(vec, t2, point, *cl);
}
