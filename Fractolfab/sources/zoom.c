# include "fractol.h"

void	zoom_in(t_fractol *fractol, t_vec2 pos)
{
	fractol->fract->pos.x += fractol->fract->size.x / 3
		* ((double)pos.x / (double)fractol->mlx.win_size.x);
	fractol->fract->pos.y += fractol->fract->size.y / 3
		* ((double)pos.y / (double)fractol->mlx.win_size.y);
	fractol->fract->size.x -= fractol->fract->size.x / 3;
	fractol->fract->size.y -= fractol->fract->size.y / 3;
}
void	zoom_out(t_fractol *fractol, t_vec2 pos)
{
	fractol->fract->pos.x -= fractol->fract->size.x / 3
		* ((double)pos.x / (double)fractol->mlx.win_size.x);
	fractol->fract->pos.y -= fractol->fract->size.y / 3
		* ((double)pos.y / (double)fractol->mlx.win_size.y);
	fractol->fract->size.x += fractol->fract->size.x / 3;
	fractol->fract->size.y += fractol->fract->size.y / 3;
}
