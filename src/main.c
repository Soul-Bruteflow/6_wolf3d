/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:13:15 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:14:44 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast_init(t_wolf *w)
{
	w->pos_y = 12;
	w->pos_x = 22;
	w->dir_y = 0;
	w->dir_x = -1;
	w->plane_y = 0.66;
	w->plane_x = 0;
	w->time = 0;
	w->old_time = 0;
}

int		main(int ac, char **av)
{
	t_wolf *wolf;

	if (ac == 2)
	{
		wolf = NULL;
		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
		wolf->av = av;
		map_parser(wolf);
		raycast_init(wolf);
		game_loop(wolf);
		quit(wolf);
	}
	else
		wolf_error(USSAGE_ERROR);
}
