/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:29:02 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 20:25:11 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes_mac.h"

static void	menu(t_fractol *fractol)
{
	fractol->menu_on = !fractol->menu_on;
	if (fractol->menu_on)
		draw_menu(fractol);
	else
		draw_fractal(fractol);
}

static void	move(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex(ft_abs(fractol->max.re - fractol->min.re), \
	ft_abs(fractol->max.im - fractol->min.im));
	if (key == ARROW_LEFT)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	draw_fractal(fractol);
}

static void	change_max_iteration(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration += 1;
		else if (fractol->max_iteration < 10000000)
			fractol->max_iteration = (int)(fractol->max_iteration * 1.1);
	}
	if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
	{
		if (fractol->max_iteration > 50)
			fractol->max_iteration = (int)(fractol->max_iteration * 0.9);
		else if (fractol->max_iteration > 1)
			fractol->max_iteration -= 1;
	}
	draw_fractal(fractol);
}

static void	change_color_shift(t_fractol *fractol)
{
	fractol->color_shift = (fractol->color_shift + 1) % 3;
	draw_fractal(fractol);
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == MAIN_PAD_M)
		menu(fractol);
	else if (!fractol->menu_on)
	{
		if (key == MAIN_PAD_R)
		{
			set_defaults(fractol);
			draw_fractal(fractol);
		}
		else if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS \
				|| key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
			change_max_iteration(key, fractol);
		else if (key == ARROW_LEFT || key == ARROW_RIGHT \
				|| key == ARROW_UP || key == ARROW_DOWN)
			move(key, fractol);
		else if (key == MAIN_PAD_C)
			change_color_shift(fractol);
		else if (key == MAIN_PAD_SPACE)
			fractol->set_julia = !fractol->set_julia;
	}
	return (0);
}
