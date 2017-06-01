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

typedef enum		e_bool
{
	false, true
}					t_bool;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture* 	screen;
	SDL_Event 		event;
}					t_sdl;

typedef struct		s_wolf
{
	struct s_sdl	*sdl;
	uint16_t		width;
	uint16_t		height;
	uint8_t			input_keys;
	uint8_t			*pixels;
}					t_wolf;

#endif
