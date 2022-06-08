/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:01:26 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/03 15:04:37 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*init_image(void *mlx)
{
	t_image		*image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		terminate(ERR_INIT_IMAGE);
	if (!(image->image = mlx_new_image(mlx, WIDTH, HEIGHT)))
		terminate(ERR_INIT_IMAGE);
		image->data_addr = mlx_get_data_addr(image->image,\
		&(image->bits_per_pixel), &(image->size_line), &(image->endian));
	return (image);
}

static int			(*get_formula(char *name)) (t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[] = {
		{ "Mandelbrot", &iterate_mandelbrot },
		{ "Julia", &iterate_julia },
	};

	i = 0;
	formula = NULL;
	while (i < (sizeof(formulas) / sizeof(t_formula)))
	{
		if (ft_strequ(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}

void		set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
}

static t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		terminate(ERR_INIT_FRACTOL);
	fractol->mlx = mlx;
	if (!(fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name)))
		terminate(ERR_INIT_WINDOW);
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	fractol->is_julia_fixed = true;
	if (!(fractol->formula = get_formula(name)))
		terminate(ERR_NAME);
	fractol->is_help = false;
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close_with_x, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	if (ft_strequ(name, "Julia"))
		mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
	return (fractol);
}

void	start_fractol(char *fractal_name)
{
	t_fractol	*fractol;
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	fractol = init_fractol(fractal_name, mlx);
	draw_fractal(fractol);
	mlx_loop(mlx);
}
