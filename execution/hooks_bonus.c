/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:12:50 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 09:44:51 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	move_for_bonus(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + MOV_SPEED * cos(game->angle);
	new_y = game->player_y + MOV_SPEED * sin(game->angle);
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update_bonus(game);
	}
}

void	move_back_bonus(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x - MOV_SPEED * cos(game->angle);
	new_y = game->player_y - MOV_SPEED * sin(game->angle);
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update_bonus(game);
	}
}

void	move_left_bonus(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + MOV_SPEED * cos(norm_angle(game->angle - M_PI_2));
	new_y = game->player_y + MOV_SPEED * sin(norm_angle(game->angle - M_PI_2));
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update_bonus(game);
	}
}

void	move_right_bonus(t_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + MOV_SPEED * cos(norm_angle(game->angle + M_PI_2));
	new_y = game->player_y + MOV_SPEED * sin(norm_angle(game->angle + M_PI_2));
	if (wall(game, new_x, new_y, 1) != 1)
	{
		game->player_x = new_x;
		game->player_y = new_y;
		update_bonus(game);
	}
}

int	key_hook_bonus(int keycode, t_data *game)
{
	if (keycode == 53)
		ft_exit(game, 1);
	else if (keycode == 123)
	{
		game->angle = norm_angle(game->angle - ROT_SPEED);
		update_bonus(game);
	}
	else if (keycode == 124)
	{
		game->angle = norm_angle(game->angle + ROT_SPEED);
		update_bonus(game);
	}
	else if (keycode == 126 || keycode == 13)
		move_for_bonus(game);
	else if (keycode == 125 || keycode == 1)
		move_back_bonus(game);
	else if (keycode == 0)
		move_left_bonus(game);
	else if (keycode == 2)
		move_right_bonus(game);
	return (0);
}
