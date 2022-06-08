# include <stdlib.h>
# include "fractol.h"

int		fractol_exit(t_fractol *fractol)
{
	if (fractol->mlx.mlx && fractol->mlx.window)
		mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.window);
	if (fractol->mlx.mlx && fractol->mlx.image)
		mlx_destroy_image(fractol->mlx.mlx, fractol->mlx.image);
	exit(0);
}
