/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_fns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:27:34 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/03 15:02:33 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Terminate execution and display error message from pre-defined error 
** types (macros) .
*/

void	terminate(char *s)
{
	ft_putendl(s);
	exit(0);
}

/*
** Terminate execution when close "cross" is clicked.
*/

int		close_with_x(void *param)
{
	(void)param;
	exit(0);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

