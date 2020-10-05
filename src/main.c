/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:34:16 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/12 18:21:40 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_fdf	*d;
	int		fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY, 0)) < 0)
			ft_exit("Map error!");
		/*if (!(valid_file(fd)))
			ft_exit("Not valid map");*/
		d = ft_memalloc(sizeof(t_fdf));
		read_file(argv[1], d);
		d->mlx = mlx_init();
		d->win = mlx_new_window(d->mlx, d->w_width, d->w_height, "FDF");
		d->img_ptr = mlx_new_image(d->mlx, d->w_width, d->w_height);
		d->data_ptr = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->sl, &d->end);
		ft_bzero(d->data_ptr, d->w_width * d->w_height * 4);
		d->a = ft_memalloc(sizeof(t_dot));
		d->b = ft_memalloc(sizeof(t_dot));
		fdf_start(d);
		mlx_key_hook(d->win, opt_key, d);
		mouse_hook(d);
		mlx_loop(d->mlx);
		exit(0);
	}
	ft_exit("usage: ./fdf map_filename");
}
