#include "wolf3d.h"

/*
** Release resources and quit.
*/
void	quit(t_wolf *wolf)
{
	SDL_DestroyTexture(wolf->sdl->screen);
	SDL_DestroyRenderer(wolf->sdl->renderer);
	SDL_DestroyWindow(wolf->sdl->window);
	SDL_Quit();
}

/*
** Clears screen.
** Sets render draw color to black and clears the window with it.
*/
void	screen_clear(t_wolf *wolf)
{
	SDL_SetRenderDrawColor(wolf->sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(wolf->sdl->renderer);
}

/*
**  Shows what was drawn.
*/
void	screen_update(t_wolf *wolf)
{
	SDL_UpdateTexture(wolf->sdl->screen, NULL, &wolf->draw_buffer[0], 800 * 4);
	SDL_RenderCopy(wolf->sdl->renderer, wolf->sdl->screen, NULL, NULL);
	SDL_RenderPresent(wolf->sdl->renderer);
}