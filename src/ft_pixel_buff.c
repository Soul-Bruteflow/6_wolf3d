/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:54:57 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/10 14:25:22 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_pixel_buff(t_wolf *w, unsigned int off,
	unsigned int off1, unsigned int i)
{
	if (off1 >= 0 && off1 <= ((TEX_WIDTH - 1) * (TEX_WIDTH - 1) * BITS)
	&& off >= 0 && off <= ((WIDTH - 1) * (HEIGHT - 1) * BITS))
	{
		w->draw_buffer[off + 0] = w->wall_buffer[i][off1 + 0];
		w->draw_buffer[off + 1] = w->wall_buffer[i][off1 + 1];
		w->draw_buffer[off + 2] = w->wall_buffer[i][off1 + 2];
		w->draw_buffer[off + 3] = w->wall_buffer[i][off1 + 3];
	}
}

void	ft_pixel_buff_shade(t_wolf *w, unsigned int off,
	unsigned int off1, unsigned int i)
{
	if (off1 >= 0 && off1 <= ((TEX_WIDTH - 1) * (TEX_WIDTH - 1) * BITS)
	&& off >= 0 && off <= ((WIDTH - 1) * (HEIGHT - 1) * BITS))
	{
		w->draw_buffer[off + 0] =
		(Uint8)(w->wall_buffer[i][off1 + 0] / 2);
		w->draw_buffer[off + 1] =
		(Uint8)(w->wall_buffer[i][off1 + 1] / 2);
		w->draw_buffer[off + 2] =
		(Uint8)(w->wall_buffer[i][off1 + 2] / 2);
		w->draw_buffer[off + 3] =
		(Uint8)(w->wall_buffer[i][off1 + 3] / 2);
	}
}
