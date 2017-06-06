/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:18:23 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/02 11:18:26 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool	running(SDL_Event *event, const Uint8 *key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);
	if(event->type == SDL_QUIT)
		return (false);
	key_state = SDL_GetKeyboardState(NULL);
	if(SDL_KEYDOWN && key_state[SDL_SCANCODE_ESCAPE])
		return (false);
	return (true);
}
