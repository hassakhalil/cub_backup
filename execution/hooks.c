/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:35:06 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/28 01:47:48 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double norm_angle(double angle)
{
	angle =  remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2*M_PI;
	return (angle);
}

int	key_hook(int keycode, t_data *game)
{
	double	new_x;
	double	new_y;

	if (keycode == 123)
		game->angle = norm_angle(game->angle - 8*M_PI/180);
	else if (keycode == 124)
		game->angle = norm_angle(game->angle + 8*M_PI/180);
	else if (keycode == 126)
	{
		new_x = game->player_x + 8*cos(game->angle);
		new_y = game->player_y + 8*sin(game->angle);
		if (wall(game, new_x, new_y) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
		//debug
		dprintf(2, "{hooks} pressed up++++++++++++++\n");
		dprintf(2, "{hooks}new x ====== [ %f ]\n", game->player_x);
		dprintf(2, "{hooks}new y ====== [ %f ]\n", game->player_y);
		//end debug
	}
	else if (keycode == 125)
	{

		new_x = game->player_x - 8*cos(game->angle);
		new_y = game->player_y - 8*sin(game->angle);
		if (wall(game, new_x, new_y) != 1)
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
		//debug
		dprintf(2, "{hooks} pressed down------------\n");
		dprintf(2, "{hooks}new x ====== [ %f ]\n", game->player_x);
		dprintf(2, "{hooks}new y ====== [ %f ]\n", game->player_y);
		//end debug
	}
	mlx_destroy_image(game->mlx, game->img);
	render(game);
	return (0);
}