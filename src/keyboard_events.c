#include "wolf3d.h"

void	keyboard_events(t_wolf *w)
{
	if(SDL_KEYDOWN && w->key_state[SDL_SCANCODE_ESCAPE])
		exit(1);
	if (SDL_KEYDOWN && w->key_state[SDL_SCANCODE_SPACE])
		SDL_SetWindowSize(w->sdl->window, 1600, 900);
}
