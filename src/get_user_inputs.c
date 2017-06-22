/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:23:38 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:23:48 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	get_user_inputs(t_wolf *w)
{
	if (SDL_KEYDOWN && w->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
//	if (SDL_KEYDOWN && w->key_state[SDL_SCANCODE_SPACE])
//	{
//		SDL_SetWindowSize(w->sdl->window, 1600, 900);
//		screen_size(w, 1600, 900);
//		free(w->sdl->screen);
//		w->sdl->screen = SDL_CreateTexture(w->sdl->renderer,
//			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
//											  w->width, w->height);
//		SDL_SetWindowTitle(w->sdl->window, w->win_title_update);
//	}
	if (SDL_KEYDOWN && (w->key_state[SDL_SCANCODE_W]
						|| w->key_state[SDL_SCANCODE_UP]))
	{
		footsteps_sound(w);
		move_forward(w);
	}
	if (SDL_KEYDOWN && (w->key_state[SDL_SCANCODE_S]
						|| w->key_state[SDL_SCANCODE_DOWN]))
	{
		footsteps_sound(w);
		move_backwards(w);
	}
	if (SDL_KEYDOWN && (w->key_state[SDL_SCANCODE_D]
						|| w->key_state[SDL_SCANCODE_RIGHT]))
		rotate_right(w);
	if (SDL_KEYDOWN && (w->key_state[SDL_SCANCODE_A]
						|| w->key_state[SDL_SCANCODE_LEFT]))
		rotate_left(w);
	if (SDL_KEYDOWN && w->key_state[SDL_SCANCODE_P])
	{
		Mix_PlayMusic(w->theme_1, 3);
	}

}
