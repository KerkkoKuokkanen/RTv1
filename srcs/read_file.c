/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:22:13 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/19 12:10:59 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	object_checker(char *line, int i)
{
	if (ft_strnequ(line, "sphere", i) == 1)
		return (1);
	else if (ft_strnequ(line, "cone", i) == 1)
		return (2);
	else if (ft_strnequ(line, "cylinder", i) == 1)
		return (3);
	else if (ft_strnequ(line, "plane", i) == 1)
		return (4);
	else if (ft_strnequ(line, "light", i) == 1)
		return (5);
	else if (ft_strnequ(line, "cam", i) == 1)
		return (6);
	return (0);
}

static int	check_line(char *line)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] == ':')
		{
			num = object_checker(line, i);
			return (num);
		}
		i++;
	}
	return (0);
}

int	create_object(char *line, t_cl *cl, t_sign *obj, int o)
{
	if (o == 0)
		return (0);
	else if (o == 5 && get_light(line, cl) == 0)
		return (0);
	else if (o == 6 && get_cam(line, cl) == 0)
		return (0);
	else if (o == 1 && obj_sphere(line, obj) == 0)
		return (0);
	else if (o == 2 && obj_cone(line, obj) == 0)
		return (0);
	else if (o == 3 && obj_cylinder(line, obj) == 0)
		return (0);
	else if (o == 4 && obj_plane(line, obj) == 0)
		return (0);
	return (1);
}

t_sign	*create_sign(char *file, t_cl *cl)
{
	int		check;
	t_sign	*obj;
	t_file	f;
	t_xy	in;

	file_init(&check, &in, &obj);
	get_fd(file, &f.fd);
	while (check == 1)
	{
		check = get_next_line(f.fd, &f.line);
		if (check == 1)
		{
			if (in.x == (in.y - 1))
				obj = allocate_more(&in.y, obj);
			if (create_object(f.line, cl, &obj[in.x], check_line(f.line)) == 0)
				file_error();
			in.x++;
			free(f.line);
		}
		else if (check == (-1))
			file_error();
	}
	obj[in.x - 2].shape = 0;
	return (obj);
}
