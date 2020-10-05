/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:57:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/11 15:57:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_key(int key, t_fdf *data)
{
	if (key == 12)
		data->color_flag = (data->color_flag == 0) ? 1 : 0;
	else
	{
		if (data->color_mod == BLUE_PINK)
			data->color_mod = NATURAL;
		else if (data->color_mod == NATURAL)
			data->color_mod = MARS;
		else if (data->color_mod == MARS)
			data->color_mod = CHI;
		else if (data->color_mod == CHI)
			data->color_mod = BLUE_PINK;
	}
	re_draw(data);
}

static void	move_key(int key, t_fdf *data)
{
	if (key == 34)
	{
		if (data->iso == 0)
			data->iso = 1;
		else if (data->iso == 1)
			data->iso = 2;
		else if (data->iso == 2)
			data->iso = 3;
		else if (data->iso == 3)
			data->iso = 0;
		start_param(data);
	}
	if (key == 13)
		data->shift_y -= 10;
	if (key == 1)
		data->shift_y += 10;
	if (key == 0)
		data->shift_x -= 10;
	if (key == 2)
		data->shift_x += 10;
	re_draw(data);
}

static void	rotate_key(int key, t_fdf *data)
{
	if (key == 89 || key == 91)
	{
		data->ang_y += (key == 91) ? 0.02 : -0.02;
		if (data->ang_y >= 6.28319 || data->ang_y <= -6.28319)
			data->ang_y = 0;
	}
	if (key == 86 || key == 87)
	{
		data->ang_x += (key == 87) ? 0.02 : -0.02;
		if (data->ang_x >= 6.28319 || data->ang_x <= -6.28319)
			data->ang_x = 0;
	}
	if (key == 83 || key == 84)
	{
		data->ang_z += (key == 84) ? 0.02 : -0.02;
		if (data->ang_z >= 6.28319 || data->ang_z <= -6.28319)
			data->ang_z = 0;
	}
	re_draw(data);
}

static void	param_key(int key, t_fdf *data)
{
	if (key == 88)
		data->up += 0.1;
	if (key == 85)
		data->up -= 0.1;
	if (key == 69)
		data->zoom *= 1.1;
	if (key == 78)
		data->zoom *= 0.9;
	if (key == 36)
		start_param(data);
	if (key == 53)
		exit(0);
	if (key == 48)
		data->menu = (data->menu == OFF) ? ON : OFF;
	re_draw(data);
}


int			opt_key(int key, t_fdf *d)
{
	if (key == 8 || key == 12)
		color_key(key, d);
	if (key == 13 || key == 0 || key == 1 || key == 2 || key == 34)
		move_key(key, d);
	if (key == 83 || key == 84 || key == 86 || key == 87 || key == 89 ||
		key == 91)
		rotate_key(key, d);
	if (key == 35 || key == 36 || key == 88 || key == 85 || key == 69 ||
		key == 78 || key == 53 || key == 48)
		param_key(key, d);
	return (0);
}