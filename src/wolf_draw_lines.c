#include "wolf3d.h"

t_bool verLine(int x, int y1, int y2, t_rgb color, t_wolf *wolf, int w, int h)
{
	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
	if(y2 < 0 || y1 >= h  || x < 0 || x >= w) return false; //no single point of the line is on screen
	if(y1 < 0) y1 = 0; //clip
	if(y2 >= w) y2 = h - 1; //clip


//	Uint32 colorSDL = SDL_MapRGB(scr->format, color.r, color.g, color.b);
//	Uint32* bufp;
//	bufp = (Uint32*)scr->pixels + y1 * scr->pitch / 4 + x;


//	wolf->offset = ((w * 4 * y1) + x * 4);

//	wolf->old_offset = wolf->offset;
//	wolf->offset = (y1 * wolf->pitch/4 + x);

//	bufp = (Uint32*)scr->pixels + y1 * scr->pitch / 4 + x;
	for(int y = y1; y <= y2; y++)
	{
		wolf->offset = (size_t)((w * 4 * y) + x * 4);
		wolf->draw_buffer[wolf->offset + 0] = color.b;			// b
		wolf->draw_buffer[wolf->offset + 1] = color.g;			// g
		wolf->draw_buffer[wolf->offset + 2] = color.r;			// r
		wolf->draw_buffer[wolf->offset + 3] = SDL_ALPHA_OPAQUE;	// a

//		wolf->offset += wolf->pitch/4;

//		*bufp = colorSDL;
//		bufp += scr->pitch / 4;
	}
	return (true);
}
