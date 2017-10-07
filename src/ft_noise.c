/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:19:23 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 14:58:47 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** bgra
*/

void	ft_noise(t_wolf *wolf)
{
	Uint16	i;
	Uint16	x;
	Uint16	y;
	Uint32	offset;

	i = 0;
	while (i < 1000)
	{
		x = (Uint16)(rand() % wolf->width);
		y = (Uint16)(rand() % wolf->height);
		offset = (Uint32)((wolf->width * 4 * y) + x * 4);
		wolf->draw_buffer[offset + 0] = (Uint8)(rand() % 256);
		wolf->draw_buffer[offset + 1] = (Uint8)(rand() % 256);
		wolf->draw_buffer[offset + 2] = (Uint8)(rand() % 256);
		wolf->draw_buffer[offset + 3] = SDL_ALPHA_OPAQUE;
		i++;
	}
}
