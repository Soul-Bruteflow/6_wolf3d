/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:41:20 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/07 11:43:11 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_init_sdl(t_wolf *w)
{
	SDL_Init(SDL_INIT_VIDEO);
	w->sdl->window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w->width, w->height, SDL_WINDOW_OPENGL);
	w->sdl->renderer = SDL_CreateRenderer(w->sdl->window, -1,
		SDL_RENDERER_ACCELERATED);
	w->sdl->screen = SDL_CreateTexture(w->sdl->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
		w->width, w->height);
}

t_wolf	*wolf_init(t_wolf *w)
{
	w = (t_wolf*)malloc(sizeof(t_wolf));
	w->key_state = (const Uint8*)malloc(sizeof(const Uint8));
	w->width = 800;
	w->height = 600;
	w->draw_buffer = (Uint8*)malloc(sizeof(Uint8) * w->width * w->height * 4);
	w->sdl = (t_sdl*)malloc(sizeof(t_sdl));
	w->sdl->window = (SDL_Window*)malloc(sizeof(w->sdl->window));
	w->sdl->renderer = (SDL_Renderer*)malloc(sizeof(w->sdl->renderer));
	w->sdl->screen = (SDL_Texture*)malloc(sizeof(w->sdl->screen));
	return (w);
}
