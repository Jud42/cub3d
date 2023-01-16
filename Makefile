# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 18:02:56 by rmamison          #+#    #+#              #
#    Updated: 2022/10/04 17:10:56 by rmamison         ###   ########.fr        #
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


SRCS = $(addprefix srcs/, $(SRC))

ifeq ($(shell uname -s), Linux)
	INCLUDE = -Iincludes -Imlx_linux -Ilibft -I/usr/include
	LIB = -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz libft/libft.a
else
	INCLUDE = -Iincludes -Iminilibx -Ilibft
	LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit libft/libft.a
endif 

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
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
	@make -C libft
	@echo "Compiling cub3d..."
	@$(CC) $(FLAGS) $(OB) $(LIB) -o $@
	@echo "Compilation [cub3d] is done!"

clean :
	@echo "Remove all file_object..."
	@$(RM) $(DIR)
	@make clean -C libft
	@echo "file_object removed!"

fclean : clean
	@echo "Remove all file_object & file_binary..."
	@$(RM) $(NAME)
	@make fclean -C libft
	@echo "object and binary_file removed!"

re : fclean $(NAME)
.PHONY: all clean fclean re
