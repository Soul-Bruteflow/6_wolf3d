/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:21:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/01 13:21:43 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <SDL2/SDL.h>

# define MALLOCK_ERROR 0
# define INIT_ERROR 1
# define WINDOW_ERROR 2
# define RENDERER_ERROR 3
# define TEXTURE_ERROR 4

typedef enum		e_bool
{
	false, true
}					t_bool;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*screen;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_wolf
{
	struct s_sdl	*sdl;
	Uint16			width;
	Uint16			height;
	const Uint8		*key_state;
	Uint8			*draw_buffer;
}					t_wolf;

t_wolf				*wolf_init(t_wolf *w);
void				create_screen(t_wolf *w, Uint16 wdth,
					Uint16 hght, const char *win_name);
void				create_buffer(Uint8 **draw_buffer, Uint16 width,
					Uint16 height);
void				screen_size(t_wolf *w, Uint16 width, Uint16 height);

void				quit(t_wolf *wolf);
void				screen_clear(t_wolf *wolf);
void				screen_update(t_wolf *wolf);

void				game_loop(t_wolf *wolf);
t_bool				running(SDL_Event *event, const Uint8 **input_keys);

void				ft_noise(t_wolf *wolf);

void				wolf_error(Uint8 error_code);

void				keyboard_events(t_wolf *w);

#endif
