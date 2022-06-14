/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:01:26 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/09 19:38:55 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_message.h"

t_image		*init_image(void *mlx)
{
	t_image		*image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		terminate(ERR_IMAGE_INIT);
	if (!(image->image = mlx_new_image(mlx, WIDTH, HEIGHT)))
		terminate(ERR_IMAGE_INIT);
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
	fractol->max_iteration = 100;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
}
