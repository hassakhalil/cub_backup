/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:35:06 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/26 09:18:41 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double norm_angle(double angle)
{
	angle =  remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = 2*M_PI + angle;
	return (angle);
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 123)
		game->angle = norm_angle(game->angle - 8*M_PI/180);
	else if (keycode == 124)
		game->angle = norm_angle(game->angle + 8*M_PI/180);
	else if (keycode == 126)
	{
		if (!wall(game, keycode))
		{
			game->player_x = game->player_x + 8*cos(game->angle);
			game->player_y = game->player_y + 8*sin(game->angle);
		}
	}
	else if (keycode == 125)
	{
		if (!wall(game, keycode))
		{
			game->player_x = game->player_x - 8*cos(game->angle);
			game->player_y = game->player_y - 8*sin(game->angle);
		}
	}
	mlx_destroy_image(game->mlx, game->img);
	render(game);
	return (0);
}