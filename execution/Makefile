# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 23:58:46 by hkhalil           #+#    #+#              #
#    Updated: 2022/11/09 20:50:44 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = mouse.c clean.c main.c hooks.c map_collision.c render_map.c render_walls.c floor_ceilling.c ray_distance.c angle.c read_texture.c ../parsing/tools/tools1.c  ../parsing/tools/tools2.c ../parsing/tools/tools3.c \
		../parsing/GNL/get_next_line.c  ../parsing/GNL/get_next_line_utils.c ../parsing/errors.c ../parsing/fill.c ../parsing/identifiers_utils.c  ../parsing/identifiers.c \
		../parsing/map_utils.c  ../parsing/map.c ../parsing/parse.c ../parsing/utils.c ../parsing/to_add.c ../parsing/tools/tools4.c ../parsing/utils2.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-O3  -g3  #-fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all