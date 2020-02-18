# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lconchit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 19:00:15 by lconchit          #+#    #+#              #
#    Updated: 2020/02/18 20:57:23 by lconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

MLX_HEAD_NAME = mlx.h\
	mlx_new_window.h\
	mlx_int.h

MLX_HEAD = $(addprefix $(MINILIBX_DIR), $(MLX_HEAD_NAME))

SRCS_DIR = ./srcs/
SRCS_NAME = main.c\
	error.c\
	read_map.c\
	memall.c\
	init.c\
	draw_map.c\
	draw_line.c\
	geometry.c\
	transform.c\
	projection.c\
	key_control.c\
	terminator.c\
	support.c
SRC = $(addprefix $(SCS_DIR), $(SRCS_NAME))

OBJ_DIR = ./objects/
OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)
LIBFT_HEAD = $(addprefix $(LIBFT_DIR), libft.h)

MINILIBX_DIR = ./minilibx_macos/
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_HEADERS = $(MINILIBX_DIR)

HEADERS_DIR = ./includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(MLX_HEAD) $(LIBFT_HEAD)
	@make -C $(LIBFT_DIRECTORY)
	$(CC) $(FLAGS) $(SRC) $(INCLUDES)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
 	$(CC) $(FLAGS) -framework OpenGL -framework AppKit $(INCLUDES) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean:
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)

re:
