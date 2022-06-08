/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:47:39 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/08 14:24:42 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		1000
# define HEIGHT		1000

# define THREADS	10

# include "libft.h"
# include <math.h>
# include "mlx.h"
# include <stdint.h>

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

/*
** Functions
*/

/*
** Init
*/

t_image				*init_image(void *mlx); //ok

t_complex			init_complex(double re, double im); //ok

void				set_defaults(t_fractol *fractol); //ok

/*
** Draw
*/
void				start_fractol(char *fractal_name); //ok

void				draw_fractal(t_fractol *fractol); //ok

void				draw_help(t_fractol *fractol); //ok


/*
** Fractals
*/

int					(*get_formula(char *name)) (t_fractol *fractol);


int					iterate_mandelbrot(t_fractol *fractol); //ok

int					iterate_julia(t_fractol *fractol); //ok

int					iterate_sierpinski(t_fractol *fractol); //ok


/*
** Color
*/

t_color				get_color(int iteration, t_fractol *fractol);//ok

/*
** Controls
*/


int					key_press(int key, t_fractol *fractol); //ok

int					zoom(int button, int x, int y, t_fractol *fractol); //ok

int					julia_motion(int x, int y, t_fractol *fractol); //ok


/*
** Utils
*/

void				terminate(char *s); //ok

int					close_window(void *param); //ok

#endif
