#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_wolf *wolf;

	wolf = NULL;
	wolf = wolf_init(wolf);
	wolf->height = 800;
	wolf->width = 600;
	wolf->win_title = ft_strdup("wolf3d, \0");
	wolf->win_title_update = NULL;
	create_screen(wolf, wolf->height, wolf->width);
	game_loop(wolf);
	quit(wolf);
	return (0);
}