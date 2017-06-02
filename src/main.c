#include "wolf3d.h"

const Uint8		*key_state;

int	main(int ac, char **av)
{
	t_wolf *wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	wolf->key_state = (const Uint8*)malloc(sizeof(const Uint8));
	wolf->width = 800;
	wolf->height = 600;
	wolf->pixels = (Uint8*)malloc(sizeof(Uint8) * wolf->width * wolf->height * 4);
	wolf->sdl = (t_sdl*)malloc(sizeof(t_sdl));

	wolf->sdl->window = (SDL_Window*)malloc(sizeof(wolf->sdl->window));
	wolf->sdl->renderer = (SDL_Renderer*)malloc(sizeof(wolf->sdl->renderer));
	wolf->sdl->screen = (SDL_Texture*)malloc(sizeof(wolf->sdl->screen));
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Create a SDL window
	wolf->sdl->window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

	// Create a renderer (accelerated and in sync with the display refresh rate)
	wolf->sdl->renderer = SDL_CreateRenderer(wolf->sdl->window, -1, SDL_RENDERER_ACCELERATED);

	wolf->sdl->screen = SDL_CreateTexture (wolf->sdl->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 800, 600);

//	unsigned char *pixels;
//	pixels = malloc(sizeof(pixels) * 800 * 600 * 4);

//	t_bool running = true;
//	SDL_Event event;
	while((running(&wolf->sdl->event, wolf->key_state)))
	{
		// Process events
//		while(SDL_PollEvent(&wolf->sdl->event))
//		{
//			if(wolf->sdl->event.type == SDL_QUIT)
//				running = false;
//		}
//		wolf->key_state = SDL_GetKeyboardState(NULL);
//		if (wolf->key_state[SDL_SCANCODE_ESCAPE])
//		{
//				running = false;
//		}

		// Clear screen
		SDL_SetRenderDrawColor(wolf->sdl->renderer, 0, 0, 0, 255);
		SDL_RenderClear(wolf->sdl->renderer);

		// Draw
//		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//		SDL_RenderDrawPoint(renderer, 200, 200);

		for( unsigned int i = 0; i < 1000; i++ )
		{
			const unsigned int x = rand() % 800;
			const unsigned int y = rand() % 600;

			const unsigned int offset = ( 800 * 4 * y ) + x * 4;
			wolf->pixels[ offset + 0 ] = rand() % 256;        // b
			wolf->pixels[ offset + 1 ] = rand() % 256;        // g
			wolf->pixels[ offset + 2 ] = rand() % 256;        // r
			wolf->pixels[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a
		}

		// Show what was drawn
		SDL_UpdateTexture(wolf->sdl->screen, NULL, &wolf->pixels[0], 800 * 4);
		SDL_RenderCopy(wolf->sdl->renderer, wolf->sdl->screen, NULL, NULL);
		SDL_RenderPresent(wolf->sdl->renderer);
	}

	// Release resources
	SDL_DestroyRenderer(wolf->sdl->renderer);
	SDL_DestroyWindow(wolf->sdl->window);
	SDL_Quit();
	return (0);
}