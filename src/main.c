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

int		main(int ac, char **av)
{
	t_wolf *wolf;

	if (ac == 2)
	{
		wolf = NULL;
		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
		wolf->av = av;
		map_parser(wolf);
//		raycast_init(wolf);
		wolf->pitch = 800 *4;
		wolf->offset = 0;
		game_loop(wolf);
		quit(wolf);
	}
	else
		wolf_error(USSAGE_ERROR);
}
