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

void	malloc_textures(t_wolf *w)
{

}

void	malloc_screen(t_wolf *w)
{

}

void	malloc_main(t_wolf *w)
{

}

t_wolf	*wolf_init(t_wolf *w, Uint16 width, Uint16 height, const char *title)
{

	w = (t_wolf*)malloc(sizeof(t_wolf));
	if (w == NULL)
		wolf_error(MALLOCK_ERROR);
	w->key_state = (const Uint8*)malloc(sizeof(const Uint8));
	if (w->key_state == NULL)
		wolf_error(MALLOCK_ERROR);
	w->draw_buffer = NULL;
	w->sdl = (t_sdl*)malloc(sizeof(t_sdl));
	if (w->sdl == NULL)
		wolf_error(MALLOCK_ERROR);

	w->sdl->window = (SDL_Window*)malloc(sizeof(w->sdl->window));
	if (w->sdl->window == NULL)
		wolf_error(MALLOCK_ERROR);
	w->sdl->renderer = (SDL_Renderer*)malloc(sizeof(w->sdl->renderer));
	if (w->sdl->renderer == NULL)
		wolf_error(MALLOCK_ERROR);
	w->sdl->screen = (SDL_Texture*)malloc(sizeof(w->sdl->screen));
	if (w->sdl->screen == NULL)
		wolf_error(MALLOCK_ERROR);


	w->walls = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * TEX_NBR);
	if (w->sdl->screen == NULL)
		wolf_error(MALLOCK_ERROR);
	w->wall_buffer = (Uint8*)malloc(sizeof(Uint8) * TEX_WIDTH * TEX_HEIGHT * 4);
	if (w->sdl->screen == NULL)
		wolf_error(MALLOCK_ERROR);




	malloc_main(w);
	malloc_screen(w);
	malloc_textures(w);
	texture_core(w);
	create_screen(w, width, height, title);
	return (w);
}
