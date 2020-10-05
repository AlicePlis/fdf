/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:34:52 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:34:54 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# define BLUE_PINK 1
# define NATURAL 2
# define MARS 3
# define CHI 4
# define OFF 0
# define ON 1

typedef struct	s_dot
{
	double	x;
	double	y;
	double	z;
}				t_dot;

typedef	struct	s_mouse
{
	int		x0;
	int		y0;
	double	x;
	double	y;
	double	button1;
	double	button2;
}				t_mouse;

typedef struct	s_fdf
{
    t_dot   *c;
	t_dot	*a;
	t_dot	*b;
	t_mouse	m;
	int     z1;
	int     z;
	int		w_width;
	int		w_height;
	int		width;
	int		height;
	int		**z_matrix;
	int		**c_matrix;
	int		*z_buffer;
	double  zoom;
	int		color;
	int 	color_flag;
	double	ang_y;
	double	ang_x;
	double	ang_z;
	int		shift_x;
	int		shift_y;
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char 	*data_ptr;
	int		bpp;
	int		sl;
	int		end;
	double	up;
	int		iso;
	int		z_max;
	int		z_min;
	int		color_mod;
	int 	menu;
}				t_fdf;

int				valid_file(int fd);
void			read_file(char *file, t_fdf *data);
void			draw(t_fdf *data);
void			fdf_start(t_fdf *data);
int				opt_key(int key, t_fdf *data);
void			rotate(t_fdf *data);
int				color_fill(t_fdf *data, double z);
void 			menu(t_fdf *data);
void			start_param(t_fdf *data);
void			zoom_shift(t_fdf *data);
int				find_min(int **z_matrix, int width, int height);
int				find_max(int **z_matrix, int width, int height);
void			mouse_hook(t_fdf *data);
void            make_scope(t_dot *dot, t_fdf *data, int r);
void	        plot(t_fdf *data, t_dot	*dot);
void			re_draw(t_fdf *data);

void			res_buffer(t_fdf *data);
void			get_buffer(t_fdf *data);
int				check_buffer(t_fdf *data, t_dot *dot);
int				get_color(int colormax, int colormin, double max, double step);
void 			rotate_scope(t_fdf *data);
void			rotate_z(t_dot *dot, t_fdf *data, double x, double y);
void			rotate_x(t_dot *dot, t_fdf *data, double y);
void			rotate_y(t_dot *dot, t_fdf *data, double x);
#endif
