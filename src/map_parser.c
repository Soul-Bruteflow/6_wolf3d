#include "wolf3d.h"

void	map_parser(t_wolf *w)
{
	parser_first_read(w);
	w->map_height = w->map_y;
	w->map_width = w->map_x;
	w->world_map = (Uint8**)ft_malloc_2d_array(sizeof(w->world_map),
											   w->map_width, w->map_height);
	w->map_height -= 1;
	w->map_width -= 1;
	parser_second_read(w);
	if (parser_final_validation(w) == false)
		exit (0);

//	int y = 0;
//	int x = 0;
//	while (y < 30)
//	{
//		x = 0;
//		while (x < 30)
//		{
//			printf("%d", w->world_map[y][x]);
//			x++;
//		}
//		printf("\n");
//		y++;
//	}
}