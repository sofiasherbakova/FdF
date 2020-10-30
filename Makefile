# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 13:56:09 by ffood             #+#    #+#              #
#    Updated: 2020/01/29 17:12:29 by bhugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_D = ./src/
SRC =	$(SRC_D)fdf.c \
		$(SRC_D)valid.c \
		$(SRC_D)draw_line.c \
		$(SRC_D)draw_map.c \
		$(SRC_D)rotation.c \
		$(SRC_D)keycode.c \
		$(SRC_D)read_map.c

OBJ_D = ./obj/
OBJ = $(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

LIBFT_D = ./libft/
LIBFT = $(LIBFT_D)libft.a

MLX_D = ./mlx/
MLX = $(MLX_D)libmlx.a

INC_D = ./inc/
INC =	-I$(INC_D) \
		-I$(LIBFT_D) \
		-I$(MLX_D)  

LIB = $(LIBFT) $(MLX) -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

$(MLX):
	make -C $(MLX_D)

$(LIBFT):
	make -C $(LIBFT_D)

$(OBJ_D)%.o : $(SRC_D)%.c
	mkdir -p $(OBJ_D)
	$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	make -C $(LIBFT_D) clean
	make -C $(MLX_D) clean
	/bin/rm -rf $(OBJ_D);

fclean: clean
	make -C $(LIBFT_D) fclean
	make -C $(MLX_D) clean
	/bin/rm -rf $(NAME);

re: fclean all
