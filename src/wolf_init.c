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

}

t_wolf	*wolf_init(t_wolf *w)
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
	return (w);
}