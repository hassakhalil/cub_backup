/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/31 03:56:44 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_walls(t_data *game)
{
	game->img = mlx_new_image(game->mlx, game->window_width, game->window_length);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

	send_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop(game->mlx);
}