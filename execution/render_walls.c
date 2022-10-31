/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/31 04:35:57 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(t_data *game)
{
	int	i;
	double	ray_angle;
	double	rays[game->num_of_rays];
	t_raydata	*ray = malloc(sizeof(t_raydata));

	ray_angle = game->angle - game->fov/2;
	i = 0;
	while (i < game->num_of_rays)
	{
		get_inter_point(game, ray, ray_angle);
		rays[i] = hypot(game->player_x - ray->inter_x, game->player_y - ray->inter_y);
		//draw with dda
		ray_angle += norm_angle(game->fov / game->num_of_rays);
		i++;
	}
}

void	render_walls(t_data *game)
{
	game->img = mlx_new_image(game->mlx, game->window_width, game->window_length);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

	draw_rays_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop(game->mlx);
}