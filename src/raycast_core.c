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
	int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

	//calculate value of wallX
	double wallX; //where exactly the wall was hit
	if (side == 0) wallX = rayPosY + perpWallDist * rayDirY;
	else           wallX = rayPosX + perpWallDist * rayDirX;
	wallX -= floor((wallX));

	//x coordinate on the texture
	int texX = int(wallX * double(texWidth));
	if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
	if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
}

void	draw_texture(t_wolf *w)
{
	for(int y = drawStart; y<drawEnd; y++)
	{
		int d = y * 256 - h * 128 + lineHeight * 128;  //256 and 128 factors to avoid floats
		int texY = ((d * texHeight) / lineHeight) / 256;
		Uint32 color = texture[texNum][texHeight * texY + texX];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(side == 1) color = (color >> 1) & 8355711;
		buffer[y][x] = color;
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
	}
}