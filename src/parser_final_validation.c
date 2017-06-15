#include "wolf3d.h"

t_bool	border_run(Uint16 start_x, Uint16 start_y, Uint16 end_x, Uint16 end_y, t_wolf *w)
{
	if (start_x == end_x)
	{
		while (start_y <= end_y)
		{
			if (w->world_map[start_y][start_x] != 1)
				return (false);
			start_y++;
		}
	}
	else if (start_y == end_y)
	{
		while (start_x <= end_x)
		{
			if (w->world_map[start_y][start_x] != 1)
				return (false);
			start_x++;
		}
	}
	return (true);
}

t_bool	validate_borders(t_wolf *w)
{
	if (!border_run(0, 0, w->map_width, 0, w))
		return (false);
	if (!border_run(0, 1, 0, w->map_height, w))
		return (false);
	if (!border_run(1, w->map_height, w->map_width, w->map_height, w))
		return (false);
	if (!border_run(w->map_width, 1, w->map_width, (Uint16)(w->map_height - 1), w))
		return (false);
	return (true);
}

t_bool	validate_center(t_wolf *w)
{
	return (true);
}

t_bool	parser_final_validation(t_wolf *w)
{
	if (!validate_borders(w))
		return (false);
	if (!validate_center(w))
		return (false);
	else
		return (true);
}