/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:37:32 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 22:25:27 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error.h"
#include <mlx.h>

/*
** Check for leaks : Instruments and system("leaks fractol"); before exit/draw
*/
static int	closewin(void *param)
{
	(void)param;
	exit(0);
}

static t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	if (!fractol)
		terminate(ERR_FRACTOL_INIT);
	fractol->mlx = mlx;
	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name);
	if (!fractol->window)
		terminate(ERR_WINDOW_INIT);
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	fractol->set_julia = true;
	fractol->formula = get_formula(name);
	if (!fractol->formula)
		terminate(ERR_FRACTAL_NAME);
	fractol->menu_on = false;
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, closewin, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	if (ft_strequ(name, "Julia"))
		mlx_hook(fractol->window, 6, 0, julia_setting, fractol);
	return (fractol);
}

/*
** mlx_init() starts the graphical interface. init_fractol() launches the
** particular fractal program.
*/
static void	start(char *fractal_name)
{
	t_fractol	*fractol;
	void		*mlx;

	mlx = mlx_init();
	fractol = init_fractol(fractal_name, mlx);
	draw_fractal(fractol);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!get_formula(argv[1]))
			terminate(ERR_FRACTAL_NAME);
		else
			start(argv[1]);
	}
	print_usage();
	return (0);
}
