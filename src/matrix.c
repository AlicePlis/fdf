/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:17:38 by student           #+#    #+#             */
/*   Updated: 2020/09/07 13:17:47 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	res_buffer(t_fdf *data)
{
	int		i;

	i = -1;
	while (++i < data->w_height * data->w_width)
		data->z_buffer[i] = -1000000;
}

void	get_buffer(t_fdf *data)
{
	data->z_buffer = (int*)malloc(sizeof(int) * data->w_height * data->w_width);
	res_buffer(data);
}

int		check_buffer(t_fdf *data, t_dot *dot)
{
	if (data->z_buffer[(int)dot->x + (int)dot->y * data->w_width] > dot->z)
		return (0);
	else
	{
		data->z_buffer[(int)dot->x + (int)dot->y * data->w_width] = dot->z;
		return (1);
	}
}