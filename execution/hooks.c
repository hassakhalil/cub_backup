/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:35:06 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/05 23:43:27 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_hook(int keycode, t_data *game)
{
	double	new_x;
	double	new_y;

	//debug
	dprintf(2, "keycode == %d\n", keycode);
	//end debug
	if (keycode == 53)
	{
		//clean everything
		exit(1);
	}
	else if (keycode == 123)
		game->angle = norm_angle(game->angle - ROT_SPEED);
	else if (keycode == 124)
		game->angle = norm_angle(game->angle + ROT_SPEED);
	else if (keycode == 126 || keycode == 13)
	{
		new_x = game->player_x + MOV_SPEED*cos(game->angle);
		new_y = game->player_y + MOV_SPEED*sin(game->angle);
		if (wall(game, new_x, new_y, 1) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
	else if (keycode == 125 || keycode == 1)
	{
		new_x = game->player_x - MOV_SPEED*cos(game->angle);
		new_y = game->player_y - MOV_SPEED*sin(game->angle);
		if (wall(game, new_x, new_y, 1) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
	else if (keycode == 0)
	{
		new_x = game->player_x + MOV_SPEED*cos(norm_angle(game->angle - M_PI_2));
		new_y = game->player_y + MOV_SPEED*sin(norm_angle(game->angle - M_PI_2));
		if (wall(game, new_x, new_y, 1) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
	else if (keycode == 2)
	{
		new_x = game->player_x + MOV_SPEED*cos(norm_angle(game->angle + M_PI_2));
		new_y = game->player_y + MOV_SPEED*sin(norm_angle(game->angle + M_PI_2));
		if (wall(game, new_x, new_y, 1) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
	mlx_destroy_image(game->mlx, game->img);
	render_walls(game);
	render_map(game);
	return (0);
}