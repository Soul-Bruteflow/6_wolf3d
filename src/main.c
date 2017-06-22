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
		wolf = (t_wolf*)malloc(sizeof(t_wolf));
		if (wolf == NULL)
			wolf_error(MALLOCK_ERROR);
		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
		wolf->av = av;
		map_parser(wolf);
		wolf->pitch = 800 *4;
		wolf->offset = 0;
		game_loop(wolf);
		quit(wolf);
	}
	else
		wolf_error(USSAGE_ERROR);
}

