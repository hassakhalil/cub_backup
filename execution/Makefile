# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 23:58:46 by hkhalil           #+#    #+#              #
#    Updated: 2022/11/10 10:14:38 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BNAME = bonus

SRC =  draw_utils.c game_init.c hor_distance.c ver_distance.c clean.c main.c hooks.c map_collision.c render_walls.c floor_ceilling.c ray_distance.c angle.c read_texture.c ../parsing/tools/tools1.c  ../parsing/tools/tools2.c ../parsing/tools/tools3.c \
		../parsing/GNL/get_next_line.c  ../parsing/GNL/get_next_line_utils.c ../parsing/errors.c ../parsing/fill.c ../parsing/identifiers_utils.c  ../parsing/identifiers.c \
		../parsing/map_utils.c  ../parsing/map.c ../parsing/parse.c ../parsing/utils.c ../parsing/to_add.c ../parsing/tools/tools4.c ../parsing/utils2.c
BSRC = draw_utils.c render_map_bonus.c mouse_bonus.c main_bonus.c hooks_bonus.c game_init_bonus.c hor_distance.c ver_distance.c clean.c map_collision.c render_walls.c floor_ceilling.c ray_distance.c angle.c read_texture.c ../parsing/tools/tools1.c  ../parsing/tools/tools2.c ../parsing/tools/tools3.c \
		../parsing/GNL/get_next_line.c  ../parsing/GNL/get_next_line_utils.c ../parsing/errors.c ../parsing/fill.c ../parsing/identifiers_utils.c  ../parsing/identifiers.c \
		../parsing/map_utils.c  ../parsing/map.c ../parsing/parse.c ../parsing/utils.c ../parsing/to_add.c ../parsing/tools/tools4.c ../parsing/utils2.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-O3  -g3  #-fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

$(BNAME) : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -I -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all