/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:58:52 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/19 11:54:04 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_the_side(double dist, t_sign sign, t_cl cl)
{
	t_dot	xyz;
	double	len;

	xyz.x = sign.x - cl.light_x;
	xyz.y = sign.y - cl.light_y;
	xyz.z = sign.z - cl.light_z;
	len = sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z);
	return (sqrt(len * len - dist * dist));
}

double	curr_r(double side, t_sign sign)
{
	double	h;

	h = CONE_H_HEIGHT;
	return (side / h * sign.rad);
}

void	light_side(t_cl *cl, t_sign *sign)
{
	t_dot	vec1;
	t_dot	vec2;
	double	angle1;
	double	angle2;

	vec1.x = sign->x - cl->cam_x;
	vec1.y = sign->y - cl->cam_y;
	vec1.z = sign->z - cl->cam_z;
	vec2.x = sign->x - cl->light_x;
	vec2.y = sign->y - cl->light_y;
	vec2.z = sign->z - cl->light_z;
	angle1 = two_vecs(vec1, sign->vector);
	angle2 = two_vecs(vec2, sign->vector);
	if ((angle1 > (PI * 0.5) && angle2 < (PI * 0.5))
		|| (angle2 > (PI * 0.5) && angle1 < (PI * 0.5)))
		cl->light_seen = 0;
}

int	cone_check_light(t_cl *cl, t_sign *sign)
{
	double	angle;
	double	len;
	double	dist;

	angle = calculate_angle_vectors(*sign, *cl, &len, 0);
	if (angle < 0.0001)
	{
		sign->io = 1;
		return (1);
	}
	dist = sin(angle) * len;
	if (rad_c(cl, dist, curr_r(get_the_side(dist, *sign, *cl), *sign)))
	{
		sign->io = 1;
		return (1);
	}
	return (0);
}

void	cone_s(t_cl *cl, t_sign *sign)
{
	int	light;
	int	cam;

	light = cone_check_light(cl, sign);
	cam = cone_check_light(cl, sign);
	if ((light == 1 && cam == 0) || (light == 0 && cam == 1))
		cl->light_seen = 0;
	else if (light == 1 && cam == 1)
		light_side(cl, sign);
}
