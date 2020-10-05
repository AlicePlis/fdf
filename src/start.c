/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:05:19 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/28 11:05:20 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		re_draw(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_bzero(data->data_ptr, data->w_width * data->w_height * 4);
	res_buffer(data);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_ptr, 0, 0);
	menu(data);
}

void		start_param(t_fdf *d)
{
	if ((d->width >= 100 && d->width <= 200) ||
		(d->height >= 100 && d->height <= 200))
		d->zoom = 3;
	else if (d->width > 200 || d->height > 200)
		d->zoom = 1;
	else
		d->zoom = 20;
	d->shift_x = d->w_width / 2 - d->width * d->zoom / 2;
	d->shift_y = d->w_height / 2 - d->height * d->zoom / 2;
	d->ang_y = 0;
	d->ang_x = 0;
	d->ang_z = 0;
	d->up = 1;
	d->z_min = find_min(d->z_matrix, d->width, d->height) * d->up;
	d->z_max = find_max(d->z_matrix, d->width, d->height) * d->up;
	d->color_mod = BLUE_PINK;
	d->color = 0xffffff;
	d->menu = OFF;
}

void		fdf_start(t_fdf *d)
{
	d->iso = 0;
	start_param(d);
	get_buffer(d);
	draw(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img_ptr, 0, 0);
	menu(d);
}
