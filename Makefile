# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lconchit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:15:44 by lconchit          #+#    #+#              #
#    Updated: 2020/02/19 19:20:54 by lconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3

# sources files
SRCS_DIR = ./srcs/
SRCS_NAME = draw_line.c	\
	draw_map.c			\
	error.c				\
	geometry.c			\
	init.c				\
	key_control.c		\
	main.c				\
	memall.c			\
	projection.c		\
	read_map.c			\
	support.c			\
	terminator.c		\
	transform.c
SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))

# objects files
OBJS_DIR = obj/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR),$(OBJS_NAME))

# includes
INCLUDES_FDF_DIR = ./includes/
INCLUDES_FDF_NAME = fdf.h

# libft
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_NAME))
LIBFT_FLAGS = -lft -L$(LIBFT_DIR)

# mlx
MLX_DIR = ./minilibx_macos/
MLX_NAME = libmlx.a
MLX = $(addprefix $(MLX_DIR),$(MLX_NAME))
MLX_FLAGS = -lmlx -lm -L$(MLX_DIR) -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR) $(MLX_DIR)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -I$(INCLUDES_FDF_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INCLUDES_FDF_DIR) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@/bin/rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
re: fclean all
