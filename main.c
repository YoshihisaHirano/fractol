#include "fractol.h"

void	initialize_window(t_sess *win, int height, int width)
{
	win->mlx_ptr = mlx_init();
	win->height = height;
	win->width = width;
	win->counter = 0;
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			win->width, win->height, "Fractol");
}

void	initialize_img(t_img *image, t_sess *win)
{
	image->img = mlx_new_image(win->mlx_ptr, win->width, win->height);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp),
			&(image->line_len), &(image->endian));
	image->max_iter = 70;
	image->zoom = 4;
	image->start_x = -2;
	image->start_y = -2;
	image->constant[0] = -0.7269;
	image->constant[1] = 0.1889;
}

void	assign_funcs(t_sess *win)
{
	if (win->type == 1)
	{
		win->iter_f = &iterate_mdbr;
		win->col_f = &color_pix_mdbr;
	}
	else if (win->type == 2)
	{
		win->iter_f = &iterate_jul;
		win->col_f = &color_pix_jul;
	}
	else if (win->type == 3)
	{
		win->iter_f = &iterate_ship;
		win->col_f = &color_pix_ship;
	}
}

int	main(int argc, char **argv)
{
	t_sess	curr;
	t_img	image;

	curr.type = check_args(argc, argv);
	initialize_window(&curr, 900, 900);
	initialize_img(&image, &curr);
	curr.image = &image;
	assign_funcs(&curr);
	if (curr.type == 2 && argc == 4)
		check_jul_params(argv, &image);
	if (curr.type == 2 || curr.type == 3)
		image.max_iter = 90;
	mlx_key_hook(curr.win_ptr, &key_hook, &curr);
	draw_fractal(&curr, image.start_y, image.start_x, image.zoom);
	mlx_put_image_to_window(curr.mlx_ptr, curr.win_ptr, image.img, 0, 0);
	mlx_mouse_hook(curr.win_ptr, &zoom, &curr);
	mlx_hook(curr.win_ptr, 6, (1L << 6), &julia_const, &curr);
	mlx_hook(curr.win_ptr, 2, (1L << 0), &color_shift, &curr);
	mlx_loop(curr.mlx_ptr);
	return (0);
}
