/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:29:04 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/18 16:29:05 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		add_more_sh(t_fdf *d)
{
	char	*ang_x;
	char	*ang_y;
	char	*ang_z;

	ang_x = ft_itoa(d->ang_x * 57.2957795);
	ang_y = ft_itoa(d->ang_y * 57.2957795);
	ang_z = ft_itoa(d->ang_z * 57.2957795);
	mlx_string_put(d->mlx, d->win, 132, 352, 0x688b, ang_y);
	mlx_string_put(d->mlx, d->win, 132, 372, 0x688b, ang_x);
	mlx_string_put(d->mlx, d->win, 132, 392, 0x688b, ang_z);
	mlx_string_put(d->mlx, d->win, 22, 352, 0x688b, "y axis   :");
	mlx_string_put(d->mlx, d->win, 22, 372, 0x688b, "x axis   :");
	mlx_string_put(d->mlx, d->win, 22, 392, 0x688b, "z axis   :");
	free(ang_x);
	free(ang_y);
	free(ang_z);
}

static void		add_sh(t_fdf *d)
{
	mlx_string_put(d->mlx, d->win, 62, 22, 0x688b, "CONTROL");
	mlx_string_put(d->mlx, d->win, 22, 52, 0x688b,
				"MOVE     : WASD ");
	mlx_string_put(d->mlx, d->win, 22, 72, 0x688b,
				"ZOOM     : + / -");
	mlx_string_put(d->mlx, d->win, 22, 92, 0x688b,
				"ROTATE Y : 7 / 8");
	mlx_string_put(d->mlx, d->win, 22, 112, 0x688b,
				"ROTATE X : 4 / 5");
	mlx_string_put(d->mlx, d->win, 22, 132, 0x688b,
				"ROTATE Z : 1 / 2");
	mlx_string_put(d->mlx, d->win, 22, 152, 0x688b,
				"RELIEF   : 6 / 3");
	mlx_string_put(d->mlx, d->win, 22, 172, 0x688b,
				"RESET    : ENTER");
	mlx_string_put(d->mlx, d->win, 22, 192, 0x688b,
				"COLOR    : C");
	mlx_string_put(d->mlx, d->win, 22, 212, 0x688b,
				"ISO      : I");
	mlx_string_put(d->mlx, d->win, 22, 232, 0x688b,
				"EXIT     : ESC ");
	add_more_sh(d);
}

static void		add_more_menu(t_fdf *d)
{
	char	*ang_x;
	char	*ang_y;
	char	*ang_z;

	ang_x = ft_itoa(d->ang_x * 57.2957795);
	ang_y = ft_itoa(d->ang_y * 57.2957795);
	ang_z = ft_itoa(d->ang_z * 57.2957795);
	mlx_string_put(d->mlx, d->win, 130, 350, 0xf7f7f7, ang_y);
	mlx_string_put(d->mlx, d->win, 130, 370, 0xf7f7f7, ang_x);
	mlx_string_put(d->mlx, d->win, 130, 390, 0xf7f7f7, ang_z);
	mlx_string_put(d->mlx, d->win, 20, 350, 0xf7f7f7, "y axis   :");
	mlx_string_put(d->mlx, d->win, 20, 370, 0xf7f7f7, "x axis   :");
	mlx_string_put(d->mlx, d->win, 20, 390, 0xf7f7f7, "z axis   :");
	free(ang_x);
	free(ang_y);
	free(ang_z);
}

static void		add_menu(t_fdf *d)
{
	mlx_string_put(d->mlx, d->win, 60, 20, 0xf7f7f7, "CONTROL");
	mlx_string_put(d->mlx, d->win, 20, 50, 0xf7f7f7,
				"MOVE     : WASD ");
	mlx_string_put(d->mlx, d->win, 20, 70, 0xf7f7f7,
				"ZOOM     : + / -");
	mlx_string_put(d->mlx, d->win, 20, 90, 0xf7f7f7,
				"ROTATE Y : 7 / 8");
	mlx_string_put(d->mlx, d->win, 20, 110, 0xf7f7f7,
				"ROTATE X : 4 / 5");
	mlx_string_put(d->mlx, d->win, 20, 130, 0xf7f7f7,
				"ROTATE Z : 1 / 2");
	mlx_string_put(d->mlx, d->win, 20, 150, 0xf7f7f7,
				"RELIEF   : 6 / 3");
	mlx_string_put(d->mlx, d->win, 20, 170, 0xf7f7f7,
				"RESET    : ENTER");
	mlx_string_put(d->mlx, d->win, 20, 190, 0xf7f7f7,
				"COLOR    : C");
	mlx_string_put(d->mlx, d->win, 20, 210, 0xf7f7f7,
				"ISO      : I");
	mlx_string_put(d->mlx, d->win, 20, 230, 0xf7f7f7,
				"EXIT     : ESC ");
	add_more_menu(d);
}

void			menu(t_fdf *data)
{
	if (data->menu == OFF)
	{
		mlx_string_put(data->mlx, data->win, 62, 22, 0x688b, "CONTROL [tab]");
		mlx_string_put(data->mlx, data->win, 60, 20, 0xf7f7f7, "CONTROL [tab]");
	}
	else
	{
		add_sh(data);
		add_menu(data);
	}
}
