#include "fractol.h"

int	key_hook(int key_code, t_sess *curr)
{
	t_img	*img;

	img = curr->image;
	if (key_code == 53)
		exit(1);
	if (key_code == 123)
		img->start_x -= (0.15 * img->zoom);
	if (key_code == 124)
		img->start_x += (0.15 * img->zoom);
	if (key_code == 125)
		img->start_y += (0.15 * img->zoom);
	if (key_code == 126)
		img->start_y -= (0.15 * img->zoom);
	draw_fractal(curr, img->start_y, img->start_x, img->zoom);
	mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, img->img, 0, 0);
	return (0);
}

int	zoom(int button, int x, int y, t_sess *curr)
{
	t_img	*image;
	double	new_x;
	double	new_y;

	image = curr->image;
	if (button == 5)
	{
		new_x = (image->zoom * ((double)x / curr->width)) + image->start_x;
		new_y = (image->zoom * ((double)y / curr->height)) + image->start_y;
		image->start_x = new_x - (image->zoom / 2) * 0.55;
		image->start_y = new_y - (image->zoom / 2) * 0.55;
		image->zoom *= 0.65;
		image->max_iter = (int)(image->max_iter * 1.19);
	}
	if (button == 4)
	{
		image->start_x -= (image->zoom / 2);
		image->start_y -= (image->zoom / 2);
		image->zoom /= 0.65;
		image->max_iter = (int)(image->max_iter / 1.19);
	}
	draw_fractal(curr, image->start_y, image->start_x, image->zoom);
	mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, image->img, 0, 0);
	return (0);
}

int	julia_const(int x, int y, t_sess *curr)
{
	t_img	*image;
	double	new_x;
	double	new_y;

	if (curr->type == 2)
	{
		image = curr->image;
		new_x = (image->zoom * ((double)x / curr->width)) + image->start_x;
		new_y = (image->zoom * ((double)y / curr->height)) + image->start_y;
		(image->constant)[0] = new_x;
		(image->constant)[1] = new_y;
		draw_fractal(curr, image->start_y, image->start_x, image->zoom);
		mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, image->img, 0, 0);
	}
	return (0);
}

int	color_shift(int key_code, t_sess *curr)
{
	void	(*col_f[3])(int, int, int, t_img*);
	t_img	*img;

	img = curr->image;
	col_f[0] = color_pix_mdbr;
	col_f[1] = color_pix_jul;
	col_f[2] = color_pix_ship;
	if (key_code == 48)
	{
		curr->col_f = col_f[curr->type - 1];
		draw_fractal(curr, img->start_y, img->start_x, img->zoom);
		mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, img->img, 0, 0);
	}
	if (key_code == 258)
	{
		curr->col_f = col_f[curr->counter % 3];
		curr->counter++;
		draw_fractal(curr, img->start_y, img->start_x, img->zoom);
		mlx_put_image_to_window(curr->mlx_ptr, curr->win_ptr, img->img, 0, 0);
	}
	return (0);
}
