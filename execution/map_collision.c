/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:38:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/31 01:35:13 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall(t_data *game, double x, double y, int flag)
{
	int	i;
	int j;
	

	if (x < 0 || x > game->window_width || y < 0 || y > game->window_length)
		return (2);
	i = floor(y / game->cube);
	j = floor(x / game->cube);
	if (flag)
	{
		//check x vector
		if (wall(game, x, game->player_y, 0) == 1)
			return (1);
		//check y vector
		if (wall(game, game->player_x, y, 0) == 1)
			return (1);
	}
	return (game->map[(int)i][(int)j] - 48);
}