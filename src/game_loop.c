#include "wolf3d.h"

t_bool	running(SDL_Event *event, const Uint8 *key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);
	if(event->type == SDL_QUIT)
		return (false);
	key_state = SDL_GetKeyboardState(NULL);
	if(SDL_KEYDOWN && key_state[SDL_SCANCODE_ESCAPE])
		return (false);
	return (true);
}

void	game_loop(t_wolf *wolf)
{
	while((running(&wolf->sdl->event, wolf->key_state)))
	{
		screen_clear(wolf);
		ft_noise(wolf);
		screen_update(wolf);
	}
}