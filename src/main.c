/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:13:15 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:14:44 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"



//int		main(int ac, char **av)
//{
//	t_wolf *wolf;
//
//	if (ac == 2)
//	{
//		wolf = NULL;
//		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
//		wolf->av = av;
//		map_parser(wolf);
////		raycast_init(wolf);
//		wolf->pitch = 800 *4;
//		wolf->offset = 0;
//		game_loop(wolf);
//		quit(wolf);
//	}
//	else
//		wolf_error(USSAGE_ERROR);
//}



//#define WIDTH 800
//#define HEIGHT 600
//#define IMG_PATH "wall1.bmp"
//
//int main (int argc, char *argv[]) {
//
//	Uint8			*draw_buffer;
//	draw_buffer = (Uint8*)malloc(sizeof(Uint8) * 800 * 600 * 4);
//	// variable declarations
//	SDL_Window *win = NULL;
//	SDL_Renderer *renderer = NULL;
//	SDL_Texture *img = NULL;
//	int w, h; // texture width & height
//
//	// Initialize SDL.
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//		return 1;
//
//	// create the window and renderer
//	// note that the renderer is accelerated
//	win = SDL_CreateWindow("Image Loading", 100, 100, WIDTH, HEIGHT, 0);
//	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
//
//	// load our image
//	img = IMG_LoadTexture(renderer, IMG_PATH);
//	SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
//	// put the location where we want the texture to be drawn into a rectangle
//	// I'm also scaling the texture 2x simply by setting the width and height
//	SDL_Rect texr; texr.x = WIDTH/2; texr.y = HEIGHT/2; texr.w = w*2; texr.h = h*2;
//
//	// main loop
//	while (1) {
//
//		// event handling
//		SDL_Event e;
//		if ( SDL_PollEvent(&e) ) {
//			if (e.type == SDL_QUIT)
//				break;
//			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
//				break;
//		}
//
////		// clear the screen
////		SDL_RenderClear(renderer);
////		// copy the texture to the rendering context
////		SDL_RenderCopy(renderer, img, NULL, &texr);
////		// flip the backbuffer
////		// this means that everything that we prepared behind the screens is actually shown
////		SDL_RenderPresent(renderer);
//
//
//		Uint16	i;
//		Uint16	x;
//		Uint16	y;
//		Uint32	offset;
//		i = 0;
//		while (i < 1000)
//		{
//			x = (Uint16)(rand() % 800);
//			y = (Uint16)(rand() % 600);
//			offset = (Uint32)((800 * 4 * y) + x * 4);
//			draw_buffer[offset + 0] = (Uint8)(rand() % 256);			// b
//			draw_buffer[offset + 1] = (Uint8)(rand() % 256);			// g
//			draw_buffer[offset + 2] = (Uint8)(rand() % 256);			// r
//			draw_buffer[offset + 3] = SDL_ALPHA_OPAQUE;				// a
//			i++;
//		}
//
//
//		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//		SDL_RenderClear(renderer);
//		SDL_UpdateTexture(screen, NULL, &draw_buffer[0], 800 * 4);
//		SDL_RenderCopy(renderer, screen, NULL, NULL);
//		SDL_RenderPresent(renderer);
////		bzero(draw_buffer, 800 * 600 * 4);
//
//	}
//
//	SDL_DestroyTexture(img);
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(win);
//
//	return 0;
//}

#include "wolf3d.h"

const Uint8		*key_state;
int f = 1;
int w, h;

void draw_wall(t_wolf * wolf, Uint8 *w_p, int wall_pitch);

int	main(int ac, char **av)
{
	t_wolf *wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	wolf->key_state = (const Uint8*)malloc(sizeof(const Uint8));
	wolf->width = 800;
	wolf->height = 600;
	wolf->draw_buffer = (Uint8*)malloc(sizeof(Uint8) * wolf->width * wolf->height * 4);
	wolf->sdl = (t_sdl*)malloc(sizeof(t_sdl));

	wolf->sdl->window = (SDL_Window*)malloc(sizeof(wolf->sdl->window));
	wolf->sdl->renderer = (SDL_Renderer*)malloc(sizeof(wolf->sdl->renderer));
	wolf->sdl->screen = (SDL_Texture*)malloc(sizeof(wolf->sdl->screen));
	SDL_Init(SDL_INIT_VIDEO);
	wolf->sdl->window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	wolf->sdl->renderer = SDL_CreateRenderer(wolf->sdl->window, -1, SDL_RENDERER_ACCELERATED);
	wolf->sdl->screen = SDL_CreateTexture (wolf->sdl->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 800, 600);


	SDL_Texture *img = NULL;
	img = IMG_LoadTexture(wolf->sdl->renderer, "./textures/wall1.bmp");
	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	SDL_Rect texr; texr.x = 800/2; texr.y = 600/2; texr.w = w; texr.h = h;

	Uint8 *w_p = (Uint8*)malloc(sizeof(Uint8) * 128 * 128 * 4);
	void *wall_pixels;
	int wall_pitch;

	SDL_LockTexture(img, NULL, &wall_pixels, &wall_pitch);
	SDL_UnlockTexture(img);

	while(1)
	{
//		 event handling
		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
		}

		SDL_SetRenderDrawColor(wolf->sdl->renderer, 0, 0, 0, 255);
		SDL_RenderClear(wolf->sdl->renderer);

		for( unsigned int i = 0; i < 1000; i++ )
		{
			const unsigned int x = rand() % 400;
			const unsigned int y = rand() % 200;

			const unsigned int offset = ( 800 * 4 * y ) + x * 4;
			wolf->draw_buffer[ offset + 0 ] = 26;        // b
			wolf->draw_buffer[ offset + 1 ] = 26;        // g
			wolf->draw_buffer[ offset + 2 ] = 155;        // r
			wolf->draw_buffer[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a
		}


		if (f == 1)
		{
			draw_wall(wolf, w_p, wall_pitch);
			f = 0;
		}


		// Show what was drawn
		SDL_UpdateTexture(wolf->sdl->screen, NULL, &wolf->draw_buffer[0], 800 * 4);
		SDL_RenderCopy(wolf->sdl->renderer, wolf->sdl->screen, NULL, NULL);
//		SDL_RenderCopy(wolf->sdl->renderer, img, NULL, &texr);
		SDL_RenderPresent(wolf->sdl->renderer);
	}

	// Release resources
	SDL_DestroyRenderer(wolf->sdl->renderer);
	SDL_DestroyWindow(wolf->sdl->window);
	SDL_Quit();
	return (0);
}

void draw_wall(t_wolf * wolf, Uint8 *w_p, int wall_pitch)
{
	unsigned int x = 451;
	unsigned int y = 251;

	unsigned int x1 = 0;
	unsigned int y1 = 0;

//	65025
	int j = 0;
	for (int i = 0; i < w * h * 4; i += 4)
	{
		unsigned int offset = ( 800 * 4 * y ) + x * 4;
		unsigned int offset1 = ( 128 * 4 * y1 ) + x1 * 4;

		wolf->draw_buffer[ offset + 0 ] = w_p[offset1 + 0];	// b
		wolf->draw_buffer[ offset + 1 ] = w_p[offset1 + 1];	// g
		wolf->draw_buffer[ offset + 2 ] = w_p[offset1 + 2];	// r
		wolf->draw_buffer[ offset + 3 ] = w_p[offset1 + 3];	// a
		if (j % 128 == 0)
		{
			y++;
			y1++;
			x = 451;
			x1 = 0;
		}
		else
		{
			x++;
			x1++;
		}
		j++;
	}
}
