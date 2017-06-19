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


	SDL_Texture **img = malloc(sizeof(SDL_Texture *) * 10);
	img[0] = IMG_LoadTexture(wolf->sdl->renderer, "./textures/wall1.bmp");
	img[1] = IMG_LoadTexture(wolf->sdl->renderer, "./textures/wall2.bmp");
	img[9] = IMG_LoadTexture(wolf->sdl->renderer, "./textures/wall1.bmp");

	SDL_QueryTexture(img[9], NULL, NULL, &w, &h);

	Uint8 *w_p = (Uint8*)malloc(sizeof(Uint8) * 128 * 128 * 4);
	void *wall_pixels;
	int wall_pitch;

	SDL_LockTexture(img[9], NULL, &wall_pixels, &wall_pitch);
	SDL_UnlockTexture(img[9]);

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
	for (int i = 0; i < 127 * 127 * 4; i += 4)
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
