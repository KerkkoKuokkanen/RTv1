/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:09:43 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/26 17:34:05 by kkuokkan         ###   ########.fr       */
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
