#include "wolf3d.h"

void	map_parser(t_wolf *w)
{
	parser_first_read(w);
	parser_second_read(w);
	w->world_map = (Uint8**)ft_malloc_2d_array(sizeof(w->world_map), w->map_x, w->map_y);
}