/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:35:06 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/30 22:34:39 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double norm_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2*M_PI;
	return (angle);
}

int	key_hook(int keycode, t_data *game)
{
	double	new_x;
	double	new_y;

	//define speed
	if (keycode == 123)
		game->angle = norm_angle(game->angle - ROT_SPEED);
	else if (keycode == 124)
		game->angle = norm_angle(game->angle + ROT_SPEED);
	else if (keycode == 126)
	{
		new_x = game->player_x + MOV_SPEED*cos(game->angle);
		new_y = game->player_y + MOV_SPEED*sin(game->angle);
		if (wall(game, new_x, new_y, 1) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
	else if (keycode == 125)
	{
		new_x = game->player_x - MOV_SPEED*cos(game->angle);
		new_y = game->player_y - MOV_SPEED*sin(game->angle);
		if (wall(game, new_x, new_y, 1) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
	mlx_destroy_image(game->mlx, game->img);
	render(game);
	return (0);
}