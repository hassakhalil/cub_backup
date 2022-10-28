/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:58:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/28 14:36:31 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main()
{
	t_data *game = malloc(sizeof(t_data));
	game->map = malloc(sizeof(char *)*25);
	game->map_rows = 24;
	game->map_columns = 50;
	game->cube = 32;
	game->window_length = game->map_rows * game->cube;
	game->window_width = game->map_columns * game->cube;
	game->player_x = 4*game->cube + game->cube/2;
	game->player_y = 4*game->cube + game->cube/2;
	game->angle = norm_angle(-M_PI_2);
	game->fov = M_PI/3;
	game->resolution_x = 400;
	game->num_of_rays = game->resolution_x;
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->window_width, game->window_length, "cub3d");
	(game->map)[0] = strdup("11111111111111111111111111111111111111111111111111");
	(game->map)[1] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[2] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[3] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[4] = strdup("1000P011111000010101000000000000000000000000000001");
	(game->map)[5] = strdup("10000010001000000000000000000000000000000000000001");
	(game->map)[6] = strdup("10000010001000010001000000000000000000000000000001");
	(game->map)[7] = strdup("10000010001000000000000000000000000000000000000001");
	(game->map)[8] = strdup("10000011011000010101000000000000000000000000000001");
	(game->map)[9] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[10] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[11] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[12] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[13] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[14] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[15] = strdup("10000000000000000000000000000000000000000000000001");
	(game->map)[16] = strdup("11111111100000000000000000000000000000000000000001");
	(game->map)[17] = strdup("11010000100000000000000000000000000000000000000001");
	(game->map)[18] = strdup("11000110100000000000000000000000000000000000000001");
	(game->map)[19] = strdup("11010000100000000000000000000000000000000000000001");
	(game->map)[20] = strdup("11011111100000000000000000000000000000000000000001");
	(game->map)[21] = strdup("11000000000000000000000000000000000000000000000001");
	(game->map)[22] = strdup("11111111100000000000000000000000000000000000000001");
	(game->map)[23] = strdup("11111111111111111111111111111111111111111111111111");
	(game->map)[24] = NULL;
	
	render(game);
}