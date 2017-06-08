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
	char 			*win_title;
	char 			*win_title_update;
	const Uint8		*key_state;
	Uint8			*draw_buffer;
	
	Uint16			map_width;
	Uint16 			map_height;
	float 			pos_x;
	float 			pos_y;
	float 			dir_x;
	float 			dir_y;
	float 			plane_x;
	float			plane_y;
	float 			time;
	float 			old_time;
}					t_wolf;

/*
** Init
*/
t_wolf				*wolf_init(t_wolf *w, Uint16 width, Uint16 height,
					const char *title);
void				create_screen(t_wolf *w, Uint16 wdth, Uint16 hght,
					const char *title);
void				create_buffer(Uint8 **draw_buffer, Uint16 width,
					Uint16 height);
void				screen_size(t_wolf *w, Uint16 width, Uint16 height);
void				screen_title(t_wolf *w);
void				wolf_init_title(t_wolf *w, const char *title);
/*
** Game loop.
*/
void				game_loop(t_wolf *wolf);
t_bool				running(SDL_Event *event, const Uint8 **input_keys);
void				quit(t_wolf *wolf);
void				world_clear(t_wolf *wolf);
void				world_update(t_wolf *wolf);
void				world_render(t_wolf *w);
/*
** Effects.
*/
void				ft_noise(t_wolf *wolf);
/*
** Error management.
*/
void				wolf_error(Uint8 error_code);
/*
** Keyboard.
*/
void				get_user_inputs(t_wolf *w);

#endif
