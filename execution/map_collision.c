/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:38:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/30 22:35:20 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall(t_data *game, double x, double y, int flag)
{
	int	i;
	int j;
	double	back_angle;
	

	if (flag == 2)
	 	back_angle = norm_angle(game->angle + M_PI);
	else
		back_angle = norm_angle(game->angle);
	if (x < 0 || x > game->window_width || y < 0 || y > game->window_length)
		return (2);
	i = floor(y / game->cube);
	j = floor(x / game->cube);
	if (flag)
	{
		if (M_PI < back_angle && 1.5*M_PI > back_angle)
		{
			if ((i + 1) <game->map_rows && (j + 1) < game->map_columns && game->map[(int)(i)][(int)(j+1)] == '1' && game->map[(int)(i+1)][(int)(j)] == '1')
				return(1);
		}
		else if (1.5*M_PI < back_angle && 2*M_PI > back_angle)
		{
			if ((i + 1) <game->map_rows && (j - 1) < game->map_columns && game->map[(int)(i)][(int)(j-1)] == '1' && game->map[(int)(i+1)][(int)(j)] == '1')
				return(1);
		}
		else if (0 < back_angle && M_PI_2 > back_angle)
		{
			if ((i - 1) <game->map_rows && (j - 1) < game->map_columns && game->map[(int)(i)][(int)(j-1)] == '1' && game->map[(int)(i-1)][(int)(j)] == '1')
				return(1);
		}
		else if (M_PI_2 < back_angle && M_PI > back_angle)
		{
			if ((i - 1) <game->map_rows && (j + 1) < game->map_columns && game->map[(int)(i)][(int)(j+1)] == '1' && game->map[(int)(i-1)][(int)(j)] == '1')
				return(1);
		}
	}
	return (game->map[(int)i][(int)j] - 48);
}