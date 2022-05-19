/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:05:56 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 16:52:44 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	g_light(t_screen *point, t_cl cl)
{
	t_dot	xyz;

	xyz.x = point->x - cl.light_x;
	xyz.y = point->y - cl.light_y;
	xyz.z = point->z - cl.light_z;
	return (sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z));
}

void	get_dist(t_screen *point, t_cl cl)
{
	t_dot	xyz;

	xyz.x = point->x - cl.light_x;
	xyz.y = point->y - cl.light_y;
	xyz.z = point->z - cl.light_z;
	point->dist = sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z);
}

double	get_dist_from_cam(t_screen *point, t_cl cl)
{
	t_dot	xyz;

	xyz.x = point->x - cl.cam_x;
	xyz.y = point->y - cl.cam_y;
	xyz.z = point->z - cl.cam_z;
	return (sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z));
}

int	dist_to_light(t_sign sign, t_cl *cl)
{
	double	len;
	double	x;
	double	y;
	double	z;

	x = cl->light_x - sign.x;
	y = cl->light_y - sign.y;
	z = cl->light_z - sign.z;
	len = sqrt(x * x + y * y + z * z);
	if (rad_c(cl, len, sign.rad))
		return (1);
	return (0);
}
