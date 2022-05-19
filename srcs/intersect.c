/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:46:03 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 15:01:33 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	sign_check(t_screen *point, t_sign *sign, double t2, t_cl cl)
{
	double	light;

	if (cl.light_seen == 0)
		return (0);
	light = g_light(point, cl);
	if (fabs(t2) > light)
		return (1);
	if (t2 > -0.0001)
		return (1);
	return (0);
}

int	pick_first_intersections(t_screen *point, t_sign *sign, t_cl cl)
{
	if (sign[point->curr].shape == 1)
		return (intersect_sphere(point, sign, cl, point->curr));
	if (sign[point->curr].shape == 2)
		return (cone_intersect(point, &sign[point->curr], cl));
	if (sign[point->curr].shape == 3)
		return (cylinder_intersect(point, &sign[point->curr], cl));
	if (sign[point->curr].shape == 4 && cl.light_seen == 1)
		return (1);
	return (0);
}

int	second_intersection(t_screen *point, t_sign *sign, t_cl cl, int i)
{
	if (sign[i].shape == 1)
		return (intersect_sphere(point, sign, cl, i));
	if (sign[i].shape == 2)
		return (cone_intersect(point, &sign[i], cl));
	if (sign[i].shape == 3)
		return (cylinder_intersect(point, &sign[i], cl));
	if (sign[i].shape == 4)
		return (plane_intersect(point, &sign[i], cl));
	return (0);
}

int	check_intersections(t_screen *point, t_sign *sign, t_cl cl)
{
	int	i;
	int	j;
	int	bool;

	i = 0;
	bool = 0;
	while (sign[i].shape != 0)
	{
		if (pick_first_intersections(point, sign, cl) == 1)
		{
			bool = 1;
			if (point->curr != i)
			{
				if (!second_intersection(point, sign, cl, i))
					return (0);
			}
		}
		i++;
	}
	if (bool == 0)
		return (0);
	get_dist(point, cl);
	return (1);
}
