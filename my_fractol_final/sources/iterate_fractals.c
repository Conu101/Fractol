/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:27:10 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 18:19:44 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		(*get_formula(char *name)) (t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[] = {
		{ "Mandelbrot", &iterate_mandelbrot },
		{ "Julia", &iterate_julia },
		{ "Celtic Mandelbrot", &iterate_celtic_mandelbrot },
		{ "Sierpinski", &iterate_sierpinski },
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

int		iterate_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
			2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}

int		iterate_mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
			2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}

int		iterate_celtic_mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractol->c.re,
			2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}

int		iterate_sierpinski(t_fractol *fractol)
{
	int			iteration;
	t_position	base_point;

	base_point = (t_position){
		.x = fractol->c.re,
		.y = fractol->c.im,
	};
	iteration = 0;
	while (iteration < fractol->max_iteration)
	{
		if ((int)base_point.x % 3 == 1 && (int)base_point.y % 3 == 1)
			return (iteration);
		base_point.x *= 3;
		base_point.y *= 3;
		iteration++;
	}
	return (iteration);
}
