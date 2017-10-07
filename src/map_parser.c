/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 15:03:51 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_parser(t_wolf *w)
{
	parser_first_read(w);
	w->map_size_y = w->map_y;
	w->map_size_x = w->map_x;
	w->map_height = (Uint16)(w->map_size_y - 1);
	w->map_width = (Uint16)(w->map_size_x - 1);
	w->map_center_y = (Uint16)(w->map_size_y / 2);
	w->map_center_x = (Uint16)(w->map_size_x / 2);
	w->world_map = (Uint8**)ft_malloc_2d_array(sizeof(w->world_map),
			w->map_size_x, w->map_size_y);
	parser_second_read(w);
	if (parser_final_validation(w) == false)
		exit(0);
}
