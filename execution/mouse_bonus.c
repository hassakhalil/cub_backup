/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:59:16 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 09:41:19 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	mouse_hook(int button, int x, int y, t_data *game)
{
	x = 0;
	y = 0;
	if (button == 1)
	{
		game->angle = norm_angle(game->angle - ROT_SPEED);
		update_bonus(game);
	}
	else if (button == 2)
	{
		game->angle = norm_angle(game->angle + ROT_SPEED);
		update_bonus(game);
	}
	return (0);
}
