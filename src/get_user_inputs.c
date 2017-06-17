/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:23:38 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:23:48 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	get_user_inputs(t_wolf *wolf)
{
	if (SDL_KEYDOWN && wolf->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
	if (SDL_KEYDOWN && wolf->key_state[SDL_SCANCODE_SPACE])
	{
		SDL_SetWindowSize(wolf->sdl->window, 1600, 900);
		screen_size(wolf, 1600, 900);
		free(wolf->sdl->screen);
		wolf->sdl->screen = SDL_CreateTexture(wolf->sdl->renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
											  wolf->width, wolf->height);
		SDL_SetWindowTitle(wolf->sdl->window, wolf->win_title_update);
	}
	if (SDL_KEYDOWN && wolf->key_state[SDL_SCANCODE_W])
	{
		if(wolf->world_map[(int)(wolf->pos_x + wolf->dir_x * wolf->move_speed)][(int)(wolf->pos_y)] == 0) wolf->pos_x += wolf->dir_x * wolf->move_speed;
		if(wolf->world_map[(int)(wolf->pos_x)][(int)(wolf->pos_y + wolf->dir_y * wolf->move_speed)] == 0) wolf->pos_y += wolf->dir_y * wolf->move_speed;
	}
	//move backwards if no wall behind you
	if (SDL_KEYDOWN && wolf->key_state[SDL_SCANCODE_S])
	{
		if(wolf->world_map[(int)(wolf->pos_x - wolf->dir_x * wolf->move_speed)][(int)(wolf->pos_y)] == 0) wolf->pos_x -= wolf->dir_x * wolf->move_speed;
		if(wolf->world_map[(int)(wolf->pos_x)][(int)(wolf->pos_y - wolf->dir_y * wolf->move_speed)] == 0) wolf->pos_y -= wolf->dir_y * wolf->move_speed;
	}
	//rotate to the right
	if (SDL_KEYDOWN && wolf->key_state[SDL_SCANCODE_D])
	{
		//both camera direction and camera plane must be rotated
		wolf->old_dir_x = wolf->dir_x;
		wolf->dir_x = wolf->dir_x * cosf(-wolf->rot_speed) - wolf->dir_y * sinf(-wolf->rot_speed);
		wolf->dir_y = wolf->old_dir_x * sinf(-wolf->rot_speed) + wolf->dir_y * cosf(-wolf->rot_speed);
		wolf->old_plane_x = wolf->plane_x;
		wolf->plane_x = wolf->plane_x * cosf(-wolf->rot_speed) - wolf->plane_y * sinf(-wolf->rot_speed);
		wolf->plane_y = wolf->old_plane_x * sinf(-wolf->rot_speed) + wolf->plane_y * cosf(-wolf->rot_speed);
	}
	//rotate to the left
	if (SDL_KEYDOWN && wolf->key_state[SDL_SCANCODE_A])
	{
		//both camera direction and camera plane must be rotated
		wolf->old_dir_x = wolf->dir_x;
		wolf->dir_x = wolf->dir_x * cosf(wolf->rot_speed) - wolf->dir_y * sinf(wolf->rot_speed);
		wolf->dir_y = wolf->old_dir_x * sinf(wolf->rot_speed) + wolf->dir_y * cosf(wolf->rot_speed);
		wolf->old_plane_x = wolf->plane_x;
		wolf->plane_x = wolf->plane_x * cosf(wolf->rot_speed) - wolf->plane_y * sinf(wolf->rot_speed);
		wolf->plane_y = wolf->old_plane_x * sinf(wolf->rot_speed) + wolf->plane_y * cosf(wolf->rot_speed);
	}
}
