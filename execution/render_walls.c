/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/01 17:02:25 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(t_data *game)
{
	int	i;
	double	ray_angle;
	double	wallheight;
	//distance from player to projection plan
	double	d2pp;
	double	rays[game->num_of_rays];
	t_raydata	*ray = malloc(sizeof(t_raydata));

	ray_angle = game->angle - M_PI/6;
	i = 0;
	d2pp = (CUBE/2)/tan(M_PI/6);
	while (i < game->num_of_rays)
	{
		get_inter_point(game, ray, ray_angle);
		rays[i] = hypot(game->player_x - ray->inter_x, game->player_y - ray->inter_y);
		wallheight = round((game->window_length*d2pp/rays[i]));
		if (game->window_length/2 + wallheight/2 < game->window_length)
		{
			DDA(i, game->window_length/2 - wallheight/2, i, game->window_length/2 + wallheight/2, game, 0x808000);
		}
		ray_angle += FOV / game->num_of_rays;
		i++;
	}
}

void	render_walls(t_data *game)
{
	game->img = mlx_new_image(game->mlx, game->window_width, game->window_length);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

	draw_wall(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
}