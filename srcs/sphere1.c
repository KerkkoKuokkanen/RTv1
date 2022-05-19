/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:43:06 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 18:33:47 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	intersect_sphere(t_screen *point, t_sign *sign, t_cl cl, int curr)
{
	double	t2;
	double	t1;
	t_dot	abc;
	t_dot	xyz;
	t_dot	vec;

	xyz.x = point->x - sign[curr].x;
	xyz.y = point->y - sign[curr].y;
	xyz.z = point->z - sign[curr].z;
	cyl_vec_calc(*point, &vec, cl);
	abc.x = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	abc.y = 2 * (vec.x * xyz.x + vec.y * xyz.y + vec.z * xyz.z);
	abc.z = (xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z)
		- (sign[curr].rad * sign[curr].rad);
	if ((abc.y * abc.y - 4 * abc.x * abc.z) < 0)
		return (2);
	else if (abc.x == 0)
		return (0);
	t1 = (-abc.y + sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	t2 = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	return (sign_check(point, sign, t2, cl));
}

void	cam_to_sphere(t_xy xy, t_screen *point, t_sign *sign, t_cl cl)
{
	t_dot	xyz;
	t_dot	vec;
	t_dot	abc;
	double	t1;
	double	t2;

	xyz.x = cl.cam_x - sign->x;
	xyz.y = cl.cam_y - sign->y;
	xyz.z = cl.cam_z - sign->z;
	vec_from_cam(&vec, xy.x, xy.y, cl);
	abc.x = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	abc.y = 2 * (vec.x * xyz.x + vec.y * xyz.y + vec.z * xyz.z);
	abc.z = (xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z)
		- (sign->rad * sign->rad);
	if ((abc.y * abc.y - 4 * abc.x * abc.z) < 0 || abc.x == 0)
		return ;
	t1 = (-abc.y + sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	t2 = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2 * abc.x);
	if (t1 > 0 && t2 > 0)
		return ;
	point->tru = 1;
	if (t1 < 0 && t2 < 0)
	{
		get_coord(vec, t1, point, cl);
		return ;
	}
	get_coord(vec, t2, point, cl);
}
