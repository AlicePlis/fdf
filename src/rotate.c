/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:03:06 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/28 15:03:07 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		proj(t_dot *dot, int iso, double x, double y)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;
	double	r;

	tmp_x = dot->x - x;
	tmp_y = dot->y - y;
	tmp_z = dot->z;
	r = -1000;
	if (iso == 1)
	{
		dot->x = (tmp_x - tmp_y) * cos(0.46373398) + x;
		dot->y = (tmp_x + tmp_y) * sin(0.46373398) - tmp_z + y;
	}
	else if (iso == 2)
	{
		dot->x = (tmp_x * r / (tmp_z + r)) + x;
		dot->y = (tmp_y * r / (tmp_z + r)) + y;
		/*dot->z = (tmp_z * r / (tmp_z + r)) + y;*/
	}
}

void		rotate_y(t_dot *dot, t_fdf *data, double x)
{
	double	tmp_x;
	double	tmp_z;

	tmp_x = dot->x - x;
	tmp_z = dot->z;
	dot->x = (cos(data->ang_y) * tmp_x + sin(data->ang_y) * tmp_z) + x;
	dot->z = -sin(data->ang_y) * tmp_x + cos(data->ang_y) * tmp_z;
}

void		rotate_x(t_dot *dot, t_fdf *data, double y)
{
	double	tmp_y;
	double	tmp_z;

	tmp_y = dot->y - y;
	tmp_z = dot->z;
	dot->y = (cos(data->ang_x) * tmp_y - sin(data->ang_x) * tmp_z) + y;
	dot->z = sin(data->ang_x) * tmp_y + cos(data->ang_x) * tmp_z;
}

void		rotate_z(t_dot *dot, t_fdf *data, double x, double y)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = dot->x - x;
	tmp_y = dot->y - y;
	dot->x = (cos(data->ang_z) * tmp_x - sin(data->ang_z) * tmp_y) + x;
	dot->y = (sin(data->ang_z) * tmp_x + cos(data->ang_z) * tmp_y) + y;
}

void		rotate(t_fdf *data)
{
	double		x;
	double		y;

	if (data->iso == 3)
		rotate_scope(data);
	else
	{
		x = (data->width * data->zoom) / 2 + data->shift_x;
		y = (data->height * data->zoom) / 2 + data->shift_y;
		zoom_shift(data);
		rotate_x(data->a, data, y);
		rotate_y(data->a, data, x);
		rotate_z(data->a, data, x, y);
		rotate_x(data->b, data, y);
		rotate_y(data->b, data, x);
		rotate_z(data->b, data, x, y);
		proj(data->a, data->iso, x, y);
		proj(data->b, data->iso, x, y);
	}
}
