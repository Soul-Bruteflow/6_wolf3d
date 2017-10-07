/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_second_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 15:12:46 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** 0-9, A-Z = 10-35, a-z = 36-63
*/

Uint8	parse_map_tile(t_wolf *w, int x)
{
	Uint8 tmp;

	tmp = (Uint8)w->line[x];
	if (tmp >= 48 && tmp <= 57)
		tmp -= '0';
	else if (tmp >= 65 && tmp <= 90)
		tmp -= 55;
	else if (tmp >= 97 && tmp <= 122)
		tmp -= 61;
	return (tmp);
}

void	parser_second_read(t_wolf *w)
{
	int i;

	i = 0;
	open_file(w);
	w->map_y = 0;
	while (w->map_y <= w->map_height)
	{
		i = get_next_line(w->fd, &w->line);
		w->map_x = 0;
		while (w->map_x <= w->map_width)
		{
			w->world_map[w->map_y][w->map_x] = parse_map_tile(w, w->map_x);
			w->map_x++;
		}
		w->map_y++;
		free(w->line);
		close_line(w);
	}
	gnl_error(w, i);
	close_file(w);
}
