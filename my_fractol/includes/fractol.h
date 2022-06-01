/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:47:39 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/01 20:42:28 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define HEIGHT			1080
# define WIDTH			1920

/*
** <stdlib.h> for exit
*/

//# include <mlx.h>
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "error.h"


typedef struct s_formula
{
	int			param;
}				t_formula;

/*
**  Complex number
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


typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*win;
	t_image		*img;
	t_formula	*formula;
	int			julia_variation;
	int			show_menu;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	t_complex	k;
	int			color_shift;
}				t_fractol;
 


void		terminate(char *s);
void		start_fractol(char *fractal_name);
t_image		*init_image(void *mlx);
void		set_defaults(t_fractol *fractol);
t_complex	init_complex(double re, double im);
int			key_press(int keycode, t_fractol *fractol);

#endif
