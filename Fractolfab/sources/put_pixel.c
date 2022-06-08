# include "fractol.h"

/*
**                   _______
**             _____/       \_____
**             |  _     ___   _   ||
**             | | \     |   | \  ||
**             | |  |    |   |  | ||
**             | |_/     |   |_/  ||
**             | | \     |   |    ||
**             | |  \    |   |    ||
**             | |   \. _|_. | .  ||
**             |                  ||
**             |    seg fault     ||
**             |                  ||
**     *       | *   **    * **   |**      **
**      \))ejm97/.,(//,,..,,\||(,,.,\\,.((//
**
** RIP : Here lies a segfault that could kick you out of your session
*/
void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		*img;
	img = (int*)mlx->buff;
	if (x >= 0 && x < mlx->win_size.x && y >= 0 && y < mlx->win_size.y)
		img[x + mlx->win_size.x * y] = color;
}
