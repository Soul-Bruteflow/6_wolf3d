#include "wolf3d.h"

void	screen_size(t_wolf *w, Uint16 width, Uint16 height)
{
	w->width = width;
	w->height = height;
	create_buffer(&w->draw_buffer, width, height);
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
			free(draw_buffer);
			*draw_buffer = (Uint8*)malloc(sizeof(Uint8) * width * height * 4);
			if (*draw_buffer == NULL)
				wolf_error(MALLOCK_ERROR);
		}
	}
}

void	create_screen(t_wolf *w, Uint16 wdth, Uint16 hght, const char *win_name)
{
	screen_size(w, wdth, hght);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		wolf_error(INIT_ERROR);
	w->sdl->window = SDL_CreateWindow(win_name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w->width, w->height, SDL_WINDOW_OPENGL);
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
