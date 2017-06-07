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
		// Draw
		for( unsigned int i = 0; i < 1000; i++ )
		{
			const unsigned int x = rand() % 800;
			const unsigned int y = rand() % 600;

			const unsigned int offset = ( 800 * 4 * y ) + x * 4;
			wolf->draw_buffer[ offset + 0 ] = rand() % 256;        // b
			wolf->draw_buffer[ offset + 1 ] = rand() % 256;        // g
			wolf->draw_buffer[ offset + 2 ] = rand() % 256;        // r
			wolf->draw_buffer[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a
		}
		screen_update(wolf);
	}
}