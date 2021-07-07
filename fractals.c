#include "fractol.h"

int	iterate_mdbr(double a, double b, t_img *img)
{
	int		n;
	double	new_a;
	double	new_b;
	double	ca;
	double	cb;

	n = 0;
	ca = a;
	cb = b;
	while (n < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		a = new_a + ca;
		b = new_b + cb;
		n++;
	}
	return (n);
}

int	iterate_jul(double a, double b, t_img *img)
{
	int		n;
	double	new_a;
	double	new_b;
	double	ca;
	double	cb;

	n = 0;
	ca = (img->constant)[0];
	cb = (img->constant)[1];
	while (n < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		a = new_a + ca;
		b = new_b + cb;
		n++;
	}
	return (n);
}

int	iterate_ship(double a, double b, t_img *img)
{
	int		n;
	double	new_a;
	double	new_b;
	double	ca;
	double	cb;

	n = 0;
	ca = a;
	cb = b;
	while (n < img->max_iter && (a * a + b * b < 4.0))
	{
		new_a = (a * a) - (b * b);
		new_b = 2.0 * a * b;
		if (new_b < 0)
			new_b *= (-1);
		a = new_a + ca;
		b = new_b + cb;
		n++;
	}
	return (n);
}
