/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:19:41 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/06/22 14:40:10 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_screen	cam_to_screen(t_xy xy, t_sign *sign, t_cl *cl)
{
	int			i;
	int			s;
	t_d			d;
	t_screen	point;
	t_screen	temp;

	while_init(&i, &s, &d);
	while (sign[i].shape != 0 && sign[i].shape != (-1))
	{
		point.tru = 0;
		cast_to_function(xy, &point, &sign[i], cl);
		if (point.tru == 1)
		{
			d.dist = get_dist_from_cam(&point, *cl);
			if (d.dist < d.t_dist)
			{
				d.t_dist = d.dist;
				temp = point;
				s = i;
			}
		}
		i++;
	}
	return (copy_struct(s, point, temp));
}

void	points_on_the_screen(void *data, t_sign *sign, t_cl cl)
{
	t_xy		xy;
	t_screen	point;

	points_init(&xy, sign, &cl);
	while (xy.y < WINDOW_WIDTH)
	{
		xy.x = 0;
		while (xy.x < WINDOW_WIDTH)
		{
			point = cam_to_screen(xy, sign, &cl);
			if (point.tru == 1)
			{
				if (check_intersections(&point, sign, cl) == 1)
				{
					choose_obj(sign, &point, cl);
					draw(data, xy.x, xy.y, get_color(point, cl.bright));
				}
			}
			xy.x++;
		}
		xy.y++;
	}
	free(sign);
}

void	main_while(SDL_Event ev)
{
	while (1)
	{
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT
				|| ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_sdl	sdl;
	t_cl	cl;
	t_sign	*sign;
	void	*data;
	int		pitch;

	init(&cl, argc);
	sign = create_sign(argv[1], &cl);
	if (cl.cl != 5)
		file_error();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH,
		0, &sdl.window, &sdl.renderer);
	SDL_RenderClear(sdl.renderer);
	sdl.buffer = SDL_CreateTexture(sdl.renderer, SDL_PIXELFORMAT_BGRA8888,
			SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_WIDTH);
	SDL_LockTexture(sdl.buffer, NULL, &data, &pitch);
	points_on_the_screen(data, sign, cl);
	SDL_UnlockTexture(sdl.buffer);
	SDL_RenderCopy(sdl.renderer, sdl.buffer, NULL, NULL);
	SDL_RenderPresent(sdl.renderer);
	main_while(sdl.ev);
}
