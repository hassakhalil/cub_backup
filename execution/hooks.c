/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:35:06 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/25 00:35:44 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 123)
		game->angle= game->angle - 8*M_PI/180;
	else if (keycode == 124)
		game->angle = game->angle + 8*M_PI/180;
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