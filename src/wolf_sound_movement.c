/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sound_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 16:17:56 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	footsteps_sound(t_wolf *w)
{
	if (w->step_counter % 15 == 0 && w->music_pause_flag == 0)
	{
		if (w->step == 0)
		{
			Mix_PlayChannel(1, w->step_1, 0);
			w->step = 1;
		}
		else if (w->step == 1)
		{
			Mix_PlayChannel(2, w->step_2, 0);
			w->step = 0;
		}
	}
	w->step_counter += 1;
}
