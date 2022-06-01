/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:29:02 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/01 20:30:00 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/*
** esc key press event
** leaks can be tested with a line "system("leaks fractol");" before exit(1).
*/

int	key_press(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		system("leaks fractol");
		exit(1);
	}
	return (0);
}
