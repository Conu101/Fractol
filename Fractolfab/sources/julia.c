# include "fractol.h"

uint32_t	draw_julia(t_fractol *fractol, t_vec2 pos)
{
	t_reel		z;
	uint32_t	iter;
	double		tmp;
	z = (t_reel){
		.r = pos.x
			/ (fractol->mlx.win_size.x / fractol->fract->size.x)
			+ fractol->fract->pos.x,
		.i = pos.y
			/ (fractol->mlx.win_size.y / fractol->fract->size.y)
			+ fractol->fract->pos.y
	};
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < fractol->fract->iter_num)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + fractol->mouse_pos.x;
		z.i = 2 * z.i * tmp + fractol->mouse_pos.y;
		iter++;
	}
	return (iter);
}
