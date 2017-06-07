#include "wolf3d.h"

t_bool	running(SDL_Event *event, const Uint8 **key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);
	if(event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);
	return (true);
}

void	game_loop(t_wolf *wolf)
{
	while((running(&wolf->sdl->event, &wolf->key_state)))
	{
		keyboard_events(wolf);
		screen_clear(wolf);
		ft_noise(wolf);
		screen_update(wolf);
	}
}