/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:20:48 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 15:00:34 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool		running(SDL_Event *event, const Uint8 **key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);
	if (event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);
	return (true);
}

static void	update_time(t_wolf *wolf)
{
	char	*tmp;

	wolf->old_time = wolf->time;
	wolf->time = SDL_GetTicks();
	wolf->frame_time = (wolf->time - wolf->old_time) / 1000.0f;
	wolf->move_speed = wolf->frame_time * 5.0f;
	wolf->rot_speed = wolf->frame_time * 3.0f;
	if (wolf->fps_counter % 10 == 0)
	{
		tmp = ft_itoa((int)(1.0 / wolf->frame_time));
		wolf->fps[0] = tmp[0];
		wolf->fps[1] = tmp[1];
		wolf->fps[2] = tmp[2];
		wolf->fps[3] = '\0';
		free(tmp);
	}
	wolf->fps_counter++;
}

static void	raycast_init(t_wolf *wolf)
{
	wolf->pos_x = wolf->map_width / 2;
	wolf->pos_y = wolf->map_height / 2;
	wolf->dir_x = 1;
	wolf->dir_y = 0;
	wolf->plane_x = 0;
	wolf->plane_y = -0.67f;
	wolf->time = 0;
	wolf->old_time = 0;
}

void		game_loop(t_wolf *wolf)
{
	raycast_init(wolf);
	wolf_font_init(wolf);
	wolf_audio_init(wolf);
	while ((running(&wolf->sdl->event, &wolf->key_state)))
	{
		raycast_core(wolf);
		world_clear(wolf);
		world_update(wolf);
		update_time(wolf);
		get_user_inputs(wolf);
	}
}
