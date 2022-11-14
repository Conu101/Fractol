/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:00:17 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/14 22:01:32 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error.h"
#include <pthread.h>
#include <mlx.h>

/*
** In OpenGL and Portable Network Graphics (PNG), the RGBA byte order is used,
** where the colors are stored in memory such that R is at the lowest address, 
** G after it, B after that, and A last.
*/

static void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->size_line);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

static void	draw_fractal_part(t_fractol *fractol)
{
	int			y;
	int			x;
	t_color		color;

	y = fractol->start_line;
	while (y < fractol->finish_line)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_fractol *fractol)
{
	pthread_t	threads[THREADS];
	t_fractol	fractols[THREADS];
	int			i;

	fractol->factor = init_complex(\
		(fractol->max.re - fractol->min.re) / (WIDTH - 1), \
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < THREADS)
	{
		fractols[i] = *fractol;
		fractols[i].start_line = i * (HEIGHT / THREADS);
		fractols[i].finish_line = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL, \
			(void *(*)(void *))draw_fractal_part, (void *)&fractols[i]))
			terminate(ERR_THREADS);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			terminate(ERR_THREADS);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, WIDTH - 100, HEIGHT - 40, \
					0xB2F6F6, "M - Menu");
}

/*
** Norm compliance extra function
*/
static void	draw_menu_end(t_fractol *fractol)
{
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 150), 0xF2F2F2, \
		"Zoom           - Scroll");
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 180), 0xF2F2F2, \
		"Iterations     - +/-");
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 210), 0xF2F2F2, \
		"Julia Constant - Mouse");
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 240), 0xF2F2F2, \
		"Mouse Lock     - Space");
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 270), 0xF2F2F2, \
		"Close Menu     - M");
}

void	draw_menu(t_fractol *fractol)
{
	ft_bzero(fractol->image->data_addr,
		WIDTH * HEIGHT * (fractol->image->bits_per_pixel / 8));
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 40), \
	HEIGHT / 3, 0xF2F2F2, \
		"Controls");
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 60), 0xF2F2F2, \
		"Reset          - R");
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 90), 0xF2F2F2, \
		"Color Shift    - C");
	mlx_string_put(fractol->mlx, fractol->window, (WIDTH / 2 - 120), \
	(HEIGHT / 3 + 120), 0xF2F2F2, \
		"Move           - Arrows");
	draw_menu_end(fractol);
}
