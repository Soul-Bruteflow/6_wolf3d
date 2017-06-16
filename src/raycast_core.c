#include "wolf3d.h"

void	ray_init(t_wolf *w)
{
	w->camera_x = 2 * w->ray_per_x / w->width - 1;
	w->ray_pos_x = w->pos_x;
	w->ray_pos_y = w->pos_y;
	w->ray_dir_x = w->dir_x + w->plane_y * w->camera_x;
	w->ray_dir_x = w->dir_y + w->plane_y * w->camera_x;
	//which box of the map we're in

	w->mapx = (int)w->ray_pos_x;
	w->mapy = (int)w->ray_pos_y;

	//length of ray from one x or y-side to next x or y-side
	w->sqr_ray_dir_y = w->ray_dir_y * w->ray_dir_y;
	w->sqr_ray_dir_x = w->ray_dir_x * w->ray_dir_x;
	w->delta_dist_x = sqrtf(1 + (w->sqr_ray_dir_y) / (w->sqr_ray_dir_x));
	w->delta_dist_y = sqrtf(1 + (w->sqr_ray_dir_x) / (w->sqr_ray_dir_y));
	w->perp_wall_dist = 0;

	//length of ray from current position to next x or y-side
	w->side_dist_x;
	w->side_dist_y;

	//what direction to step in x or y-direction (either +1 or -1)
	w->step_x;
	w->step_y;

	w->hit = 0; //was there a wall hit?
	w->side; //was a NS or a EW wall hit?
}

void	step_init(t_wolf *w)
{
	if (w->ray_dir_y < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (w->ray_dir_x - w->mapx) * w->delta_dist_x;
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
	//perform DDA
	while (w->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->side_dist_x;
			w->mapx += w->step_x;
			w->side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->mapy += w->step_y;
			w->side = 1;
		}
		//Check if ray has hit a wall
		if (w->world_map[w->mapx][w->mapy] > 0)
			w->hit = 1;
	}
}

void	final_calculations(t_wolf *w)
{
	//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
	if (w->side == 0)
		w->perp_wall_dist = (w->mapx - w->ray_pos_x + (1 - w->step_x) / 2) / w->ray_dir_x;
	else
		w->perp_wall_dist = (w->mapy - w->ray_pos_y + (1 - w->step_y) / 2) / w->ray_dir_y;

	//Calculate height of line to draw on screen
	w->lineheight = (int)(w->height / w->perp_wall_dist);

	//calculate lowest and highest pixel to fill in current stripe
	w->draw_start = - w->lineheight / 2 + w->height / 2;
	if(w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->lineheight / 2 + w->height / 2;
	if(w->draw_end >= w->height)
		w->draw_end = w->height - 1;
}

void	wolf_color_core(t_wolf *w)
{
	//choose wall color
	t_rgb color;
	switch(w->world_map[w->mapx][w->mapy])
	{
		case 1:
			color.r = 255;
			color.g = 0;
			color.b = 0;
			break; //red
		case 2:
			color.r = 0;
			color.g = 255;
			color.b = 0;
			break; //green
		case 3:
			color.r = 0;
			color.g = 0;
			color.b = 255;
			break;
		case 4:
			color.r = 255;
			color.g = 255;
			color.b = 255;
			break; //white
		default:
			color.r = 255;
			color.g = 255;
			color.b = 0;
			break; //yellow
	}

	//give x and y sides different brightness
	if (w->side == 1)
	{
		color.r /= 2;
		color.g /= 2;
		color.b /= 2;
	}

	//draw the pixels of the stripe as a vertical line
	verLine(w->ray_per_x, w->draw_start, w->draw_end, color, w);
}

void	raycast_core(t_wolf *w)
{
	w->ray_per_x = -1;
	while (w->ray_per_x++ < w->width)
	{
		ray_init(w);
		step_init(w);
		wolf_dda(w);
		final_calculations(w);
		wolf_color_core(w);
	}
}