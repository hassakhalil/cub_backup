/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 04:39:19 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(t_data *game)
{
	unsigned int texel_color;
	int	i;
	int	y;
	int	offset_x;
	int	offset_y;
	double	d;
	int	start;
	int	end;
	double	ray_angle;
	double	wallheight;
	double	beta;

	i = 0;	
	while (i < RX)
	{
		ray_angle = game->angle + atan((i - 0.5*RX)/game->d2pp);
		beta = ray_angle - game->angle;
		get_inter_point(game, &(game->ray), ray_angle);
		d = hypot(game->player_x - game->ray.inter_x, game->player_y - game->ray.inter_y)*cos(beta);
		wallheight = round(CUBE*(game->d2pp/d));
		if (wallheight < RY)
		{
			start = 0.5*RY - wallheight/2;
			end = 0.5*RY + wallheight/2;
		}
		else
		{
			start = 0;
			end = RY;
		}
		if (game->ray.wall == 'N')
		{
			if (game->ray.v_or_h == 'v')
				offset_x = (int)game->ray.inter_y % CUBE;
			else
				offset_x = (int)game->ray.inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - 0.5*RY)*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[0], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
		else if (game->ray.wall == 'S')
		{
			if (game->ray.v_or_h == 'v')
				offset_x = (int)game->ray.inter_y % CUBE;
			else
				offset_x = (int)game->ray.inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - 0.5*RY)*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[1], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
		else if (game->ray.wall == 'E')
		{
			if (game->ray.v_or_h == 'v')
				offset_x = (int)game->ray.inter_y % CUBE;
			else
				offset_x = (int)game->ray.inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - 0.5*RY)*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[2], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
		else if (game->ray.wall == 'W')
		{
			if (game->ray.v_or_h == 'v')
				offset_x = (int)game->ray.inter_y % CUBE;
			else
				offset_x = (int)game->ray.inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - 0.5*RY)*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[3], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
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