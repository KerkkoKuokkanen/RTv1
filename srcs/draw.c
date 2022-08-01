/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:07:18 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/27 13:28:50 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw(void *data, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_WIDTH)
		return ;
	*(int *)(data + (x + y * WINDOW_WIDTH) * CAST_JUMP) = color;
}

void	add_brightnessint(int *color, int b)
{
	double	temp;

	if (b < 50)
	{
		temp = *color;
		temp = (temp / 50.f) * (double)b;
		*color = (int)temp;
	}
	else if (b > 50)
	{
		temp = 255 - *color;
		temp = (temp / 50.f) * ((double)b - 50.f);
		*color += (int)temp;
	}
}

int	get_color(t_screen point, int b)
{
	int		color;
	int		ret;
	double	sub;
	double	one;
	double	di;

	one = MULTI / (PI / 2.f);
	sub = CLR / L_D;
	di = point.dist + (A_DIST * (one * point.angle));
	color = CLR - sub * di;
	if (color < 0)
		color = 0;
	add_brightnessint(&color, b);
	ret = color;
	ret ^= color << 8;
	ret ^= color << 16;
	ret ^= color << 24;
	return (ret);
}
