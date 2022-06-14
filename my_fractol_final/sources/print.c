/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:46:04 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 14:11:17 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl(NULL);
	ft_putendl("This program displays fractal patterns.");
	ft_putendl(NULL);
	ft_putendl("List of available fractals:");
	ft_putendl(" * Mandelbrot");
	ft_putendl(" * Julia");
	ft_putendl(" * Celtic Mandelbrot (write this name within quotes)");
	ft_putendl(" * Sierpinski");
}
