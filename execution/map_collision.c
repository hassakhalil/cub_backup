/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:38:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/30 20:45:58 by hkhalil          ###   ########.fr       */
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
		//debug
		dprintf(2, "flag == 1\n");
		//end debug
		if (M_PI < norm_angle(game->angle) && 1.5*M_PI > norm_angle(game->angle))
		{
			//debug
			dprintf(2, "++++++++++++++++++++++++++++++++++++++++++++\n");
			//end debug
			if ((i + 1) <game->map_rows && (j + 1) < game->map_columns && game->map[(int)(i)][(int)(j+1)] == '1' && game->map[(int)(i+1)][(int)(j)] == '1')
				return(1);
		}
		//else if (M_PI_2 < game->angle && M_PI > game->angle)
		//	if ((i - 1) > 0 && (j - 1) > 0 && game->map[(int)(i-1)][(int)j] == '1' && game->map[(int)i][(int)(j-1)] == '1')
	}
	return (game->map[(int)i][(int)j] - 48);
}