#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_wolf *wolf;

	wolf = NULL;
	wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
	game_loop(wolf);
	quit(wolf);
	return (0);
}