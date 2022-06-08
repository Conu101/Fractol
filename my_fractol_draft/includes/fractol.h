/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:47:39 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/03 15:10:40 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define HEIGHT			1080
# define WIDTH			1920

# define THREADS	10
/*
** <stdlib.h> for exit
*/

//# include <mlx.h>
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "error.h"
# include "color.h"
# include "keycodes.h"

typedef enum
{
	false,
	true
}	t_bool;

/*
** Color
*/

/*
** channel — alpha, red, green, blue color channels
*/

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

/*
**  Complex number
*/

/*
** re — real part
** im — imaginary part
*/

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

/*
** Image
*/

/*
** image          — image identifier
** data_addr      — image
** bits_per_pixel — depth of image
** size_line      — number of bytes used to store one line of image
** endian         — little or big endian
*/

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

/*
** Fract'ol
*/

/*
** mlx            — connection identifier
** window         — window identifier
** image          — information about image
** max_iteration  — maximum iteration
** min            — minimum real and imaginary parts of complex numbers
** max            — maximum real and imaginary parts of complex numbers
** factor         — dependency between complex numbers and pixels
** c              — complex number
** k              — constant complex number (only for Julia)
** is_julia_fixed — flag that reports Julia is fixed or is not
** start_line     — start line of fractal part (needed for multi-threading)
** finish_line    — finish line of fractal part (needed for multi-threading)
** color_shift    — shift of color channels
** formula        — fractal formula
** is_help        — flag that reports help screen is displayed or is not
*/

typedef struct		s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	t_bool			is_julia_fixed;
	int				start_line;
	int				finish_line;
	int				color_shift;
	int				(*formula)(struct s_fractol *fractol);
	t_bool			is_help;
}					t_fractol;

/*
** Formula
*/

/*
** name    — name of fractal
** formula — formula of fractal
*/

typedef struct		s_formula
{
	char			*name;
	int				(*formula)(t_fractol *fractol);
}					t_formula;

int			close_with_x(void *param);
void		draw_fractal(t_fractol *fractol);
void		draw_help(t_fractol *fractol);
t_color		get_color(int iteration, t_fractol *fractol);
t_complex	init_complex(double re, double im);
t_image		*init_image(void *mlx);
int			iterate_julia(t_fractol *fractol);
int			iterate_mandelbrot(t_fractol *fractol);
int			julia_motion(int x, int y, t_fractol *fractol);
int			key_press(int key, t_fractol *fractol);
void		set_defaults(t_fractol *fractol);
void		start_fractol(char *fractal_name);
void		terminate(char *s);
int			zoom(int button, int x, int y, t_fractol *fractol);

#endif
