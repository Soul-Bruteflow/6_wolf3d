#include "wolf3d.h"

int	main(int ac, char **av)
{
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Create a SDL window
	SDL_Window *window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

	// Create a renderer (accelerated and in sync with the display refresh rate)
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Texture* texture = SDL_CreateTexture (renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 800, 600);

	unsigned char *pixels;
	pixels = malloc(sizeof(pixels) * 800 * 600 * 4);

	t_bool running = true;
	SDL_Event event;
	while(running)
	{
		// Process events
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Draw
//		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//		SDL_RenderDrawPoint(renderer, 200, 200);

		for( unsigned int i = 0; i < 1000; i++ )
		{
			const unsigned int x = rand() % 800;
			const unsigned int y = rand() % 600;

			const unsigned int offset = ( 800 * 4 * y ) + x * 4;
			pixels[ offset + 0 ] = rand() % 256;        // b
			pixels[ offset + 1 ] = rand() % 256;        // g
			pixels[ offset + 2 ] = rand() % 256;        // r
			pixels[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a
		}

		// Show what was drawn
		SDL_UpdateTexture(texture, NULL, &pixels[0], 800 * 4);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	// Release resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}