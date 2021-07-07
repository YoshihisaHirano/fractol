#include "fractol.h"

void	draw_fractal(t_sess *win, double ymin, double xmin, double zoom)
{
	int		y_idx;
	int		x_idx;
	t_point	point;
	int		n;

	point.dx = zoom / win->width;
	point.dy = zoom / win->height;
	point.y = ymin;
	y_idx = 0;
	while (y_idx < win->height)
	{
		x_idx = 0;
		point.x = xmin;
		while (x_idx < win->width)
		{
			n = win->iter_f(point.x, point.y, win->image);
			win->col_f(n, x_idx, y_idx, win->image);
			point.x += point.dx;
			x_idx++;
		}
		point.y += point.dy;
		y_idx++;
	}
}
