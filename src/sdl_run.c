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

void	read_keys(SDL_Event *event, Uint8 *input_keys)
{
	SDL_PollEvent(event);
	input_keys = SDL_GetKeyboardState(NULL);
}

t_bool	key_is_down(Uint8 key, uint8_t *input_keys)
{
	if (input_keys[key] != 0)
		return (true);
	return (false);
}

t_bool	running(SDL_Event event, Uint8 *input_keys)
{
	SDL_Delay(5);
	if (!SDL_PollEvent(&event))
		return (true);
	read_keys(&event, input_keys);
	if(input_keys[SDL_SCANCODE_ESCAPE])
		return (false);
	if(event.type == SDL_QUIT)
		return (false);
	return (true);
}
