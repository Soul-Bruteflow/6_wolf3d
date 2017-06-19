#include "wolf3d.h"

t_bool verLine(int x, int y1, int y2, t_rgb color, t_wolf *wolf, int w, int h)
{
	if(y2 < y1)
		ft_xor_swap(&y1, &y2);
	if(y2 < 0 || y1 >= h  || x < 0 || x >= w)
		return false;
	if(y1 < 0)
		y1 = 0;
	if(y2 >= w)
		y2 = h - 1;
	for(int y = y1; y <= y2; y++)
	{
		wolf->offset = (size_t)((w * 4 * y) + x * 4);
		wolf->draw_buffer[wolf->offset + 0] = color.b;			// b
		wolf->draw_buffer[wolf->offset + 1] = color.g;			// g
		wolf->draw_buffer[wolf->offset + 2] = color.r;			// r
		wolf->draw_buffer[wolf->offset + 3] = SDL_ALPHA_OPAQUE;	// a
	}
	return (true);
}
