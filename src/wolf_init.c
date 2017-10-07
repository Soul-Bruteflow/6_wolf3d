/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:41:20 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 16:13:25 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_wolf	*wolf_init(t_wolf *w, Uint16 width, Uint16 height, const char *title)
{
	w->draw_buffer = NULL;
	w->sdl = (t_sdl*)malloc(sizeof(t_sdl));
	if (w->sdl == NULL)
		wolf_error(MALLOCK_ERROR);
	w->walls = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * TEX_NBR);
	if (w->walls == NULL)
		wolf_error(MALLOCK_ERROR);
	texture_core(w);
	create_screen(w, width, height, title);
	return (w);
}
