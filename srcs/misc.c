/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:09:43 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/17 15:15:24 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_screen	copy_struct(int s, t_screen point, t_screen temp)
{
	if (s != (-1))
	{
		point.x = temp.x;
		point.y = temp.y;
		point.z = temp.z;
		point.tru = temp.tru;
		point.l_tru = temp.l_tru;
		point.dist = temp.dist;
		point.curr = s;
	}
	return (point);
}

void	cast_to_function(t_xy xy, t_screen *point, t_sign *sign, t_cl *cl)
{
	if (sign->shape == 1)
		cam_to_sphere(xy, point, sign, *cl);
	else if (sign->shape == 2)
		cone_cam(xy, point, sign, cl);
	else if (sign->shape == 3)
		cam_to_cylinder(xy, point, sign, cl);
	else if (sign->shape == 4)
		cam_to_plane(xy, point, sign, *cl);
}

void	get_min_max_dist(t_draw *drw, double dist, int curr)
{
	if (dist < drw->l[curr])
		drw->l[curr] = dist;
	if (dist > drw->b[curr])
		drw->b[curr] = dist;
}

void	if_check(t_screen *point, t_sign *sign, t_xy xy, t_draw *drw)
{
	get_min_max_dist(drw, point->dist, point->curr);
	drw->dists[xy.y][xy.x].dist = point->dist;
	drw->dists[xy.y][xy.x].curr = point->curr;
	drw->dists[xy.y][xy.x].shape = sign[point->curr].shape;
}

void	make_min_max(t_sign *sign, t_draw *drw)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (sign[i].shape != (-1) && sign[i].shape != 0)
		i++;
	drw->b = (double *)malloc(sizeof(double) * i + 1);
	if (!drw->b)
		mem_error();
	drw->l = (double *)malloc(sizeof(double) * i + 1);
	if (!drw->l)
		mem_error();
	while (j < i)
	{
		drw->b[j] = 0;
		drw->l[j] = MAX;
		j++;
	}
}
