/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:13:05 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 19:10:58 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	rad_c(t_cl *cl, double len, double rad)
{
	double	l;

	l = len - rad;
	if (l > -0.0001 && l < 0.0001)
		cl->light_seen = 0;
	if (len < rad)
		return (1);
	return (0);
}

void	plane_sign_check(t_cl *cl, t_sign sign)
{
	double	t;
	double	len;
	double	x;
	double	y;
	double	z;

	x = cl->light_x - cl->cam_x;
	y = cl->light_y - cl->cam_y;
	z = cl->light_z - cl->cam_z;
	len = sqrt(x * x + y * y + z * z);
	t = cam_to_light(*cl, sign);
	if (t < 0)
		return ;
	if (fabs(t) < len)
		cl->light_seen = 0;
}

void	sphere_sign_check(t_cl *cl, t_sign *sign, int i)
{
	double	x;
	double	y;
	double	z;
	double	len;

	x = cl->cam_x - sign[i].x;
	y = cl->cam_y - sign[i].y;
	z = cl->cam_z - sign[i].z;
	len = sqrt(x * x + y * y + z * z);
	if (len < sign[i].rad)
	{
		sign[i].io = 1;
		cl->o_in = 1;
		if (dist_to_light(sign[i], cl) == 0)
			cl->light_seen = 0;
	}
	else if (dist_to_light(sign[i], cl) == 1)
		cl->light_seen = 0;
}

void	sign_check_dist_to_obj(t_sign *sign, t_cl *cl)
{
	int		i;

	i = 0;
	while (sign[i].shape != 0)
	{
		sign[i].io = 0;
		sign[i].i = 0;
		if (sign[i].shape == 4)
		{
			sign[i].vector = make_normal(sign[i]);
			plane_sign_check(cl, sign[i]);
		}
		else if (sign[i].shape == 2)
			cone_i(sign, i, cl);
		else if (sign[i].shape == 3)
		{
			sign[i].vector = make_normal(sign[i]);
			cyl_s(cl, sign[i]);
		}
		else
			sphere_sign_check(cl, sign, i);
		i++;
	}
}
