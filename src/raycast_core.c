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
		if (w->world_map[w->mapx][w->mapy] > 0) w->hit = 1;
	}
}

void	final_calculations(t_wolf *w)
{
	if (w->side == 0)
		w->perp_wall_dist = (w->mapx - w->ray_pos_x + (1 - w->step_x) / 2) / w->ray_dir_x;
	else
		w->perp_wall_dist = (w->mapy - w->ray_pos_y + (1 - w->step_y) / 2) / w->ray_dir_y;
	w->line_height = (int)(w->height / w->perp_wall_dist);
	w->draw_start = -w->line_height / 2 + w->height / 2;
	if(w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_height / 2 + w->height / 2;
	if(w->draw_end >= w->height)
		w->draw_end = w->height - 1;
}

void	wolf_color_core(t_wolf *w)
{
	t_rgb color;
	color.r = 255;
	color.g = 0;
	color.b = 0;
	if (w->side == 1)
	{
		color.r /= 2;
		color.g /= 2;
		color.b /= 2;
	}
	verLine(w->ray_per_x, w->draw_start, w->draw_end, color, w, w->width, w->height);
}

void	wolf_texture_core(t_wolf *w)
{
	//texturing calculations
	w->tex_num = w->world_map[w->mapx][w->mapy] - 1; //1 subtracted from it so that texture 0 can be used!

	//calculate value of wallX
//	double wallX; //where exactly the wall was hit
	if (w->side == 0)
		w->wall_x = w->ray_pos_y + w->perp_wall_dist * w->ray_dir_y;
	else
		w->wall_x = w->ray_pos_x + w->perp_wall_dist * w->ray_dir_x;
	w->wall_x -= floorf(w->wall_x);

	//x coordinate on the texture
	w->tex_x = (int)(w->wall_x * TEX_WIDTH);
	if(w->side == 0 && w->ray_dir_x > 0)
		w->tex_x = TEX_WIDTH - w->tex_x - 1;
	if(w->side == 1 && w->ray_dir_y < 0)
		w->tex_x = TEX_WIDTH - w->tex_x - 1;
}

void	draw_texture(t_wolf *w)
{
	for(int y = w->draw_start; y < w->draw_end; y++)
	{
//		int d = y * 256 - w->height * 128 + w->line_height * 128;  //256 and 128 factors to avoid floats
//		w->tex_y = ((d * TEX_HEIGHT) / w->line_height) / 256;

		w->tex_y = (int)((y - 600 * 0.5 + w->line_height * 0.5) * 128) / w->line_height;


		unsigned int offs = (unsigned int)(800 * 4 * y) + w->ray_per_x * 4;
		unsigned int offs1 = (unsigned int)(128 * 4 * w->tex_y) + w->tex_x * 4;

		if(w->side == 1)
		{
			w->draw_buffer[ offs + 0 ] = (Uint8)(w->wall_buffer[w->tex_num][offs1 + 0] / 2);	// b
			w->draw_buffer[ offs + 1 ] = (Uint8)(w->wall_buffer[w->tex_num][offs1 + 1] / 2);	// g
			w->draw_buffer[ offs + 2 ] = (Uint8)(w->wall_buffer[w->tex_num][offs1 + 2] / 2);	// r
			w->draw_buffer[ offs + 3 ] = (Uint8)(w->wall_buffer[w->tex_num][offs1 + 3] / 2);	// a
		}
		else
		{
			w->draw_buffer[ offs + 0 ] = w->wall_buffer[w->tex_num][offs1 + 0];	// b
			w->draw_buffer[ offs + 1 ] = w->wall_buffer[w->tex_num][offs1 + 1];	// g
			w->draw_buffer[ offs + 2 ] = w->wall_buffer[w->tex_num][offs1 + 2];	// r
			w->draw_buffer[ offs + 3 ] = w->wall_buffer[w->tex_num][offs1 + 3];	// a
		}
	}
}

void	floor_and_ceeling(t_wolf *w)
{
	//FLOOR CASTING
	double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

	//4 different wall directions possible
	if(w->side == 0 && w->ray_dir_x > 0)
	{
		floorXWall = w->mapx;
		floorYWall = w->mapy + w->wall_x;
	}
	else if(w->side == 0 && w->ray_dir_x < 0)
	{
		floorXWall = w->mapx + 1.0;
		floorYWall = w->mapy + w->wall_x;
	}
	else if(w->side == 1 && w->ray_dir_y > 0)
	{
		floorXWall = w->mapx + w->wall_x;
		floorYWall = w->mapy;
	}
	else
	{
		floorXWall = w->mapx + w->wall_x;
		floorYWall = w->mapy + 1.0;
	}

	double distWall, distPlayer, currentDist;

	distWall = w->perp_wall_dist;
	distPlayer = 0.0;

	if (w->draw_end < 0) w->draw_end = w->height; //becomes < 0 when the integer overflows

	//draw the floor from drawEnd to the bottom of the screen
	for(int y = w->draw_end + 1; y < w->height; y++)
	{
		currentDist = w->height / (2.0 * y - w->height); //you could make a small lookup table for this instead

		double weight = (currentDist - distPlayer) / (distWall - distPlayer);

		double currentFloorX = weight * floorXWall + (1.0 - weight) * w->pos_x;
		double currentFloorY = weight * floorYWall + (1.0 - weight) * w->pos_y;

		int floorTexX, floorTexY;
		floorTexX = (int)(currentFloorX * TEX_WIDTH) % TEX_WIDTH;
		floorTexY = (int)(currentFloorY * TEX_HEIGHT) % TEX_HEIGHT;

		unsigned int offs = (unsigned int)(800 * 4 * y) + w->ray_per_x * 4;
		unsigned int offs1 = (unsigned int)(128 * 4 * floorTexY) + floorTexX * 4;

		w->draw_buffer[ offs + 0 ] = (Uint8)(w->wall_buffer[3][offs1 + 0] / 2);	// b
		w->draw_buffer[ offs + 1 ] = (Uint8)(w->wall_buffer[3][offs1 + 1] / 2);	// g
		w->draw_buffer[ offs + 2 ] = (Uint8)(w->wall_buffer[3][offs1 + 2] / 2);	// r
		w->draw_buffer[ offs + 3 ] = (Uint8)(w->wall_buffer[3][offs1 + 3] / 2);	// a

		offs = (unsigned int)(800 * 4 * (w->height - y)) + w->ray_per_x * 4;
		w->draw_buffer[ offs + 0 ] = (Uint8)(w->wall_buffer[4][offs1 + 0] / 2);	// b
		w->draw_buffer[ offs + 1 ] = (Uint8)(w->wall_buffer[4][offs1 + 1] / 2);	// g
		w->draw_buffer[ offs + 2 ] = (Uint8)(w->wall_buffer[4][offs1 + 2] / 2);	// r
		w->draw_buffer[ offs + 3 ] = (Uint8)(w->wall_buffer[4][offs1 + 3] / 2);	// a
	}
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
//		wolf_color_core(wolf);
		wolf_texture_core(wolf);
		draw_texture(wolf);
		floor_and_ceeling(wolf);
	}
}