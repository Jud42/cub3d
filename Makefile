# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:23:26 by Blaze             #+#    #+#              #
#    Updated: 2023/01/18 20:23:37 by Blaze            ###    42Lausanne.ch     #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC =	main.c \
	tab_create.c \
	init_struct.c \
	utils.c	\
	take_color_map.c \
	manage_error/mng_error.c \
	manage_error/update_map.c \
	manage_error/parse_map.c \
	clean.c \
	draw.c \
	ray.c \
	event.c \
	event2.c \

libft_DIR = ./lib/libft
SRCS = $(addprefix srcs/, $(SRC))

UNAME= $(shell uname -s)
ifeq ($(uname), Linux)
		mlx_DIR = ./lib/mlx/linux
		mlx_FLAGS += -lmlx -lX11 -lXext -lm -lz
else
		mlx_DIR = ./lib/mlx
		mlx_FLAGS += -lmlx -lm -framework OpenGL -framework AppKit
endif

FLAGS = -Wall -Wextra -Werror
CC = gcc

RM = rm -rf

DIR = file_object
OB = $(addprefix $(DIR)/, $(SRCS:%.c=%.o))
CLONE = file_object \
	file_object/srcs \
	file_object/srcs/manage_error \

$(DIR)/%.o : %.c
	@mkdir -p $(CLONE)
	@$(CC) $(INCLUDE) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OB)
	@make -C $(libft_DIR)
	@make -C $(mlx_DIR)
	@echo "Compiling cub3d..."
	@$(CC) $(FLAGS) -lft -L$(libft_DIR) -L$(mlx_DIR) $(mlx_FLAGS) $(OB) $(LIB) -o $@
	@echo "Compilation [cub3d] is done!"

clean :
	@echo "Remove all file_object..."
	@$(RM) $(DIR)
	@make clean -C $(libft_DIR)
	@echo "file_object removed!"

fclean : clean
	@echo "Remove all file_object & file_binary..."
	@$(RM) $(NAME)
	@echo "object and binary_file removed!"

debug: FLAGS += -g3 -D DEBUG=1
debug: all
asan: FLAGS += -g3 -fsanitize=address -fno-omit-frame-pointer
asan: all

re : fclean $(NAME)
.PHONY: all clean fclean re debug asan
