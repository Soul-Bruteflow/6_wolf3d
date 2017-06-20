#include "wolf3d.h"

void	assign_textures(t_wolf *w)
{
	w->walls[0] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall0.bmp");
	w->walls[1] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall1.bmp");
	w->walls[2] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall2.bmp");
	w->walls[3] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall3.bmp");
	w->walls[4] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall4.bmp");
	w->walls[5] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall5.bmp");
	w->walls[6] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall6.bmp");
	w->walls[7] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall7.bmp");
	w->walls[8] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall8.bmp");
	w->walls[9] = IMG_LoadTexture(w->sdl->renderer, "./textures/wall9.bmp");
}

void	texture_core(t_wolf *w)
{
	assign_textures(w);
}