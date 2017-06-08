/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:26:00 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:26:43 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_init_title(t_wolf *w, const char *title)
{
	w->win_title = ft_strdup(title);
	w->win_title_update = NULL;
}

void	screen_size(t_wolf *w, Uint16 width, Uint16 height)
{
	w->width = width;
	w->height = height;
	create_buffer(&w->draw_buffer, width, height);
	screen_title(w);
}

void	create_buffer(Uint8 **draw_buffer, Uint16 width, Uint16 height)
{
	size_t buff_len;
	size_t buf_size;

	if (*draw_buffer == NULL)
	{
		*draw_buffer = (Uint8*)malloc(sizeof(Uint8) * width * height * 4);
		if (*draw_buffer == NULL)
			wolf_error(MALLOCK_ERROR);
	}
	else
	{
		buf_size = sizeof(Uint8) * width * height * 4;
		buff_len = sizeof(draw_buffer) / sizeof(draw_buffer[0]);
		if (buff_len != buf_size)
		{
			free(*draw_buffer);
			*draw_buffer = (Uint8*)malloc(sizeof(Uint8) * width * height * 4);
			if (*draw_buffer == NULL)
				wolf_error(MALLOCK_ERROR);
		}
	}
}

void	screen_title(t_wolf *w)
{
	char *win_width_text;
	char *win_height_text;
	char *win_size_text;

	if (w->win_title_update != NULL)
		free(w->win_title_update);
	win_width_text = ft_itoa(w->width);
	win_height_text = ft_itoa(w->height);
	win_size_text = ft_strcat(win_width_text, "x");
	win_size_text = ft_strcat(win_width_text, win_height_text);
	w->win_title_update = ft_strjoin(w->win_title, win_size_text);
}

void	create_screen(t_wolf *w, Uint16 wdth, Uint16 hght, const char *title)
{
	wolf_init_title(w, title);
	screen_size(w, wdth, hght);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		wolf_error(INIT_ERROR);
	w->sdl->window = SDL_CreateWindow(w->win_title_update,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			w->width, w->height, SDL_WINDOW_OPENGL);
	if (w->sdl->window == NULL)
		wolf_error(WINDOW_ERROR);
	w->sdl->renderer = SDL_CreateRenderer(w->sdl->window, -1,
		SDL_RENDERER_ACCELERATED);
	if (w->sdl->renderer == NULL)
		wolf_error(RENDERER_ERROR);
	w->sdl->screen = SDL_CreateTexture(w->sdl->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
		w->width, w->height);
	if (w->sdl->screen == NULL)
		wolf_error(TEXTURE_ERROR);
}
