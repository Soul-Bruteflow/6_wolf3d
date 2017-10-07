/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 16:16:57 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_forward(t_wolf *w)
{
	if (w->world_map[(int)(w->pos_x + w->dir_x
		* w->move_speed)][(int)(w->pos_y)] == 0)
		w->pos_x += w->dir_x * w->move_speed;
	if (w->world_map[(int)(w->pos_x)][(int)(w->pos_y +
		w->dir_y * w->move_speed)] == 0)
		w->pos_y += w->dir_y * w->move_speed;
}

void	move_backwards(t_wolf *w)
{
	if (w->world_map[(int)(w->pos_x - w->dir_x *
		w->move_speed)][(int)(w->pos_y)] == 0)
		w->pos_x -= w->dir_x * w->move_speed;
	if (w->world_map[(int)(w->pos_x)][(int)(w->pos_y -
		w->dir_y * w->move_speed)] == 0)
		w->pos_y -= w->dir_y * w->move_speed;
}

void	rotate_right(t_wolf *w)
{
	w->old_dir_x = w->dir_x;
	w->dir_x = w->dir_x * cosf(-w->rot_speed) - w->dir_y * sinf(-w->rot_speed);
	w->dir_y = w->old_dir_x * sinf(-w->rot_speed)
	+ w->dir_y * cosf(-w->rot_speed);
	w->old_plane_x = w->plane_x;
	w->plane_x = w->plane_x * cosf(-w->rot_speed)
	- w->plane_y * sinf(-w->rot_speed);
	w->plane_y = w->old_plane_x * sinf(-w->rot_speed)
	+ w->plane_y * cosf(-w->rot_speed);
}

void	rotate_left(t_wolf *w)
{
	w->old_dir_x = w->dir_x;
	w->dir_x = w->dir_x * cosf(w->rot_speed) - w->dir_y * sinf(w->rot_speed);
	w->dir_y = w->old_dir_x * sinf(w->rot_speed)
	+ w->dir_y * cosf(w->rot_speed);
	w->old_plane_x = w->plane_x;
	w->plane_x = w->plane_x * cosf(w->rot_speed)
	- w->plane_y * sinf(w->rot_speed);
	w->plane_y = w->old_plane_x * sinf(w->rot_speed)
	+ w->plane_y * cosf(w->rot_speed);
}
