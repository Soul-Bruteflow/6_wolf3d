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
	w->key_state = (const Uint8*)malloc(sizeof(const Uint8));
	w->draw_buffer = NULL;
	w->sdl = (t_sdl*)malloc(sizeof(t_sdl));
	w->sdl->window = (SDL_Window*)malloc(sizeof(w->sdl->window));
	w->sdl->renderer = (SDL_Renderer*)malloc(sizeof(w->sdl->renderer));
	w->sdl->screen = (SDL_Texture*)malloc(sizeof(w->sdl->screen));
	return (w);
}
