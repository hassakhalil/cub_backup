/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:59:16 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/09 05:00:24 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_hook(int button, int x, int y, t_data *game)
{
	x = 0;
	y = 0;
	if (button == 1)
		game->angle = norm_angle(game->angle - ROT_SPEED);
	else if (button == 2)
		game->angle = norm_angle(game->angle + ROT_SPEED);
	mlx_destroy_image(game->mlx, game->img);
	render_walls(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
	return (0);
}
