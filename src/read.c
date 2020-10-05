/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:09:17 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/06 17:09:18 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_win_size(t_fdf *data)
{
    int     i;

	if (data->width <= 50)
		data->w_width = 800;
	else
		data->w_width = 1000;
	if (data->height <= 50)
		data->w_height = 500;
	else
		data->w_height = 800;
}

static void	get_size(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	data->height = 0;
	data->width = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		data->height++;
		if (!data->width)
			data->width = ft_wcount(line, ' ');
		free(line);
	}
	close(fd);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height));
	data->c_matrix = (int**)malloc(sizeof(int*) * (data->height));
	i = -1;
	while (++i < data->height)
	{
		data->z_matrix[i] = (int*)malloc(sizeof(int) * (data->width));
		data->c_matrix[i] = (int*)malloc(sizeof(int) * (data->width));
	}
}

static int	get_c(char *str, t_fdf *data)
{
	char	*tmp;
	int		color;

	color = 0x000000;
	tmp = str;
	while (*tmp && *tmp != ',')
		tmp++;
	if (*tmp == ',')
	{
		tmp++;
		color = ft_atoi_base(str, 16);
		data->color_flag = 1;
	}
	return (color);
}

void		read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**nums;
	int		i;
	int		j;

	data->color_flag = 0;
	get_size(file, data);
	get_win_size(data);
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nums = ft_strsplit(line, ' ');
		j = -1;
		while (nums[++j])
		{
			data->z_matrix[i][j] = ft_atoi(nums[j]);
			data->c_matrix[i][j] = get_c(nums[j], data);
			free(nums[j]);
		}
		free(nums);
		free(line);
		i++;
	}
	close(fd);
}
