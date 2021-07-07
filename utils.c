#include "fractol.h"

void	error_exit(void)
{
	printf("The Julia fractal parameters should be numeric, the first is the "
		   "real part, the second is the imaginary part\n");
	exit(1);
}

int	check_args(int argc, char **argv)
{
	char	*mdbr;
	char	*jul;
	char	*ship;

	mdbr = "Mandelbrot";
	jul = "Julia";
	ship = "Burning Ship";
	if (argc > 1 && !ft_strncmp(argv[1], mdbr, ft_strlen(mdbr)))
		return (1);
	else if (argc > 1 && !ft_strncmp(argv[1], jul, ft_strlen(jul)))
		return (2);
	else if (argc > 1 && !ft_strncmp(argv[1], ship, ft_strlen(ship)))
		return (3);
	else
	{
		printf("\nPlease select a fractal. "
			   "The available options are:\n%s\n%s\n%s\n\n"
			   "For %s you can also specify constant parameter in the "
			   "following form: \"[real_part] [imaginary_part]\"\n\n", mdbr,
			   jul, ship, jul);
		exit(1);
	}
}

void	initialize_atod(t_atod *elt)
{
	elt->fact = 1.0;
	elt->p = 0;
	elt->res = 0.0;
	elt->num = 0;
}

double	ft_atod(char *s)
{
	t_atod	elt;

	initialize_atod(&elt);
	if (*s == '-')
	{
		s++;
		elt.fact = -1;
	}
	while (*s)
	{
		if (*s == '.')
		{
			elt.p++;
			s++;
			continue ;
		}
		if (elt.p)
			elt.fact /= 10.0;
		if (*s && ((elt.p > 1 && *s == '.') || (!ft_isdigit(*s) && *s != '.')))
			error_exit();
		elt.num = *s - '0';
		elt.res = elt.res * 10.0 + (double)elt.num;
		s++;
	}
	return (elt.res * elt.fact);
}

void	check_jul_params(char **argv, t_img *image)
{
	image->constant[0] = ft_atod(argv[2]);
	image->constant[1] = ft_atod(argv[3]);
}
