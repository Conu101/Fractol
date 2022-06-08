/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:52:55 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/03 14:40:52 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H

# define ERR_USAGE			"\nUsage: ./fractol <fractal name> \n\n\
List of available fractals to display:\n\
* Julia\n\
* Mandelbrot\n\
* Sierpinski\n\n\
Once the window is open, the menu of commands for more options can be displayed\
and closed by pressing M.\n"

# define ERR_INIT_FRACTOL	"\nError in init_fractol\n"
# define ERR_INIT_WINDOW	"\nError in mlx_new_window\n"
# define ERR_INIT_IMAGE		"\nError in init_image\n"
# define ERR_THREADS		"\nError with threads\n"
# define ERR_NAME			"\nError with the fractal formula, name invalid\n"

#endif
