/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:15:50 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 18:43:10 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function that sets the values for A, B, G, R. The use of color_shift in the
** channel number allows to switch colors by switching the channel values
*/
t_color	get_color(int iteration, t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)iteration / fractol->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1] =
		(int8_t)10 * (1 - t) * pow(t, 3) * 255;
	color.channel[(1 + fractol->color_shift) % 3 + 1] =
		(int8_t)15 * pow((1 - t), 2) * pow(t, 2) * 255;
	color.channel[(2 + fractol->color_shift) % 3 + 1] =
		(int8_t)5 * pow((1 - t), 3) * t * 255;
	return (color);
}
