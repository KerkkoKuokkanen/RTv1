/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:40:03 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/07/18 15:01:34 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H
# define L_D 16000.f
# define MAX 100000000.f
# define WINDOW_WIDTH 1000
# define CAST_JUMP 4
# define CAM_RAY 500
# define FOV 3000
# define PI 3.14159265
# define CONE_H_HEIGHT 100
# define A_DIST 2600.f
# define CLR 255.f
# define MULTI 3.f

# include <stdlib.h>
# include <SDL2/SDL.h>
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_screen
{
	int		tru;
	int		curr;
	double	x;
	double	y;
	double	z;
	double	dist;
	double	angle;
}			t_screen;

typedef struct s_dot
{
	double	x;
	double	y;
	double	z;
}				t_dot;

// 1 = sphere, 2 = cone, 3 = cylinder, 4 = plane

typedef struct s_sign
{
	int		shape;
	int		x;
	int		y;
	int		z;
	int		rad;
	int		a_x;
	int		a_y;
	int		a_z;
	t_dot	vector;
	t_dot	cone;
}				t_sign;

typedef struct s_cl
{
	int	cl;
	int	cam_x;
	int	cam_y;
	int	cam_z;
	int	light_x;
	int	light_y;
	int	light_z;
	int	a_x;
	int	a_y;
	int	a_z;
	int	light_seen;
	int	bright;
}				t_cl;

typedef struct s_d
{
	double	dist;
	double	t_dist;
}				t_d;

typedef struct s_xy
{
	int	x;
	int	y;
}				t_xy;

typedef struct s_file
{
	int		fd;
	char	*line;
}				t_file;

typedef struct s_sdl
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Event		ev;
	SDL_Texture		*buffer;
}				t_sdl;

int			get_color(t_screen point, int b);
int			intersect_sphere(t_screen *point, t_sign *sign, t_cl cl, int curr);
int			cone_intersect(t_screen *point, t_sign *sign, t_cl cl);
int			cylinder_intersect(t_screen *point, t_sign *sign, t_cl cl);
int			check_intersections(t_screen *point, t_sign *sign, t_cl cl);
int			sign_check(t_screen *point, double t2, t_cl cl);
int			get_next_line(const int fd, char **line);
int			plane_intersect(t_screen *point, t_sign *sign, t_cl cl);
int			dist_from_cyl(t_cl *cl, t_sign sign, int s);
int			light_end(int count, t_cl *cl);
int			cone_cyl_data(t_sign *obj, int count, int *i, char *line);
int			cam_things(int count, t_cl *cl, char *line, int *i);
int			get_light(char *l, t_cl *cl);
int			get_cam(char *line, t_cl *cl);
int			obj_plane(char *line, t_sign *obj);
int			obj_cylinder(char *line, t_sign *obj);
int			obj_cone(char *line, t_sign *obj);
int			obj_sphere(char *line, t_sign *obj);
int			dist_to_light(t_sign sign, t_cl *cl);
int			rad_c(t_cl *cl, double len, double rad);
long		ft_abs(int n);
void		draw(void *data, int x, int y, int color);
void		choose_obj(t_sign *sign, t_screen *point, t_cl cl);
void		plane_sign_check(t_cl *cl, t_sign sign);
void		sphere_sign_check(t_cl *cl, t_sign *sign, int i);
void		sign_check_dist_to_obj(t_sign *sign, t_cl *cl);
void		while_init(int *i, int *s, t_d *d);
void		points_init(t_xy *xy, t_sign *sign, t_cl *cl);
void		check_brightness(t_cl *cl);
void		mem_error(void);
void		file_error(void);
void		cone_s(t_cl *cl, t_sign *sign);
void		make_c_for_cone(t_sign *sign);
void		cam_to_cylinder(t_xy xy, t_screen *point, t_sign *sign, t_cl *cl);
void		cam_to_sphere(t_xy xy, t_screen *point, t_sign *sign, t_cl cl);
void		get_dist(t_screen *point, t_cl cl);
void		add_angle(t_dot *vec, int x, int y, t_cl cl);
void		vec_from_cam(t_dot *vec, int x, int y, t_cl cl);
void		get_coord(t_dot vec, double t, t_screen *point, t_cl cl);
void		cam_to_plane(t_xy xy, t_screen *point, t_sign *sign, t_cl cl);
void		angle_z_axis(double *x, double *y, double angle);
void		angle_y_axis(double *x, double *z, double angle);
void		angle_x_axis(double *y, double *z, double angle);
void		cyl_s(t_cl *cl, t_sign sign);
void		cone_cam(t_xy xy, t_screen *point, t_sign *sign, t_cl *cl);
void		cyl_vec_calc(t_screen point, t_dot *vec, t_cl cl);
void		light_seen(t_cl *cl, t_sign *sign);
void		file_init(int *check, t_xy *in, t_sign **obj);
void		get_fd(char *file, int *fd);
void		get_coords(t_sign *obj, int count, int i, char *line);
void		get_angle(t_sign *obj, int count, int i, char *line);
void		coord_cam(int count, t_cl *cl, char *line, int i);
void		angle_cam(int count, t_cl *cl, char *line, int i);
void		get_coord_light(t_cl *cl, int count, int i, char *line);
void		init(t_cl *cl, int argc);
void		sign_check_dist_to_obj(t_sign *sign, t_cl *cl);
void		cast_to_function(t_xy xy, t_screen *point, t_sign *sign, t_cl *cl);
double		g_light(t_screen *point, t_cl cl);
double		cam_to_light(t_cl cl, t_sign sign);
double		calculate_angle_vectors(t_sign sign, t_cl cl, double *len, int s);
double		two_vecs(t_dot vec1, t_dot vec2);
double		get_dist_from_cam(t_screen *point, t_cl cl);
t_sign		*create_sign(char *file, t_cl *cl);
t_sign		*allocate_more(int *num, t_sign *obj);
t_dot		make_normal(t_sign sign);
t_screen	copy_struct(int s, t_screen point, t_screen temp);

#endif
