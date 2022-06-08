# include "libft.h"
# include "fractol.h"

static t_fract	g_fractals[] = {
	{
		.name = "mandelbrot",
		.size = {.x = 2.7, .y = 2.4},
		.pos = {.x = -2.1, .y = -1.2},
		.draw = &draw_mandelbrot,
		.iter_num = 50,
		.movable = false,
	},
	{
		.name = "mandelrot",
		.size = {.x = 3.0, .y = 2.7},
		.pos = {.x = -1.5, .y = -2.1},
		.draw = &draw_mandelrot,
		.iter_num = 50,
		.movable = false,
	},
	{
		.name = "julia",
		.size = {.x = 4.0, .y = 4.0},
		.pos = {.x = -2.0, .y = -2.0},
		.draw = &draw_julia,
		.iter_num = 50,
		.movable = true,
		.mov_lock = false,
	},
	{
		.name = "burning-ship",
		.size = {.x = 3.0, .y = 3.0},
		.pos = {.x = -2.0, .y = -2.0},
		.draw = &draw_ship,
		.iter_num = 50,
		.movable = false,
	},
	{
		.name = "sierpinski",
		.size = {.x = 9.0, .y = 9.0},
		.pos = {.x = 0.0, .y = 0.0},
		.draw = &draw_sierpinski,
		.iter_num = 5,
		.movable = false,
	},
	{.name = NULL}
};
static int8_t	get_fractal(t_fract fractals[], t_fractol *fractol,
	const char fract[])
{
	size_t	i;
	i = 0;
	while (fractals[i].name != NULL)
	{
		if (ft_strequ(fractals[i].name, fract))
		{
			fractol->fract = &fractals[i];
			return (1);
		}
		i++;
	}
	return (0);
}
static void		print_usage(t_fract fractals[])
{
	size_t		i;
	i = 0;
	ft_putstr("usage: fractol [");
	while (fractals[i].name != NULL)
	{
		if (i != 0)
			ft_putstr(" ");
		ft_putstr(fractals[i].name);
		i++;
	}
	ft_putendl("]");
}

int	main(const int ac, const char *av[])
{
	t_fractol	fractol;
	t_fract		*fractals;
	fractals = g_fractals;
	ft_bzero(&fractol, sizeof(t_fractol));
	if (ac == 2 && get_fractal(fractals, &fractol, av[1]))
	{
		init_fractol(&fractol);
		if (display_mlx_win(&fractol) == 0)
			return (0);
	}
	else
		print_usage(fractals);
	return (1);
}
