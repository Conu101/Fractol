/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:27:34 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 21:11:35 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

void	print_usage(void)
{
	ft_putendl("\nUsage: ./fractol <name>");
	ft_putendl(NULL);
	ft_putendl("\nThis program displays fractal patterns.");
	ft_putendl(NULL);
	ft_putendl("\nList of available fractals:");
	ft_putendl(" * Mandelbrot");
	ft_putendl(" * Julia");
	ft_putendl(" * Celtic Mandelbrot (write this name within quotes)");
	ft_putendl(" * Sierpinski\n");
}

static t_formula	set_formula(char *name, int (*formula)(t_fractol *fractol))
{
	static t_formula	formulas;

	formulas.name = name;
	formulas.formula = formula;
	return (formulas);
}

int	(*get_formula(char *name)) (t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[4];

	formulas[0] = set_formula("Mandelbrot", &iterate_mandelbrot);
	formulas[1] = set_formula("Julia", &iterate_julia);
	formulas[2] = set_formula("Celtic Mandelbrot", &iterate_celtic_mandelbrot);
	formulas[3] = set_formula("Sierpinski", &iterate_sierpinski);
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
