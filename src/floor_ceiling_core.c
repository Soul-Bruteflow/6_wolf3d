/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_core.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 14:56:13 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		floor_celing_draw(t_wolf *w)
{
	unsigned int	off;
	unsigned int	off1;
	int				y;

	y = w->draw_end + 1;
	while (y < w->height)
	{
		w->current_dist = w->height / (2.0f * y - w->height);
		w->weight = (w->current_dist - w->dist_player)
		/ (w->dist_wall - w->dist_player);
		w->current_floot_x = w->weight
		* w->floor_x_wall + (1.0f - w->weight) * w->pos_x;
		w->current_floot_y = w->weight
		* w->floor_y_wall + (1.0f - w->weight) * w->pos_y;
		w->floor_tex_x = (int)(w->current_floot_x * TEX_WIDTH) % TEX_WIDTH;
		w->floor_tex_y = (int)(w->current_floot_y * TEX_HEIGHT) % TEX_HEIGHT;
		off = (unsigned int)(800 * 4 * y) + w->ray_per_x * 4;
		off1 = (unsigned int)(128 * 4 * w->floor_tex_y) + w->floor_tex_x * 4;
		ft_pixel_buff_shade(w, off, off1, 3);
		off = (unsigned int)(800 * 4 * (w->height - y)) + w->ray_per_x * 4;
		ft_pixel_buff_shade(w, off, off1, 4);
		y++;
	}
}

void		floor_celing_core(t_wolf *w)
{
	if (w->side == 0 && w->ray_dir_x > 0)
	{
		w->floor_x_wall = w->mapx;
		w->floor_y_wall = w->mapy + w->wall_x;
	}
	else if (w->side == 0 && w->ray_dir_x < 0)
	{
		w->floor_x_wall = w->mapx + 1.0f;
		w->floor_y_wall = w->mapy + w->wall_x;
	}
	else if (w->side == 1 && w->ray_dir_y > 0)
	{
		w->floor_x_wall = w->mapx + w->wall_x;
		w->floor_y_wall = w->mapy;
	}
	else
	{
		w->floor_x_wall = w->mapx + w->wall_x;
		w->floor_y_wall = w->mapy + 1.0f;
	}
	w->dist_wall = w->perp_wall_dist;
	w->dist_player = 0.0;
	if (w->draw_end < 0)
		w->draw_end = w->height;
}
