/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_fns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:27:34 by ctrouve           #+#    #+#             */
/*   Updated: 2022/06/01 15:38:29 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Terminate execution and display error message either from pre-defined error 
** types (macros) .
*/

void	terminate(char *s)
{
	ft_putendl(s);
	exit(1);
}
