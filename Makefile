# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruteflow <bruteflow@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:24:38 by mvlad             #+#    #+#              #
#    Updated: 2017/06/26 11:36:17 by bruteflow        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= wolf3d
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
FRM_DIR	= ./frameworks/
SDL_INC	= $(FRM_DIR)SDL2.framework/Versions/A/Headers
SDL_TTF = $(FRM_DIR)SDL2_ttf.framework/Versions/A/Headers
SDL_IMG = $(FRM_DIR)SDL2_image.framework/Versions/A/Headers
SDL_MIX = $(FRM_DIR)SDL2_mixer.framework/Versions/A/Headers
LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)
LIB_LIB = $(LIB_DIR)libft.a

OBJ	=	floor_ceiling_core.o \
		ft_free_2d_array.o \
		ft_malloc_2d_array.o \
		ft_noise.o \
		ft_xor_swap.o \
		game_loop.o \
		get_next_line.o \
		get_user_inputs.o \
		main.o \
		map_parser.o \
		parser_final_validation.o \
		parser_first_read.o \
		parser_second_read.o \
		parser_support.o \
		raycast_core.o \
		texture_core.o \
		wolf_audio.o \
		wolf_draw_lines.o \
		wolf_error.o \
		wolf_font.o \
		wolf_init.o \
		wolf_movement.o \
		wolf_screen.o \
		wolf_sound_movement.o \
		wolf_world.o

LIB = $(LIB_DIR)libft.a

HEADERS	= $(INC_DIR)

# -lmlx -framework OpenGL -framework AppKit
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SDL		= -F $(FRM_DIR) -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer
INC_OPT = -I $(LIB_INC) -I $(INC_DIR) -I $(SDL_INC) -I $(SDL_TTF) -I $(SDL_IMG) -I $(SDL_MIX)
OUT_OPT = -o
OBJ_OPT = $< -o $@
LIB_OPT	= -c

RMF 	= rm -f

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(LIB_OPT) $(OBJ_OPT) $(INC_OPT)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(MAKE) -C ./libft/
	$(CC) $(CFLAGS) $(SDL) $(LIB_LIB) $^ $(OUT_OPT) $(NAME)

clean:
	$(RMF) $(addprefix $(OBJ_DIR), $(OBJ))
	cd $(LIB_DIR) && $(MAKE) clean

fclean: clean
	$(RMF) $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean

re: fclean all
	cd $(LIB_DIR) && $(MAKE) re
