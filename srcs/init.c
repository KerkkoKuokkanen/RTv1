/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:02:26 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/26 17:36:50 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init(t_cl *cl, int argc)
{
	if (argc == 1)
	{
		write(1, "usage: one parameter file\n", 26);
		exit(0);
	}
	if (argc != 2)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	cl->cl = 0;
	cl->light_seen = 1;
}

void	points_init(t_xy *xy, t_sign *sign, t_cl *cl)
{
	xy->y = 0;
	sign_check_dist_to_obj(sign, cl);
}

void	while_init(int *i, int *s, t_d *d)
{
	*i = 0;
	*s = (-1);
	d->dist = 0;
	d->t_dist = MAX;
}
