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

void	raycast_core(t_wolf *w)
{
	w->ray_per_x = -1;
	while (w->ray_per_x++ <= w->width)
	{
		ray_init(w);
	}
}