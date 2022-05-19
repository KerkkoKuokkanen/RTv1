/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:07:18 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/18 18:26:28 by kkuokkan         ###   ########.fr       */
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

int	count_sub(t_draw *drw, int x, int y)
{
	int		color;
	int		ret;
	double	sub;
	double	min;

	sub = (drw->b[drw->dists[y][x].curr] - drw->l[drw->dists[y][x].curr]);
	if (sub < 0.00001)
		color = 200;
	else if (sub > 10000.f)
	{
		min = drw->l[drw->dists[y][x].curr];
		color = 255.f * (min / drw->dists[y][x].dist);
	}
	else
	{
		sub = 255.f / (drw->b[drw->dists[y][x].curr]
				- drw->l[drw->dists[y][x].curr]);
		color = (drw->b[drw->dists[y][x].curr] - drw->dists[y][x].dist) * sub;
	}
	add_brightnessint(&color, drw->bright);
	ret = color;
	ret ^= color << 8;
	ret ^= color << 16;
	ret ^= color << 24;
	return (ret);
}

void	draw_main(t_draw *drw, void *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < WINDOW_WIDTH)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if ((int)drw->dists[y][x].dist != (-1))
				draw(data, x, y, count_sub(drw, x, y));
			x++;
		}
		free(drw->dists[y]);
		y++;
	}
	free(drw->b);
	free(drw->l);
	free(drw->dists);
}
