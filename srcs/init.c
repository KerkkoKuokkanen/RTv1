/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:02:26 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/20 11:56:31 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init(t_cl *cl, int argc)
{
	if (argc != 2)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	cl->cl = 0;
	cl->light_seen = 1;
}

void	points_init(t_xy *xy, t_draw *drw, t_sign *sign, t_cl *cl)
{
	xy->y = 0;
	drw->bright = cl->bright;
	make_min_max(sign, drw);
	drw->dists = (t_dists **)malloc(sizeof(t_dists *) * 1000);
	if (!drw->dists)
		mem_error();
	sign_check_dist_to_obj(sign, cl);
}

void	dist_memory(t_draw *drw, t_xy xy)
{
	drw->dists[xy.y] = (t_dists *)malloc(sizeof(t_dists) * 1000);
	if (!drw->dists[xy.y])
		mem_error();
}

void	while_init(int *i, int *s, t_d *d)
{
	*i = 0;
	*s = (-1);
	d->dist = 0;
	d->t_dist = MAX;
}

void	cone_i(t_sign *sign, int i, t_cl *cl)
{
	sign[i].vector = make_normal(sign[i]);
	make_c_for_cone(&sign[i]);
	cone_s(cl, &sign[i]);
}
