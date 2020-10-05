/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:33:30 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/22 18:33:31 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	grad(int i, int mod)
{
	static int	grad1[12] = {0x0014f0, 0x2925E2, 0x5237D3, 0x7C48C5, 0xA55AB6,
						0xCE6DA8, 0xB27DAF, 0x958FB5, 0x79A2BC, 0x5CB4C2,
						0x40C6C9, 0x23D8CF};
	static int	grad2[12] = {0x050E59, 0x042D6F, 0x035B91, 0xAB9A55, 0x978D46,
						0x6E7327, 0x0E5704, 0x235D05, 0x386406, 0x436707,
						0x6D7709, 0x384109};
	static int	grad3[12] = {0x5E0000, 0x680E05, 0x721C09, 0x7B2B0E, 0x853912,
						0x8F4717, 0x9B511C, 0xA75A20, 0xB36425, 0xBE6E29,
						0xCA772E, 0xD68132};
	static int	grad4[12] = {0xF4FF00, 0xE4E817, 0xD5D12E, 0xC7B946, 0xB9A25D,
						0xAB8B74, 0x9C748B, 0x8E5DA2, 0x8046B9, 0x722ED1,
						0x6317E8, 0x5500FF};

	if (mod == BLUE_PINK)
		return (grad1[i]);
	if (mod == NATURAL)
		return (grad2[i]);
	if (mod == CHI)
		return (grad4[i]);
	return (grad3[i]);
}

int			find_min(int **z_matrix, int width, int height)
{
	int		min;
	int		i;
	int		j;

	i = 0;
	min = z_matrix[i][i];
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (z_matrix[i][j] < min)
				min = z_matrix[i][j];
			j++;
		}
		i++;
	}
	return (min);
}

int			find_max(int **z_matrix, int width, int height)
{
	int		max;
	int		i;
	int		j;

	i = 0;
	max = z_matrix[i][i];
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (z_matrix[i][j] > max)
				max = z_matrix[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

static int	find_z(double min, double step, double z, int mod)
{
	int			i;

	i = 0;
	while (i < 11)
	{
		if (z <= min + (step * i))
			return (grad(i, mod));
		i++;
	}
	return (grad(i, mod));
}

int			color_fill(t_fdf *data, double z)
{
	int		min;
	int		max;
	double	step;

	max = data->z_max;
	min = data->z_min;
	step = (ft_absf((double)max) + ft_absf((double)min)) / 12;
	return (find_z((double)min, step, z / data->up / data->zoom, data->color_mod));
}
