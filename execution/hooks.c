/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:35:06 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 01:24:01 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_for(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + MOV_SPEED * cos(game->angle);
	new_y = game->player_y + MOV_SPEED * sin(game->angle);
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		apdate(game);
	}
}

void	move_back(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x - MOV_SPEED * cos(game->angle);
	new_y = game->player_y - MOV_SPEED * sin(game->angle);
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		apdate(game);
	}
}

void	move_left(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + MOV_SPEED * cos(norm_angle(game->angle - M_PI_2));
	new_y = game->player_y + MOV_SPEED * sin(norm_angle(game->angle - M_PI_2));
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		apdate(game);
	}
}

void	move_right(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + MOV_SPEED * cos(norm_angle(game->angle + M_PI_2));
	new_y = game->player_y + MOV_SPEED * sin(norm_angle(game->angle + M_PI_2));
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		apdate(game);
	}
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 53)
		ft_exit(game, 1);
	else if (keycode == 123)
	{
		game->angle = norm_angle(game->angle - ROT_SPEED);
		apdate(game);
	}
	else if (keycode == 124)
	{
		game->angle = norm_angle(game->angle + ROT_SPEED);
		apdate(game);
	}
	else if (keycode == 126 || keycode == 13)
		move_for(game);
	else if (keycode == 125 || keycode == 1)
		move_back(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 2)
		move_right(game);
	return (0);
}
