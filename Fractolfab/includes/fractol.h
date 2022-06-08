#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include <stdint.h>
# include "mlx.h"

typedef struct	s_vec2
{
	int32_t		x;
	int32_t		y;
}				t_vec2;
typedef struct	s_vecf2
{
	double		x;
	double		y;
}				t_vecf2;
typedef struct	s_reel
{
	double		r;
	double		i;
}				t_reel;
typedef struct	s_pixel
{
	int32_t		x;
	int32_t		y;
	int32_t		color;
}				t_pixel;
typedef struct	s_mlx
{
	void		*image;
	char		*buff;
	int			buf_wid;
	void		*window;
	void		*mlx;
	t_vec2		win_size;
	int			bpp;
	int			endian;
}				t_mlx;
struct s_fractol;
typedef struct	s_fract
{
	const char	*name;
	t_vecf2		size;
	t_vecf2		pos;
	uint32_t	(*draw)(struct s_fractol *fractol, t_vec2 pos);
	uint32_t	iter_num;
	bool		movable;
	bool		mov_lock;
}				t_fract;
typedef struct	s_fractol
{
	t_mlx		mlx;
	t_fract		*fract;
	t_vecf2		mouse_pos;
}				t_fractol;
/*
** init
*/
void			init_fractol(t_fractol *fractol);
/*
** exit
*/
int32_t			fractol_exit(t_fractol *fractol);
/*
** mlx
*/
int32_t			display_mlx_win(t_fractol *fractol);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
/*
** draw
*/
void			draw_win(t_fractol *fractol);
uint32_t		draw_mandelbrot(t_fractol *fractol, t_vec2 pos);
uint32_t		draw_julia(t_fractol *fractol, t_vec2 pos);
uint32_t		draw_ship(t_fractol *fractol, t_vec2 pos);
uint32_t		draw_mandelrot(t_fractol *fractol, t_vec2 pos);
uint32_t		draw_sierpinski(t_fractol *fractol, t_vec2 pos);
/*
** hook
*/
int				key_hook(int keycode, t_fractol *fractol);
int				mouse_hook(int x, int y, t_fractol *fractol);
int				scroll_hook(int button, int x, int y, t_fractol *fractol);
/*
** fade
*/
int32_t			fade(uint32_t step, uint32_t max_iter);
/*
** zoom
*/
void			zoom_in(t_fractol *fractol, t_vec2 pos);
void			zoom_out(t_fractol *fractol, t_vec2 pos);

#endif
