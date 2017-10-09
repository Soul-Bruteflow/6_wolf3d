/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 16:12:22 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf_texture_calculate(t_wolf *w)
{
	w->tex_num = w->world_map[w->mapx][w->mapy] - 1;
	if (w->side == 0)
		w->wall_x = w->ray_pos_y + w->perp_wall_dist * w->ray_dir_y;
	else
		w->wall_x = w->ray_pos_x + w->perp_wall_dist * w->ray_dir_x;
	w->wall_x -= floorf(w->wall_x);
	w->tex_x = (int)(w->wall_x * TEX_WIDTH);
	if (w->side == 0 && w->ray_dir_x > 0)
		w->tex_x = TEX_WIDTH - w->tex_x - 1;
	if (w->side == 1 && w->ray_dir_y < 0)
		w->tex_x = TEX_WIDTH - w->tex_x - 1;
}

static void		pixel_buff(t_wolf *w, unsigned int off, unsigned int off1)
{
	w->draw_buffer[off + 0] = w->wall_buffer[w->tex_num][off1 + 0];
	w->draw_buffer[off + 1] = w->wall_buffer[w->tex_num][off1 + 1];
	w->draw_buffer[off + 2] = w->wall_buffer[w->tex_num][off1 + 2];
	w->draw_buffer[off + 3] = w->wall_buffer[w->tex_num][off1 + 3];
}

void			draw_texture(t_wolf *w)
{
	unsigned int	off;
	unsigned int	off1;
	int				y;

	y = w->draw_start;
	while (y < w->draw_end)
	{
		w->tex_y = (int)((y - 600 * 0.5 + w->line_height * 0.5)
		* 128) / w->line_height;
		off = (unsigned int)(800 * 4 * y) + w->ray_per_x * 4;
		off1 = (unsigned int)(128 * 4 * w->tex_y) + w->tex_x * 4;
		if (w->side == 1)
		{
			w->draw_buffer[off + 0] = w->wall_buffer[w->tex_num][off1 + 0] / 2;
			w->draw_buffer[off + 1] = w->wall_buffer[w->tex_num][off1 + 1] / 2;
			w->draw_buffer[off + 2] = w->wall_buffer[w->tex_num][off1 + 2] / 2;
			w->draw_buffer[off + 3] = w->wall_buffer[w->tex_num][off1 + 3] / 2;
		}
		else
			pixel_buff(w, off, off1);
		y++;
	}
}

static void		assign_textures(t_wolf *w)
{
	int		i;

	w->walls[0] = IMG_Load("./resources/textures/wall0.bmp");
	w->walls[1] = IMG_Load("./resources/textures/wall1.bmp");
	w->walls[2] = IMG_Load("./resources/textures/wall2.bmp");
	w->walls[3] = IMG_Load("./resources/textures/wall3.bmp");
	w->walls[4] = IMG_Load("./resources/textures/wall4.bmp");
	w->walls[5] = IMG_Load("./resources/textures/wall5.bmp");
	w->walls[6] = IMG_Load("./resources/textures/wall6.bmp");
	w->walls[7] = IMG_Load("./resources/textures/wall7.bmp");
	w->walls[8] = IMG_Load("./resources/textures/wall8.bmp");
	w->walls[9] = IMG_Load("./resources/textures/wall9.bmp");
	i = -1;
	while (i++ < 9)
	{
		if (w->walls[i] == NULL)
			wolf_error(TEXTURE_ERROR);
	}
}

void			texture_core(t_wolf *w)
{
	int		bpp;
	int		i;

	assign_textures(w);
	i = -1;
	w->wall_buffer = (Uint8**)malloc(sizeof(Uint8*) * 10);
	while (i++ < 9)
	{
		bpp = w->walls[i]->format->BytesPerPixel;
		w->wall_buffer[i] = (Uint8*)w->walls[i]->pixels
		+ 0 * w->walls[i]->pitch + 0 * bpp;
	}
}
