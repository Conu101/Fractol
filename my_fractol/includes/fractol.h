/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:47:39 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/01 16:44:17 by ctrouve          ###   ########.fr       */
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

typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_formula	*formula;
	int			julia_set_can_vary;
	int			show_menu;
	
}				t_fractol;

void	terminate(char *s);
void	start_fractol(char *fractal_name);

#endif
