# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 23:58:46 by hkhalil           #+#    #+#              #
#    Updated: 2022/10/21 00:00:11 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = rendering_map_2d.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

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