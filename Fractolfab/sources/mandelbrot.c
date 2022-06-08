# include "fractol.h"

uint32_t	draw_mandelbrot(t_fractol *fractol, t_vec2 pos)
{
	t_reel		base_point;
	t_reel		z;
	uint32_t	iter;
	double		tmp;
	base_point = (t_reel){
		.r = pos.x
			/ (fractol->mlx.win_size.x / fractol->fract->size.x)
			+ fractol->fract->pos.x,
		.i = pos.y
			/ (fractol->mlx.win_size.y / fractol->fract->size.y)
			+ fractol->fract->pos.y
	};
	z = base_point;
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < fractol->fract->iter_num)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + base_point.r;
		z.i = 2 * z.i * tmp + base_point.i;
		iter++;
	}
	return (iter);
}
uint32_t	draw_mandelrot(t_fractol *fractol, t_vec2 pos)
{
	t_reel		base_point;
	t_reel		z;
	uint32_t	iter;
	double		tmp;
	base_point = (t_reel){
		.r = pos.y
			/ (fractol->mlx.win_size.y / fractol->fract->size.y)
			+ fractol->fract->pos.y,
		.i = pos.x
			/ (fractol->mlx.win_size.x / fractol->fract->size.x)
			+ fractol->fract->pos.x
	};
	z = base_point;
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < fractol->fract->iter_num)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + base_point.r;
		z.i = 2 * z.i * tmp + base_point.i;
		iter++;
	}
	return (iter);
}
