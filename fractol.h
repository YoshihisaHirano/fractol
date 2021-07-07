#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define PI 3.14159265359

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			max_iter;
	long double	zoom;
	double		constant[2];
	double		start_x;
	double		start_y;
}	t_img;

typedef struct s_sess
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_img	*image;
	int		type;
	int		(*iter_f)(double, double, t_img*);
	void	(*col_f)(int, int, int, t_img*);
	int		counter;
}	t_sess;

typedef struct s_point
{
	double	x;
	double	y;
	double	dx;
	double	dy;
}	t_point;

typedef struct s_atod
{
	double	res;
	double	fact;
	int		p;
	int		num;
}	t_atod;

int		create_trgb(int t, int r, int g, int b);
void	my_pix_put(t_img *img, int x, int y, int color);
void	color_pix_mdbr(int n, int x, int y, t_img *img);
void	color_pix_jul(int n, int x, int y, t_img *img);
void	color_pix_ship(int n, int x, int y, t_img *img);
int		iterate_mdbr(double a, double b, t_img *img);
int		iterate_jul(double a, double b, t_img *img);
int		iterate_ship(double a, double b, t_img *img);
void	draw_fractal(t_sess *win, double ymin, double xmin, double zoom);
int		check_args(int argc, char **argv);
int		key_hook(int key_code, t_sess *curr);
int		zoom(int button, int x, int y, t_sess *curr);
int		julia_const(int x, int y, t_sess *curr);
void	check_jul_params(char **argv, t_img *image);
int		color_shift(int key_code, t_sess *curr);

#endif
