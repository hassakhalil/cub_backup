/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/11 19:19:22 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	start_end(double wallheight, int *start, int *end)
{
	if (wallheight < RY)
	{
		*start = 0.5 * RY - wallheight / 2;
		*end = 0.5 * RY + wallheight / 2;
	}
	else
	{
		*start = 0;
		*end = RY;
	}
}

void	draw_ray(t_data *game, int t, double wallheight, int i)
{
	int	start;
	int	end;
	int	y;
	int	offset_x;
	int	offset_y;

	start_end(wallheight, &start, &end);
	if (game->ray.v_or_h == 'v')
		offset_x = (int)game->ray.inter_y % CUBE;
	else
		offset_x = (int)game->ray.inter_x % CUBE;
	y = start;
	while (y < end)
	{
		offset_y = (y + (wallheight / 2) - 0.5 * RY)
			* ((float)game->textures[t].t_height / wallheight);
		my_mlx_pixel_put(game, i, y,
			get_pixel(&game->textures[t], offset_x, offset_y));
		y++;
	}
}

void	draw_wall(t_data *game)
{
	int		i;
	double	d;
	double	ray_angle;
	double	wallheight;
	double	beta;

	i = 0;
	while (i < RX)
	{
		ray_angle = game->angle + atan((i - 0.5 * RX) / game->d2pp);
		beta = ray_angle - game->angle;
		get_inter_point(game, ray_angle);
		d = hypot(game->player_x - game->ray.inter_x,
				game->player_y - game->ray.inter_y) * cos(beta);
		wallheight = round(CUBE * (game->d2pp / d));
		if (game->ray.wall == 'N')
			draw_ray(game, 0, wallheight, i);
		else if (game->ray.wall == 'S')
			draw_ray(game, 1, wallheight, i);
		else if (game->ray.wall == 'E')
			draw_ray(game, 3, wallheight, i);
		else if (game->ray.wall == 'W')
			draw_ray(game, 2, wallheight, i);
		i++;
	}
}

void	render_walls(t_data *game)
{
	game->img = mlx_new_image(game->mlx, RX, RY);
	game->addr = mlx_get_data_addr(game->img,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	floor_ceilling(game);
	draw_wall(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
}
