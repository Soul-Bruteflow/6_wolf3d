#include "wolf3d.h"

static Uint16	count_symbols(t_wolf *w)
{
	char			*s;
	Uint16			i;

	i = 0;
	s = w->line;
	while (s[i])
	{
		int tmp1 = ft_isalpha(s[i]);
		int tmp2 = ft_isdigit(s[i]);
		if (tmp1 == 0 && tmp2 == 0)
			wolf_error(LINE_ERROR);
		i++;
	}
	return (i);
}

void	parser_first_read(t_wolf *w)
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
