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
	SDL_Texture		*screen;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_wolf
{
	struct s_sdl	*sdl;
	Uint16			width;
	Uint16			height;
	const Uint8		*key_state;
	Uint8			*pixels;
}					t_wolf;

t_bool				running(SDL_Event *event, const Uint8 *input_keys);

#endif
