/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:06:51 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/27 13:22:27 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	len_check(t_dot *q, double *len, t_sign sign)
{
	if (*len < 0)
	{
		*len *= (-1);
		q->x = sign.x + sign.vector.x * *len;
		q->y = sign.y + sign.vector.y * *len;
		q->z = sign.z + sign.vector.z * *len;
	}
	else
	{
		q->x = sign.x - sign.vector.x * *len;
		q->y = sign.y - sign.vector.y * *len;
		q->z = sign.z - sign.vector.z * *len;
	}
}

void	a_cone_cyl(t_cl cl, t_sign sign, t_screen *point)
{
	t_dot	h;
	t_dot	q;
	t_dot	vec1;
	t_dot	vec2;
	t_dot	a_s;

	h.x = sign.x - point->x;
	h.y = sign.y - point->y;
	h.z = sign.z - point->z;
	a_s.x = two_vecs(h, sign.vector);
	a_s.y = sqrt(h.x * h.x + h.y * h.y + h.z * h.z);
	a_s.z = cos(a_s.x) * a_s.y;
	len_check(&q, &a_s.z, sign);
	vec1.x = q.x - point->x;
	vec1.y = q.y - point->y;
	vec1.z = q.z - point->z;
	vec2.x = cl.light_x - point->x;
	vec2.y = cl.light_y - point->y;
	vec2.z = cl.light_z - point->z;
	point->angle = two_vecs(vec1, vec2);
}

void	a_sphere(t_cl cl, t_sign sign, t_screen *point)
{
	t_dot	vec1;
	t_dot	vec2;

	vec1.x = sign.x - point->x;
	vec1.y = sign.y - point->y;
	vec1.z = sign.z - point->z;
	vec2.x = cl.light_x - point->x;
	vec2.y = cl.light_y - point->y;
	vec2.z = cl.light_z - point->z;
	point->angle = two_vecs(vec1, vec2);
}

void	a_plane(t_cl cl, t_sign sign, t_screen *point)
{
	t_dot	vec;

	vec.x = cl.light_x - point->x;
	vec.y = cl.light_y - point->y;
	vec.z = cl.light_z - point->z;
	point->angle = two_vecs(vec, sign.vector);
}

void	choose_obj(t_sign *sign, t_screen *point, t_cl cl)
{
	int	i;

	i = point->curr;
	if (sign[i].shape == 1)
		a_sphere(cl, sign[i], point);
	else if (sign[i].shape == 2 || sign[i].shape == 3)
		a_cone_cyl(cl, sign[i], point);
	else
	{
		a_plane(cl, sign[i], point);
		if (point->angle > (PI / 2.f))
			point->angle = PI - point->angle;
		return ;
	}
	if (point->angle > (PI / 2.f))
		point->angle = PI - point->angle;
}
