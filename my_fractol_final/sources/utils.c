/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:27:34 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 19:26:17 by ctrouve          ###   ########.fr       */
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
