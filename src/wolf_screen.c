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


	TTF_Init();
	w->font = TTF_OpenFont("Sans.ttf", 20);
	w->white.r = 255;
	w->white.g = 255;
	w->white.b = 255;
	w->message_rect.x = 5;
	w->message_rect.y = 5;
	w->message_rect.w = 40;
	w->message_rect.h = 35;
	w->fps_counter = 0;


	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	w->step_1 = Mix_LoadWAV("pl_metal1.wav");
	w->step_2 = Mix_LoadWAV("pl_metal2.wav");
	w->theme_1 = Mix_LoadMUS("theme.wav");
	w->step = 0;
	w->step_counter = 0;
	w->music_pause_flag = 0;
	Mix_Volume(1,MIX_MAX_VOLUME/20);
	Mix_Volume(2,MIX_MAX_VOLUME/20);
	Mix_VolumeMusic(10);

	w->sdl->window = SDL_CreateWindow(w->win_title_update,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			w->width, w->height, SDL_WINDOW_OPENGL);
	if (w->sdl->window == NULL)
		wolf_error(WINDOW_ERROR);
	w->sdl->renderer = SDL_CreateRenderer(w->sdl->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (w->sdl->renderer == NULL)
		wolf_error(RENDERER_ERROR);
	w->sdl->screen = SDL_CreateTexture(w->sdl->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
		w->width, w->height);
}
