/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:38:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/28 01:45:49 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall(t_data *game, double x, double y)
{
	int	i;
	int j;

	if (x < 0 || x > game->window_width || y < 0 || y > game->window_length)
		return (1);
	i = floor(y / game->cube);
	j = floor(x / game->cube);
	//debug
	dprintf(2, "{wall} found------> [ %d ]\n", game->map[(int)i][(int)j] - 48);
	//end debug
	return (game->map[(int)i][(int)j] - 48);
}