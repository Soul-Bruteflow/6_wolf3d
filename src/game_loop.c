/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:20:48 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:23:23 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool	running(SDL_Event *event, const Uint8 **key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);
	if (event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);
	return (true);
}

void	game_loop(t_wolf *wolf)
{
	while ((running(&wolf->sdl->event, &wolf->key_state)))
	{
		get_user_inputs(wolf);
		world_clear(wolf);
		ft_noise(wolf);
		world_update(wolf);
	}
}
