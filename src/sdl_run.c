#include "wolf3d.h"

bool done(bool quit_if_esc, bool delay) //delay makes CPU have some free time, use once per frame to avoid 100% usage of a CPU core
{
	if(delay) SDL_Delay(5); //so it consumes less processing power
	int done = 0;
	if(!SDL_PollEvent(&event)) return 0;
	readKeys();
	if(quit_if_esc && inkeys[SDLK_ESCAPE]) done = 1;
	if(event.type == SDL_QUIT) done = 1;
	return done;
}

void readKeys()
{
	SDL_PollEvent(&event);
	inkeys = SDL_GetKeyState(NULL);
}

t_bool	running(void)
{
	t_bool	running;

	running = true;
	SDL_Delay(5);
	if(!SDL_PollEvent(&event))
		return 0;
	readKeys();
}