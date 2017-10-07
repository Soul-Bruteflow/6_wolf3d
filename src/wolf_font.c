/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:38:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/07 16:12:58 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_font_init(t_wolf *w)
{
	TTF_Init();
	w->font = TTF_OpenFont("./resources/fonts/Sans.ttf", 20);
	w->white.r = 255;
	w->white.g = 255;
	w->white.b = 255;
	w->message_rect.x = 5;
	w->message_rect.y = 5;
	w->message_rect.w = 40;
	w->message_rect.h = 35;
	w->fps_counter = 0;
}
