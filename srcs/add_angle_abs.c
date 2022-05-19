/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_angle_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:20:17 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/17 12:20:37 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

long	ft_abs(int n)
{
	long	x;

	x = n;
	if (n < 0)
		return (-x);
	return (x);
}

void	angle_z_axis(double *x, double *y, double angle)
{
	double	temp;

	temp = *x;
	*x = *x * cos(angle * PI) - *y * sin(angle * PI);
	*y = temp * sin(angle * PI) + *y * cos(angle * PI);
}

void	angle_y_axis(double *x, double *z, double angle)
{
	double	temp;

	temp = *x;
	*x = *x * cos(angle * PI) + *z * sin(angle * PI);
	*z = -temp * sin(angle * PI) + *z * cos(angle * PI);
}

void	angle_x_axis(double *y, double *z, double angle)
{
	double	temp;

	temp = *y;
	*y = *y * cos(angle * PI) - *z * sin(angle * PI);
	*z = temp * sin(angle * PI) + *z * cos(angle * PI);
}
