/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:46:04 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/08 15:18:41 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error.h"
#include <stdio.h> // to edit out at the end


/*
** Checks that the argument is in the list of available fractals of this program
*/
static int	check_fractal(char *argv)
{
	char	*list[3];
	int		valid;
	int		i;

	list[0] = "Julia";
	list[1] = "Mandelbrot";
	list[2] = "Sierpinski";
	valid = 0;
	i = 0;
	while (i <= 2)
	{
		if (ft_strequ(argv, list[i]) == 1)
			valid++;
		i++;
	}
	return (valid);
}

/*
** The main checks that an available fractal name is provided as argument and
** starts running the graphical display, otherwise displays usage.
*/
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_fractal(argv[1]))
			start_fractol(argv[1]);
		else
			terminate(ERR_USAGE);
	}
	else
		terminate(ERR_USAGE);
	return (0);
}

int		(*get_formula(char *name)) (t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[] = {
		{ "Mandelbrot", &iterate_mandelbrot },
		{ "Julia", &iterate_julia },
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
