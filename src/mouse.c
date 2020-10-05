/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:16:57 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/17 17:16:58 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		mouse_press(int button, int x, int y, t_fdf *d)
{
	if (button == 1)
	{
		if (x >= 0 && x <= d->w_width && y >= 0 && y <= d->w_height)
		{
			d->m.button1 = ON;
			d->m.x0 = x;
			d->m.y0 = y;
		}
	}
	if (button == 2)
	{
		d->m.button2 = ON;
		d->m.x0 = x;
		d->m.y0 = y;
	}
	if ((button == 4 || button == 5) && d->iso != 2)
	{
		d->zoom += (button == 5) ? 1 : -1;
		d->zoom = (d->zoom < 0) ? 1 : d->zoom;
		re_draw(d);
	}
	return (0);
}

static int		mouse_release(int button, int x, int y, void *data)
{
	t_fdf	*d;

	(void)x;
	(void)y;
	d = (t_fdf*)data;
	if (button == 1)
		d->m.button1 = OFF;
	if (button == 2)
		d->m.button2 = OFF;
	return (0);

}

static int		mouse_move(int x, int y, void *data)
{
	t_fdf	*d;

	d = (t_fdf*)data;
	if (d->m.button1 == ON)
	{
		d->m.x = x - d->m.x0;
		d->m.y = y - d->m.y0;
		d->m.x0 = x;
		d->m.y0 = y;
		if (d->m.button2 == ON)
		{
			d->shift_x += d->m.x;
			d->shift_y += d->m.y;
		}
		else
		{
			d->ang_y += d->m.x / 400;
			if (d->ang_y >= 6.28319 || d->ang_y <= -6.28319)
				d->ang_y = 0;
			d->ang_x -= d->m.y / 400;
			if (d->ang_x >= 6.28319 || d->ang_x <= -6.28319)
				d->ang_x = 0;
		}
		re_draw(d);
	}
	return(0);
}

static int		f_close(void *data)
{
	(void)data;
	exit(0);
}

void	mouse_hook(t_fdf *data)
{
	mlx_hook(data->win, 4, 0, mouse_press, data);
	mlx_hook(data->win, 5, 0, mouse_release, (void*)data);
	mlx_hook(data->win, 6, 0, mouse_move, (void*)data);
	mlx_hook(data->win, 17, 0, f_close, (void*)data);
}