/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:38:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/25 02:47:04 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall(t_data *game, int keycode)
{
	double	new_x = 0;
	double	new_y=0;

	if (keycode == 126)
	{
			new_x = game->player_x + 8*cos(game->angle);
			new_y = game->player_y + 8*sin(game->angle);
	}
	else if (keycode == 125)
	{
			new_x = game->player_x - 8*cos(game->angle);
			new_y = game->player_y - 8*sin(game->angle);
	}
	if (game->map[(int)new_y][(int)new_x] == '1')
		return (1);
	return (0);
}