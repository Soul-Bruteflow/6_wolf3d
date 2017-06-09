#include "wolf3d.h"

void	**ft_malloc_2d_array(Uint8 type_size, size_t x, size_t y)
{
	size_t	i;
	void	**tmp_aray;

	tmp_aray = malloc(sizeof(void*) * y);
	if (tmp_aray == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		tmp_aray[i] = malloc(type_size * x);
		if (tmp_aray[i] == NULL)
			return (NULL);
		i++;
	}
	return (tmp_aray);
}