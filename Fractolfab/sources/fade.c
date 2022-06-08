# include "fractol.h"

int32_t	fade(uint32_t step, uint32_t max_iter)
{
	const int32_t	table[] = {
		0x559597, 0xd0e1b8, 0x9c9b86, 0x87c9ac, 0x44444c
	};
	if (step == max_iter)
		return (0x000);
	return (table[step % 5]);
}