/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_dot(t_fdf *data, int x, int y)
{
	data->a->z = (double)data->z_matrix[(int)data->a->y]
	[(int)data->a->x] * data->up * data->zoom;
	data->z = data->a->z;
	data->b->z = (double)data->z_matrix[(int)y][(int)x] * data->up * data->zoom;
	data->z1 = data->b->z;
	data->b->x = x;
	data->b->y = y;
	if (!data->color_flag)
		data->color = (data->a->z > data->b->z) ? (color_fill(data, data->a->z))
											: (color_fill(data, data->b->z));
	else
		data->color = (data->a->z > data->b->z) ? data->c_matrix[(int)data->a->y][(int)data->a->x] :
				  data->c_matrix[(int)data->b->y][(int)data->b->x];
	rotate(data);
}

void		plot(t_fdf *data, t_dot *dot)
{
	int		*img;

	img = (int*)data->data_ptr;
	if (((int)dot->x < data->w_width && (int)dot->x > 0) &&
		((int)dot->y < data->w_height && (int)dot->y > 0))
		if (check_buffer(data, dot))
			*(img + (int)dot->x + (int)dot->y * data->w_width) = data->color;
}

void		zoom_shift(t_fdf *data)
{
	data->a->x *= data->zoom;
	data->a->y *= data->zoom;
	data->b->x *= data->zoom;
	data->b->y *= data->zoom;
	data->a->x += data->shift_x;
	data->a->y += data->shift_y;
	data->b->x += data->shift_x;
	data->b->y += data->shift_y;
}

static void	draw_base(double x1, double y1, t_fdf *data)
{
	double	x_step;
	double	y_step;
	double	z_step;
	double	max;
	double	z;

	init_dot(data, x1, y1);
	z = (data->z < data->z1) ? data->z : data->z1;
	x_step = data->b->x - data->a->x;
	y_step = data->b->y - data->a->y;
	z_step = data->b->z - data->a->z;
	max = ft_maxf(ft_absf(x_step), ft_absf(y_step));
	x_step /= max;
	y_step /= max;
	z_step /= max;
	while ((int)(data->a->x - data->b->x) ||
	(int)(data->a->y - data->b->y))
	{
		if (data->z != data->z1 && !data->color_flag)
			data->color = color_fill(data, z);
		z += 1;
		plot(data, data->a);
		data->a->x += x_step;
		data->a->y += y_step;
		data->a->z += z_step;
	}
}

void		draw(t_fdf *data)
{
	int		x;
	int		y;
	double	x1;
	double	y1;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
			{
				data->a->x = x;
				data->a->y = y;
				draw_base(x + 1, y, data);
			}
			if (y < data->height - 1)
			{
				data->a->x = x;
				data->a->y = y;
				draw_base(x, y + 1, data);
			}
		}
	}
}
