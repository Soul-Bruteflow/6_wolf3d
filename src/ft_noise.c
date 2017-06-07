#include "wolf3d.h"

void	ft_noise(t_wolf *wolf)
{
	Uint16	i;
	Uint16	x;
	Uint16	y;
	Uint32	offset;

	i = 0;
	while (i < 1000)
	{
		x = (Uint16)(rand() % wolf->width);
		y = (Uint16)(rand() % wolf->height);
		offset = (Uint32)((wolf->width * 4 * y) + x * 4);
		wolf->draw_buffer[offset + 0] = (Uint8)(rand() % 256);			// b
		wolf->draw_buffer[offset + 1] = (Uint8)(rand() % 256);			// g
		wolf->draw_buffer[offset + 2] = (Uint8)(rand() % 256);			// r
		wolf->draw_buffer[offset + 3] = SDL_ALPHA_OPAQUE;				// a
		i++;
	}
}