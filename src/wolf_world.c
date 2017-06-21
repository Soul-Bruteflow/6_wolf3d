/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:26:59 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:27:59 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Release resources and quit.
*/

void	quit(t_wolf *wolf)
{
	SDL_DestroyTexture(wolf->sdl->screen);
	SDL_DestroyRenderer(wolf->sdl->renderer);
	SDL_DestroyWindow(wolf->sdl->window);
	SDL_Quit();
}

/*
** Clears screen.
** Sets render draw color to black and clears the window with it.
*/

void	world_clear(t_wolf *wolf)
{
	SDL_SetRenderDrawColor(wolf->sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(wolf->sdl->renderer);
}

/*
**  Shows what was drawn.
*/

void	world_update(t_wolf *wolf)
{

	wolf->sur_message = TTF_RenderText_Blended(wolf->font, wolf->fps, wolf->white);
	wolf->tex_message = SDL_CreateTextureFromSurface(wolf->sdl->renderer, wolf->sur_message);

	SDL_UpdateTexture(wolf->sdl->screen, NULL, &wolf->draw_buffer[0], 800 * 4);
	SDL_RenderCopy(wolf->sdl->renderer, wolf->sdl->screen, NULL, NULL);
	SDL_RenderCopy(wolf->sdl->renderer, wolf->tex_message, NULL, &wolf->message_rect);
	SDL_RenderPresent(wolf->sdl->renderer);
	bzero(wolf->draw_buffer, 800 * 600 * 4);
}
