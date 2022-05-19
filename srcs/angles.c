/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:16:36 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/17 12:20:33 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	add_angle(t_dot *vec, int x, int y, t_cl cl)
{
	double	degree;
	t_dot	xyz;
	t_dot	a;

	degree = 2.f / 360.f;
	xyz.x = CAM_RAY - x;
	xyz.y = CAM_RAY - y;
	xyz.z = FOV;
	a.x = degree * (double)cl.a_x;
	a.y = degree * (double)cl.a_y;
	a.z = degree * (double)cl.a_z;
	if (cl.a_x != 0)
		angle_x_axis(&xyz.y, &xyz.z, a.x);
	if (cl.a_y != 0)
		angle_y_axis(&xyz.x, &xyz.z, a.y);
	if (cl.a_z != 0)
		angle_z_axis(&xyz.x, &xyz.y, a.z);
	vec->x = xyz.x;
	vec->y = xyz.y;
	vec->z = xyz.z;
}

t_dot	make_vec_from_point_to_light(t_sign sign, t_cl cl, double *len)
{
	t_dot	vec;
	t_dot	xyz;

	xyz.x = cl.light_x - sign.x;
	xyz.y = cl.light_y - sign.y;
	xyz.z = cl.light_z - sign.z;
	*len = sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z);
	return (xyz);
}

t_dot	make_vec_from_point_to_cam(t_sign sign, t_cl cl, double *len)
{
	t_dot	vec;
	t_dot	xyz;

	xyz.x = cl.cam_x - sign.x;
	xyz.y = cl.cam_y - sign.y;
	xyz.z = cl.cam_z - sign.z;
	*len = sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z);
	return (xyz);
}

double	calculate_angle_vectors(t_sign sign, t_cl cl, double *len, int s)
{
	t_dot	vec;
	t_dot	h;
	t_dot	ab;
	double	angle;

	h = sign.vector;
	if (s == 0)
		vec = make_vec_from_point_to_light(sign, cl, len);
	else
		vec = make_vec_from_point_to_cam(sign, cl, len);
	ab.x = vec.x * h.x + vec.y * h.y + vec.z * h.z;
	ab.y = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	ab.z = sqrt(h.x * h.x + h.y * h.y + h.z * h.z);
	angle = acos(ab.x / (ab.y * ab.z));
	if (ab.y == 0.f || ab.z == 0.f || angle > (PI - 0.00001))
		return (0);
	if (angle > (PI * 0.75))
		return (ft_abs(angle - PI));
	return (angle);
}

double	two_vecs(t_dot vec1, t_dot vec2)
{
	t_dot	calc;

	calc.x = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	calc.y = sqrt(vec1.x * vec1.x + vec1.y * vec1.y + vec1.z * vec1.z);
	calc.z = sqrt(vec2.x * vec2.x + vec2.y * vec2.y + vec2.z * vec2.z);
	return (acos(calc.x / (calc.y * calc.z)));
}
