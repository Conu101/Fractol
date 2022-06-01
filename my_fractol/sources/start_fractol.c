/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:04:46 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/01 20:43:03 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractol	*init_fractol(char *fractal_name, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	if (!(fractol))
		terminate(ERR_INIT_FRACTOL);
	fractol->name = fractal_name;
	fractol->mlx = mlx;
	fractol->win = mlx_new_window(mlx, WIDTH, HEIGHT, fractol->name);
	if (!(fractol->win))
		terminate(ERR_WINDOW_INIT);
	fractol->img = init_image(mlx);
	set_defaults(fractol);
	fractol->julia_variation = 0;
	fractol->show_menu = 0;
	mlx_hook(fractol->win, 2, 0, key_press, fractol);
	//mlx_hook(fractol->win, 4, 0, zoom, fractol);
	//if (ft_strequ(fractol->name, "Julia"))
	//	mlx_hook(fractol->win, 6, 0, julia_variation, fractol);
	return (fractol);
}

void	start_fractol(char *fractal_name)
{
	t_fractol	*fractol;
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	fractol = init_fractol(fractal_name, mlx);
	//draw_fractal(fractol);
	mlx_loop(mlx);
}
