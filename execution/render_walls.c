/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/03 07:16:46 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(t_data *game)
{
	int	i;
	double	ray_angle;
	double	wallheight;
	double	beta;
	//distance from player to projection plan
	double	d2pp;
	t_raydata	*ray = malloc(sizeof(t_raydata));

	ray_angle = norm_angle(game->angle - M_PI/6);
	i = 0;
	d2pp = (CUBE/2)/tan(M_PI/6);
	beta = norm_angle(ray_angle - game->angle);
	while (i < RX)
	{
		get_inter_point(game, ray, ray_angle);
		game->rays[i].d = hypot(game->player_x - ray->inter_x, game->player_y - ray->inter_y);
		game->rays[i].inter_x = ray->inter_x;
		game->rays[i].inter_y = ray->inter_y;
		game->rays[i].hit = ray->hit;
		wallheight = round(((RY*d2pp)/((game->rays[i]).d*cos(beta))));
		if (wallheight < RY)
		{
			if (!ray->hit)
				DDA(i, RY/2 - wallheight/2, i, RY/2 + wallheight/2, game, 0x808000);
			else
				DDA(i, RY/2 - wallheight/2, i, RY/2 + wallheight/2, game, 0x000000);
		}
		else
			DDA(i, 0, i, RY - 1, game, 0x808000);
		ray_angle += FOV / RX;
		i++;
	}
}

void	render_walls(t_data *game)
{
	game->img = mlx_new_image(game->mlx, RX, RY);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

	floor_ceilling(game);
	draw_wall(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
}