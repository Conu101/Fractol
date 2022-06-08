# include <stdlib.h>
# include "mlx_keycode.h"
# include "fractol.h"

static void	add_mlx_hook(t_fractol *fractol)
{
	mlx_hook(fractol->mlx.window, KEYPRESS, 0, key_hook, fractol);
	mlx_hook(fractol->mlx.window, MOTIONNOTIFY, 0, mouse_hook, fractol);
	mlx_hook(fractol->mlx.window, BUTTONPRESS, 0, scroll_hook, fractol);
	mlx_hook(fractol->mlx.window, DESTROYNOTIFY, 0, fractol_exit, fractol);
}
int			display_mlx_win(t_fractol *fractol)
{
	fractol->mlx.mlx = mlx_init();
	if (fractol->mlx.mlx != NULL)
	{
		fractol->mlx.window =
			mlx_new_window(fractol->mlx.mlx, fractol->mlx.win_size.x,
			fractol->mlx.win_size.y, "Fractol");
		if (fractol->mlx.window != NULL)
		{
			fractol->mlx.image = mlx_new_image(fractol->mlx.mlx,
				fractol->mlx.win_size.x, fractol->mlx.win_size.y);
			if (fractol->mlx.image != NULL)
			{
				fractol->mlx.buff = mlx_get_data_addr(fractol->mlx.image,
					&fractol->mlx.bpp, &fractol->mlx.buf_wid,
					&fractol->mlx.endian);
				mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.window,
					fractol->mlx.image, 0, 0);
				add_mlx_hook(fractol);
				draw_win(fractol);
				mlx_loop(fractol->mlx.mlx);
				return (0);
			}
		}
	}
	return (1);
}
