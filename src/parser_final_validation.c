/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_final_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:11:46 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 16:37:24 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

Uint16	*set_xy(Uint16 start_x, Uint16 start_y, Uint16 end_x, Uint16 end_y)
{
	Uint16	*tmp;

	tmp = malloc(4 * sizeof(tmp));
	tmp[0] = start_x;
	tmp[1] = start_y;
	tmp[2] = end_x;
	tmp[3] = end_y;
	return (tmp);
}

t_bool	border_run(Uint16 *tmp, t_wolf *w)
{
	if (tmp[0] == tmp[2])
	{
		while (tmp[1] <= tmp[3])
		{
			if (w->world_map[tmp[1]][tmp[0]] != 1)
				return (false);
			tmp[1]++;
		}
	}
	else if (tmp[1] == tmp[3])
	{
		while (tmp[0] <= tmp[2])
		{
			if (w->world_map[tmp[1]][tmp[0]] != 1)
				return (false);
			tmp[0]++;
		}
	}
	free(tmp);
	return (true);
}

t_bool	validate_borders(t_wolf *w)
{
	if (!border_run((set_xy(0, 0, w->map_width, 0)), w))
		return (false);
	if (!border_run((set_xy(0, 1, 0, w->map_height)), w))
		return (false);
	if (!border_run((set_xy(1, w->map_height, w->map_width, w->map_height)), w))
		return (false);
	if (!border_run((set_xy(w->map_width, 1, w->map_width,
	(Uint16)(w->map_height - 1))), w))
		return (false);
	return (true);
}

t_bool	validate_center(t_wolf *w)
{
	Uint16 i;
	Uint16 j;

	i = (Uint16)(w->map_center_y - 2);
	while (i < w->map_center_y + 3)
	{
		j = (Uint16)(w->map_center_x - 2);
		while (j < w->map_center_x + 3)
		{
			if (w->world_map[i][j] != 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool	parser_final_validation(t_wolf *w)
{
	if (!validate_borders(w))
		return (false);
	if (!validate_center(w))
		return (false);
	else
		return (true);
}
