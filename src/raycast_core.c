/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 15:20:32 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ray_init(t_wolf *w)
{
	w->camera_x = 2 * w->ray_per_x / (float)w->width - 1;
	w->ray_pos_x = w->pos_x;
	w->ray_pos_y = w->pos_y;
	w->ray_dir_x = w->dir_x + w->plane_x * w->camera_x;
	w->ray_dir_y = w->dir_y + w->plane_y * w->camera_x;
	w->mapx = (int)(w->ray_pos_x);
	w->mapy = (int)(w->ray_pos_y);
	w->sqr_ray_dir_x = w->ray_dir_x * w->ray_dir_x;
	w->sqr_ray_dir_y = w->ray_dir_y * w->ray_dir_y;
	w->delta_dist_x = sqrtf(1 + (w->sqr_ray_dir_y) / (w->sqr_ray_dir_x));
	w->delta_dist_y = sqrtf(1 + (w->sqr_ray_dir_x) / (w->sqr_ray_dir_y));
	w->hit = 0;
}

void	step_init(t_wolf *w)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (w->ray_pos_x - w->mapx) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = (w->mapx + 1.0f - w->ray_pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (w->ray_pos_y - w->mapy) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = (w->mapy + 1.0f - w->ray_pos_y) * w->delta_dist_y;
	}
}

void	wolf_dda(t_wolf *w)
{
	while (w->hit == 0)
	{
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->delta_dist_x;
			w->mapx += w->step_x;
			w->side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->mapy += w->step_y;
			w->side = 1;
		}
		if (w->world_map[w->mapx][w->mapy] > 0)
			w->hit = 1;
	}
}

void	final_calculations(t_wolf *w)
{
	if (w->side == 0)
		w->perp_wall_dist = (w->mapx - w->ray_pos_x +
		(1 - w->step_x) / 2) / w->ray_dir_x;
	else
		w->perp_wall_dist = (w->mapy - w->ray_pos_y +
		(1 - w->step_y) / 2) / w->ray_dir_y;
	w->line_height = (int)(w->height / w->perp_wall_dist);
	w->draw_start = -w->line_height / 2 + w->height / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_height / 2 + w->height / 2;
	if (w->draw_end >= w->height)
		w->draw_end = w->height - 1;
}

void	raycast_core(t_wolf *wolf)
{
	wolf->ray_per_x = -1;
	while (wolf->ray_per_x++ < wolf->width)
	{
		ray_init(wolf);
		step_init(wolf);
		wolf_dda(wolf);
		final_calculations(wolf);
		wolf_texture_calculate(wolf);
		draw_texture(wolf);
		floor_celing_core(wolf);
		floor_celing_draw(wolf);
	}
}
