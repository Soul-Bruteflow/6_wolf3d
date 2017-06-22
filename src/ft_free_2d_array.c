#include <stdlib.h>
#include "wolf3d.h"

void	ft_free_2d_array(void **array, size_t y)
{
	size_t i;

	i = 0;
	while (i < y)
	{
		free(array[i]);
		i++;
	}
	free(array);
}