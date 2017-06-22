#include "wolf3d.h"

void	floor_celing_draw(t_wolf *w)
{
	unsigned int offs;
	unsigned int offs1;
	for(int y = w->draw_end + 1; y < w->height; y++)
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
		offs = (unsigned int)(800 * 4 * y) + w->ray_per_x * 4;
		offs1 = (unsigned int)(128 * 4 * w->floor_tex_y) + w->floor_tex_x * 4;
		w->draw_buffer[ offs + 0 ] = (Uint8)(w->wall_buffer[3][offs1 + 0] / 2);
		w->draw_buffer[ offs + 1 ] = (Uint8)(w->wall_buffer[3][offs1 + 1] / 2);
		w->draw_buffer[ offs + 2 ] = (Uint8)(w->wall_buffer[3][offs1 + 2] / 2);
		w->draw_buffer[ offs + 3 ] = (Uint8)(w->wall_buffer[3][offs1 + 3] / 2);
		offs = (unsigned int)(800 * 4 * (w->height - y)) + w->ray_per_x * 4;
		w->draw_buffer[ offs + 0 ] = (Uint8)(w->wall_buffer[4][offs1 + 0] / 2);
		w->draw_buffer[ offs + 1 ] = (Uint8)(w->wall_buffer[4][offs1 + 1] / 2);
		w->draw_buffer[ offs + 2 ] = (Uint8)(w->wall_buffer[4][offs1 + 2] / 2);
		w->draw_buffer[ offs + 3 ] = (Uint8)(w->wall_buffer[4][offs1 + 3] / 2);
	}
}

void	floor_celing_core(t_wolf *w)
{
	if(w->side == 0 && w->ray_dir_x > 0)
	{
		w->floor_x_wall = w->mapx;
		w->floor_y_wall = w->mapy + w->wall_x;
	}
	else if(w->side == 0 && w->ray_dir_x < 0)
	{
		w->floor_x_wall = w->mapx + 1.0f;
		w->floor_y_wall = w->mapy + w->wall_x;
	}
	else if(w->side == 1 && w->ray_dir_y > 0)
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