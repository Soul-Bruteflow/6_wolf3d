#include "wolf3d.h"

static Uint16	count_symbols(t_wolf *w)
{
	char			*s;
	Uint16			i;
	Uint16			nbr;

	i = 0;
	nbr = 0;
	s = w->line;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			nbr++;
		i++;
	}
	return (nbr);
}

void	map_parser(t_wolf *w)
{
	int i;

	w->map_x = 0;
	w->map_y = 0;
	open_file(w);
	while ((i = get_next_line(w->fd, &w->line)) == 1)
	{
		if (w->map_x == 0)
		{
			w->map_x = count_symbols(w);
			free(w->line);
			w->map_y++;
			continue;
		}
		w->tmp = count_symbols(w);
		free(w->line);
		w->map_y++;
		close_line(w);
	}
	gnl_error(w, i);
	nbr_error(w, w->map_x);
	close_file(w);
}