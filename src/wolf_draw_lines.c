#include "wolf3d.h"

t_bool verLine(int x, int y1, int y2, t_rgb color, t_wolf *w)
{
	if(y2 < y1)
		ft_xor_swap(&y1, &y2);
	if(y2 < 0 || y1 >= w->height  || x < 0 || x >= w->width)
		return (false);
	if(y1 < 0)
		y1 = 0;
	if(y2 >= w->width)
		y2 = w->height - 1;

//	Uint32 colorSDL = SDL_MapRGB(scr->format, color.r, color.g, color.b);
//	Uint32* bufp;
//	bufp = (Uint32*)scr->pixels + y1 * scr->pitch / 4 + x;

	for(int y = y1; y <= y2; y++)
	{

		Uint32 offset = (Uint32)((w->width * 4 * y) + x * 4);
		w->draw_buffer[offset + 0] = color.b;			// b
		w->draw_buffer[offset + 1] = color.g;			// g
		w->draw_buffer[offset + 2] = color.r;			// r
		w->draw_buffer[offset + 3] = SDL_ALPHA_OPAQUE;				// a

//		*bufp = colorSDL;
//		bufp += scr->pitch / 4;
	}
	return (true);
}
