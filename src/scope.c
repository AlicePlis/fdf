#include "fdf.h"

void    make_scope(t_dot *dot, t_fdf *data, int r)
{
	double q;
	double p;

    p = -360 * dot->x / (data->width - 1);
    q = 180 * dot->y / (data->height - 1);
    dot->x = (data->width) + data->shift_x +
             (50 * data->zoom + r) * sin(q * 3.14 / 180) * cos(p * 3.14 / 180);
    dot->y = (data->height) + data->shift_y +
             (50 * data->zoom + r) * sin(q * 3.14 / 180) * sin(p * 3.14 / 180);
    dot->z = (50 * data->zoom + r) * cos(q * 3.14 / 180);
}

void 	rotate_scope(t_fdf *data)
{
	int 	x;
	int 	y;

	x = ((data->width * data->zoom)) / 2 + data->shift_x;
	y = ((data->height * data->zoom)) / 2 + data->shift_y;
	make_scope(data->a, data, data->a->z);
	make_scope(data->b, data, data->b->z);
	rotate_x(data->a, data, y);
	rotate_y(data->a, data, x);
	rotate_x(data->b, data, y);
	rotate_y(data->b, data, x);
}
