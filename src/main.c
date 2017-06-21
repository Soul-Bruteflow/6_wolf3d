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



int		main(int ac, char **av)
{
	t_wolf *wolf;

	if (ac == 2)
	{
		wolf = NULL;
		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
		wolf->av = av;
		map_parser(wolf);
//		raycast_init(wolf);
		wolf->pitch = 800 *4;
		wolf->offset = 0;
		game_loop(wolf);
		quit(wolf);
	}
	else
		wolf_error(USSAGE_ERROR);
}


//const Uint8		*key_state;
//int f = 1;
//int w, h;
//
//void draw_wall(t_wolf * wolf, Uint8 *w_p, int wall_pitch);
//
//int	main(int ac, char **av)
//{
//	t_wolf *wolf;
//
//	wolf = (t_wolf*)malloc(sizeof(t_wolf));
//	wolf->key_state = (const Uint8*)malloc(sizeof(const Uint8));
//	wolf->width = 800;
//	wolf->height = 600;
//	wolf->draw_buffer = (Uint8*)malloc(sizeof(Uint8) * wolf->width * wolf->height * 4);
//	wolf->sdl = (t_sdl*)malloc(sizeof(t_sdl));
//
//	wolf->sdl->window = (SDL_Window*)malloc(sizeof(wolf->sdl->window));
//	wolf->sdl->renderer = (SDL_Renderer*)malloc(sizeof(wolf->sdl->renderer));
//	wolf->sdl->screen = (SDL_Texture*)malloc(sizeof(wolf->sdl->screen));
//	SDL_Init(SDL_INIT_VIDEO);
//	wolf->sdl->window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
//	wolf->sdl->renderer = SDL_CreateRenderer(wolf->sdl->window, -1, SDL_RENDERER_ACCELERATED);
//	wolf->sdl->screen = SDL_CreateTexture (wolf->sdl->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 800, 600);
//
//
////	SDL_Texture **img = malloc(sizeof(SDL_Texture *) * 10);
//
////	SDL_Texture *img = SDL_CreateTexture (wolf->sdl->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 128, 128);
//	SDL_Texture *img = IMG_LoadTexture(wolf->sdl->renderer, "./textures/wall0.bmp");
//
////	img[1] = IMG_LoadTexture(wolf->sdl->renderer, "./textures/wall1.bmp");
////	img[2] = IMG_LoadTexture(wolf->sdl->renderer, "./textures/wall2.bmp");
//
////	SDL_QueryTexture(img[0], NULL, NULL, &w, &h);
//
////	Uint8 *w_p = (Uint8*)malloc(sizeof(Uint8) * 128 * 128 * 4);
////	void *pixels = malloc(sizeof(pixels) * 128 * 128 * 4);
//
//	SDL_Surface **walls = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 10);
//	walls[0] = IMG_Load("./textures/wall0.bmp");
//	walls[1] = IMG_Load("./textures/wall1.bmp");
//	walls[2] = IMG_Load("./textures/wall2.bmp");
//	walls[3] = IMG_Load("./textures/wall3.bmp");
//	walls[4] = IMG_Load("./textures/wall4.bmp");
//	walls[5] = IMG_Load("./textures/wall5.bmp");
//	walls[6] = IMG_Load("./textures/wall6.bmp");
//	walls[7] = IMG_Load("./textures/wall7.bmp");
//	walls[8] = IMG_Load("./textures/wall8.bmp");
//	walls[9] = IMG_Load("./textures/wall9.bmp");
//
//
//	int bpp;
//	int i;
//	Uint8 **upixels;
//
//	i = -1;
//	upixels = (Uint8**)malloc(sizeof(Uint8*) * 10);
//	while (i++ < 9)
//	{
//		bpp = walls[i]->format->BytesPerPixel;
////		upixels[i] = (Uint8*)malloc(sizeof(Uint8) * 128 * 128 * 4);
//		upixels[i] = (Uint8*)walls[i]->pixels + 0 * walls[i]->pitch + 0 * bpp;
//	}
//
////	void *dest; int pitch; Uint8 *upixels;
////	SDL_LockTexture(img, NULL, &dest, &pitch);
////	SDL_UnlockTexture(img);
////	upixels = dest;
////	upixels = (Uint8*)malloc(sizeof(Uint8) * 900 * 900 * 4);
//
////	SDL_LockTexture(img, NULL, &pixels, &pitch);
////	Uint8 *upixels = (Uint8*)malloc(sizeof(Uint8) * 128 * 128 * 4);
////	upixels = (Uint8*) pixels;
//
//	while(1)
//	{
////		 event handling
//		SDL_Event e;
//		if ( SDL_PollEvent(&e) ) {
//			if (e.type == SDL_QUIT)
//				break;
//			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
//				break;
//		}
//		SDL_SetRenderDrawColor(wolf->sdl->renderer, 0, 0, 0, 255);
//		SDL_RenderClear(wolf->sdl->renderer);
//
//		unsigned int x = 451;
//		unsigned int y = 251;
//
//		unsigned int x1 = 0;
//		unsigned int y1 = 0;
//
//		int p = 4;
////	65025
//		int j = 0;
//		for (int i = 0; i < 127 * 127 * 4; i += 4)
//		{
//			unsigned int offset = ( 800 * 4 * y ) + x * 4;
//			unsigned int offset1 = ( 128 * 4 * y1 ) + x1 * 4;
//
//			wolf->draw_buffer[ offset + 0 ] = upixels[p][offset1 + 0];	// b
//			wolf->draw_buffer[ offset + 1 ] = upixels[p][offset1 + 1];	// g
//			wolf->draw_buffer[ offset + 2 ] = upixels[p][offset1 + 2];	// r
//			wolf->draw_buffer[ offset + 3 ] = upixels[p][offset1 + 3];	// a
//			if (j % 128 == 0)
//			{
//				y++;
//				y1++;
//				x = 451;
//				x1 = 0;
//			}
//			else
//			{
//				x++;
//				x1++;
//			}
//			j++;
//		}
//
//		// Show what was drawn
//		SDL_UpdateTexture(wolf->sdl->screen, NULL, &wolf->draw_buffer[0], 800 * 4);
//		SDL_RenderCopy(wolf->sdl->renderer, wolf->sdl->screen, NULL, NULL);
////		SDL_RenderCopy(wolf->sdl->renderer, img, NULL, &texr);
//		SDL_RenderPresent(wolf->sdl->renderer);
//	}
//
//	// Release resources
//	SDL_DestroyRenderer(wolf->sdl->renderer);
//	SDL_DestroyWindow(wolf->sdl->window);
//	SDL_Quit();
//	return (0);
//}
//
//void draw_wall(t_wolf * wolf, Uint8 *w_p, int wall_pitch)
//{
//
//}
