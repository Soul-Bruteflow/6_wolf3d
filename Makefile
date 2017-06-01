# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:24:38 by mvlad             #+#    #+#              #
#    Updated: 2016/12/08 14:24:44 by mvlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)
LIB_LIB = $(LIB_DIR)libft.a

OBJ	=	cntrl_keyboard_core.o \
		cntrl_mouse_core.o \
		fractal_error.o \
		fractal_mlx.o \
		fractal_put_pixel.o \
		fractal_ui.o \
		ft_hsv_to_rgb.o \
		hsv_color.o \
		julia_core.o \
		julia_worker.o \
		main.o \
		mandelbrot_core.o \
		mandelbrot_worker.o \
		ship_core.o \
		ship_worker.o \
		threads_core.o

LIB = $(LIB_DIR)libft.a

HEADERS	= $(INC_DIR)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -lmlx -framework OpenGL -framework AppKit
INC_OPT = -I $(LIB_INC) -I $(INC_DIR)
OUT_OPT = -o
OBJ_OPT = $< -o $@
LIB_OPT	= -c

RMF 	= rm -f

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(LIB_OPT) $(OBJ_OPT) $(INC_OPT)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(MAKE) -C ./libft/
	$(CC) $(MLX) $(CFLAGS) $(LIB_LIB) $^ $(OUT_OPT) $(NAME)

clean:
	$(RMF) $(addprefix $(OBJ_DIR), $(OBJ))
	cd $(LIB_DIR) && $(MAKE) clean

fclean: clean
	$(RMF) $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean

re: fclean all
	cd $(LIB_DIR) && $(MAKE) re
