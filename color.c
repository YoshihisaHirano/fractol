#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	color_pix_mdbr(int n, int x, int y, t_img *img)
{
	int		color;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	b = (int)(127.5 + 127.5 * sin(PI * (xn - 0.45) / 0.5));
	g = (int)(127.5 + 127.5 * sin(PI * (xn - 0.38) / 0.5));
	r = (int)(127.5 + 127.5 * sin(PI * (xn - 0.21) / 0.5));
	color = create_trgb(0, r, g, b);
	if (n < img->max_iter && n > 0)
		my_pix_put(img, x, y, color);
	else
		my_pix_put(img, x, y, 0x00);
}

void	color_pix_jul(int n, int x, int y, t_img *img)
{
	int		color;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	b = (int)(127.5 + 127.5 * sin(PI * (xn - 0.35) / 0.5));
	g = (int)(127.5 + 127.5 * sin(PI * (xn - 0.18) / 0.5));
	r = (int)(127.5 + 127.5 * sin(PI * (xn - 0.11) / 0.5));
	color = create_trgb(0, r, g, b);
	if (n < img->max_iter && n > 0)
		my_pix_put(img, x, y, color);
	else
		my_pix_put(img, x, y, 0x00);
}

void	color_pix_ship(int n, int x, int y, t_img *img)
{
	int		color;
	int		r;
	int		g;
	int		b;
	double	xn;

	xn = (double)n / img->max_iter;
	g = (int)(127.5 + 127.5 * sin(PI * (xn - 0.45) / 0.5));
	b = (int)(127.5 + 127.5 * sin(PI * (xn - 0.18) / 0.5));
	r = (int)(127.5 + 127.5 * sin(PI * (xn - 0.21) / 0.5));
	color = create_trgb(0, r, g, b);
	if (n < img->max_iter && n > 0)
		my_pix_put(img, x, y, color);
	else
		my_pix_put(img, x, y, 0x00);
}
