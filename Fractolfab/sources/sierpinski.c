# include "libft.h"
# include "fractol.h"

uint32_t	draw_sierpinski(t_fractol *fractol, t_vec2 pos)
{
	t_vecf2		base_point;
	uint32_t	iter;
	base_point = (t_vecf2){
		.x = ft_double_abs(pos.x
			/ (fractol->mlx.win_size.x / fractol->fract->size.x)
			+ fractol->fract->pos.x),
		.y = ft_double_abs(pos.y
			/ (fractol->mlx.win_size.y / fractol->fract->size.y)
			+ fractol->fract->pos.y)
	};
	iter = 0;
	while (iter < fractol->fract->iter_num)
	{
		if ((int)base_point.x % 3 == 1 && (int)base_point.y % 3 == 1)
			return (iter);
		base_point.x *= 3;
		base_point.y *= 3;
		iter++;
	}
	return (iter);
}
