#include "wolf3d.h"

void	assign_textures(t_wolf *w)
{
	w->walls[0] = IMG_Load("./textures/wall0.bmp");
	w->walls[1] = IMG_Load("./textures/wall1.bmp");
	w->walls[2] = IMG_Load("./textures/wall2.bmp");
	w->walls[3] = IMG_Load("./textures/wall3.bmp");
	w->walls[4] = IMG_Load("./textures/wall4.bmp");
	w->walls[5] = IMG_Load("./textures/wall5.bmp");
	w->walls[6] = IMG_Load("./textures/wall6.bmp");
	w->walls[7] = IMG_Load("./textures/wall7.bmp");
	w->walls[8] = IMG_Load("./textures/wall8.bmp");
	w->walls[9] = IMG_Load("./textures/wall9.bmp");
}

void	texture_core(t_wolf *w)
{
	int bpp;
	int i;
	assign_textures(w);

	i = -1;
	w->wall_buffer = (Uint8**)malloc(sizeof(Uint8*) * 10);
	while (i++ < 9)
	{
		bpp = w->walls[i]->format->BytesPerPixel;
//		w->wall_buffer[i] = (Uint8*)malloc(sizeof(Uint8) * 128 * 128 * 4);
		w->wall_buffer[i] = (Uint8*)w->walls[i]->pixels + 0 * w->walls[i]->pitch + 0 * bpp;
	}
}