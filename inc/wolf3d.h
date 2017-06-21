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
# include <SDL2_image/SDL_image.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_mixer/SDL_mixer.h>

/*
** SDL
*/
# define MALLOCK_ERROR 0
# define INIT_ERROR 1
# define WINDOW_ERROR 2
# define RENDERER_ERROR 3
# define TEXTURE_ERROR 4
# define TEX_WIDTH 128
# define TEX_HEIGHT 128
# define TEX_NBR 10

/*
** Parser
*/
# define FILE_CLOSE_ERROR 20
# define FILE_OPEN_ERROR 21
# define GNL_ERROR 22
# define EMPTY_MAP_ERROR 23
# define SMALL_MAP_ERROR 24
# define BIG_MAP_ERROR 25
# define LINE_ERROR 26

Uint32 buffer[600][800];

/*
** General
*/
# define USSAGE_ERROR 40

typedef enum		e_bool
{
	false, true
}					t_bool;

typedef struct		s_rgb
{
	Uint8			r;
	Uint8			g;
	Uint8			b;
}					t_rgb;

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
	Uint16			map_x;
	Uint16			map_y;
	Uint16			map_center_x;
	Uint16			map_center_y;
	char			*line;
	int 			fd;
	Uint16			tmp;
	char			**av;
	Uint16			map_width;
	Uint16 			map_height;
	Uint16			map_size_y;
	Uint16 			map_size_x;
	Uint8			**world_map;
	float 			pos_x;
	float 			pos_y;
	float 			dir_x;
	float 			dir_y;
	float 			plane_x;
	float			plane_y;
	float 			time;
	float 			old_time;
	float 			frame_time;
	int				ray_per_x;
	float			camera_x;
	float 			ray_pos_x;
	float 			ray_pos_y;
	float 			ray_dir_x;
	float 			ray_dir_y;
	int 			mapx;
	int 			mapy;
	float 			side_dist_x;
	float 			side_dist_y;
	float 			delta_dist_x;
	float 			delta_dist_y;
	float 			perp_wall_dist;
	int 			step_x;
	int 			step_y;
	int 			hit;
	int 			side;
	float 			sqr_ray_dir_y;
	float 			sqr_ray_dir_x;
	int				draw_start;
	int 			line_height;
	int 			draw_end;
	float 			move_speed;
	float 			rot_speed;
	float 			camera_y;
	float			ray_per_y;
	int				linewidth;
	int 			pitch;
	size_t			offset;
	size_t			old_offset;
	float			old_dir_x;
	float 			old_plane_x;

	int 			tex_num;
	float 			wall_x;
	int 			tex_x;
	int 			tex_y;

	SDL_Surface		**walls;
	Uint8			**wall_buffer;
	int 			wall_pitch;
	int 			wall_height;
	int 			wall_width;

	TTF_Font 		*font;
	SDL_Color 		white;
	SDL_Surface		*sur_message;
	SDL_Texture		*tex_message;
	SDL_Rect 		message_rect;
	char			fps[4];
	int 			fps_counter;
	Mix_Chunk		*step_1;
	Mix_Chunk		*step_2;
	Mix_Music		*theme_1;
	int 			step;
	int				step_counter;
	int 			music_pause_flag;
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
** Raycasting
*/
void				raycast_core(t_wolf *w);
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
/*
** Parser.
*/
void				map_parser(t_wolf *w);
void				close_file(t_wolf *w);
void				close_line(t_wolf *w);
void				open_file(t_wolf *w);
void				gnl_error(t_wolf *w, int i);
void				nbr_error(t_wolf *w, Uint16 i);
void				parser_first_read(t_wolf *w);
void				parser_second_read(t_wolf *w);
t_bool				parser_final_validation(t_wolf *w);
/*
** Support
*/
void				**ft_malloc_2d_array(Uint8 type_size, size_t x, size_t y);
void				ft_free_2d_array(void **array, size_t y);
void 				ft_xor_swap(int *a, int *b);
/*
**
*/
t_bool 				verLine(int x, int y1, int y2, t_rgb color, t_wolf *wolf, int w, int h);


void	tmp(t_wolf *w);

/*
** Textures
*/
void	texture_core(t_wolf *w);
#endif
