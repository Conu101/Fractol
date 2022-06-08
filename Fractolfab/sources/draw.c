/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:56:58 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/08 18:38:02 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

static void	draw_px(t_fractol *fractol, t_vec2 pos)
{
	const uint32_t	iter_num = fractol->fract->draw(fractol, pos);
	const int32_t	color = fade(iter_num, fractol->fract->iter_num);
	put_pixel(&fractol->mlx, pos.x, pos.y, color);
}

void		draw_win(t_fractol *fractol)
{
	t_vec2	tmp;
	tmp.y = 0;
	mlx_clear_window(fractol->mlx.mlx, fractol->mlx.window);
	while (tmp.y < fractol->mlx.win_size.y)
	{
		tmp.x = 0;
		while (tmp.x < fractol->mlx.win_size.x)
		{
			draw_px(fractol, tmp);
			tmp.x++;
		}
		tmp.y++;
	}
	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.window,
		fractol->mlx.image, 0, 0);
}
