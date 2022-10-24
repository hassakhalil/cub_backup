/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:38:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/25 00:39:30 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall(t_data *game, int keycode)
{
	double	tmp_x;
	double	tmp_y;
	int		i;
	int		j;

	if (keycode == 126)
	{
			tmp_x = game->player_x + 8*cos(game->angle);
			tmp_y = game->player_y + 8*sin(game->angle);
	}
	else if (keycode == 125)
	{
			tmp_x = game->player_x - 8*cos(game->angle);
			tmp_y = game->player_y - 8*sin(game->angle);
	}
	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_columns)
		{
			if (((tmp_x >= j*game->cube) && (tmp_x <= (j+1)*game->cube)) && ((tmp_y >= i*game->cube) && (tmp_y <= (i+1)*game->cube)))
			{
				if (game->map[i][j] == '1')
					return (1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (0);	
}