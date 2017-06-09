#include "wolf3d.h"

/*
** fdf_close_file
** Closes the file, and checks for the errors.
*/

void	close_file(t_wolf *w)
{
	if ((close(w->fd)) < 0)
		wolf_error(FILE_CLOSE_ERROR);
}

/*
** fdf_close_line
** Closes the file on the line error, and checks for the errors.
*/

void	close_line(t_wolf *w)
{
	if (w->tmp != w->map_x)
	{
		close_file(w);
		wolf_error(LINE_ERROR);
	}
}

/*
** fdf_open_file
** Opens the file, and checks for the errors.
*/

void	open_file(t_wolf *w)
{
	w->fd = open(w->av[1], O_RDONLY);
	if (w->fd < 0)
		wolf_error(FILE_OPEN_ERROR);
}

/*
** fdf_gnl_error
** Checks for the GNL errors.
*/

void	gnl_error(t_wolf *w, int i)
{
	if (i < 0)
	{
		close_file(w);
		wolf_error(GNL_ERROR);
	}
}

/*
** fdf_gnl_error
** Errors for the number of the sequential symbols.
*/

void	nbr_error(t_wolf *w, Uint16 i)
{
	if (i == 0)
	{
		close_file(w);
		wolf_error(EMPTY_MAP_ERROR);
	}
	else if (w->map_x < 7 || w->map_y < 7)
	{
		close_file(w);
		wolf_error(SMALL_MAP_ERROR);
	}
	else if (w->map_x >= 100 || w->map_y >= 100)
	{
		close_file(w);
		wolf_error(BIG_MAP_ERROR);
	}
}