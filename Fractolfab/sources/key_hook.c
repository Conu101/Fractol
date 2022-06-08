# include "mlx_keycode.h"
# include "fractol.h"

/*
** Convert a position in a win (ex: 44px out of 1980)
** Into a position in the fractal plane
*/
static double	scale(int32_t win_pos, int32_t win_size,
	double pos, double size)
{
	return (((double)win_pos / (double)win_size) * size + pos);
}
int				key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ESC_KEY)
		fractol_exit(fractol);
	if (keycode == UP_KEY)
		fractol->fract->pos.y -= (fractol->fract->size.y / 10);
	if (keycode == DOWN_KEY)
		fractol->fract->pos.y += (fractol->fract->size.y / 10);
	if (keycode == RIGHT_KEY)
		fractol->fract->pos.x += (fractol->fract->size.x / 10);
	if (keycode == LEFT_KEY)
		fractol->fract->pos.x -= (fractol->fract->size.x / 10);
	if (keycode == PUP_KEY)
		fractol->fract->iter_num++;
	if (keycode == PDOWN_KEY)
		fractol->fract->iter_num -= (fractol->fract->iter_num >= 1);
	draw_win(fractol);
	return (0);
}
int				mouse_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->fract->movable && !fractol->fract->mov_lock)
	{
		fractol->mouse_pos.x = scale(x, fractol->mlx.win_size.x,
			fractol->fract->pos.x, fractol->fract->size.x);
		fractol->mouse_pos.y = scale(y, fractol->mlx.win_size.y,
			fractol->fract->pos.y, fractol->fract->size.y);
		draw_win(fractol);
	}
	return (0);
}
int				scroll_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == SCROLLDOWN_KEY)
	{
		zoom_out(fractol, (t_vec2){x, y});
	}
	else if (button == SCROLLUP_KEY)
	{
		zoom_in(fractol, (t_vec2){x, y});
	}
	else
	{
		if (!fractol->fract->movable)
		{
			fractol->fract->pos.x = scale(x, fractol->mlx.win_size.x,
				fractol->fract->pos.x, fractol->fract->size.x)
				- fractol->fract->size.x / 2;
			fractol->fract->pos.y = scale(y, fractol->mlx.win_size.y,
				fractol->fract->pos.y, fractol->fract->size.y)
				- fractol->fract->size.y / 2;
		}
		else
			fractol->fract->mov_lock = !fractol->fract->mov_lock;
	}
	draw_win(fractol);
	return (0);
}
