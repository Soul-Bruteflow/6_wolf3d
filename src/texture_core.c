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

	int i;
	void *wall_tmp_buffer;

	w->wall_buffer = (Uint8**)malloc(sizeof(Uint8*) * 10);
	if (w->wall_buffer == NULL)
		wolf_error(MALLOCK_ERROR);
	i = -1;
	while (i++ < 9)
	{
		SDL_LockTexture(w->walls[i], NULL, &wall_tmp_buffer, &w->wall_pitch);
		SDL_UnlockTexture(w->walls[i]);
		w->wall_buffer[i] = (Uint8*)malloc(sizeof(Uint8) * TEX_WIDTH * TEX_HEIGHT * 4);
		if (w->wall_buffer[i] == NULL)
			wolf_error(MALLOCK_ERROR);
		w->wall_buffer[i][0] = (Uint8)wall_tmp_buffer;
	}
}