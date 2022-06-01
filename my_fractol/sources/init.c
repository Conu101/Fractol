/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:01:26 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/01 20:49:47 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*init_image(void *mlx)
{
	t_image		*image;

	image = (t_image *)ft_memalloc(sizeof(t_image));
	if (!(image))
		terminate(ERR_INIT_IMAGE);
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!(image->image))
		terminate(ERR_INIT_IMAGE);
	image->data_addr = mlx_get_data_addr(
		image->image,
		&(image->bits_per_pixel),
		&(image->size_line),
		&(image->endian));
	return (image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
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
