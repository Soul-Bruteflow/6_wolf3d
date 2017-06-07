#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_wolf *wolf;

	wolf = NULL;
	wolf = wolf_init(wolf);
	wolf_init_sdl(wolf);
	game_loop(wolf);
	quit(wolf);
	return (0);
}