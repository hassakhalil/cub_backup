/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/09 21:14:59 by hkhalil          ###   ########.fr       */
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
	int	start;
	int	end;
	double	ray_angle;
	double	wallheight;
	double	beta;

	ray_angle = norm_angle(game->angle - M_PI/6);
	i = 0;
	beta = norm_angle(ray_angle - game->angle);
	while (i < RX)
	{
		get_inter_point(game, &(game->rays[i]), ray_angle);
		game->rays[i].d = hypot(game->player_x - game->rays[i].inter_x, game->player_y - game->rays[i].inter_y);
		wallheight = round(((CUBE*game->value.d2pp)/((game->rays[i]).d*cos(beta))));
		if (wallheight < RY)
		{
			start = RY/2 - wallheight/2;
			end = RY/2 + wallheight/2;
		}
		else
		{
			start = 0;
			end = RY;
		}
		if (game->rays[i].wall == 'N')
		{
			if (game->rays[i].v_or_h == 'v')
				offset_x = (int)game->rays[i].inter_y % CUBE;
			else
				offset_x = (int)game->rays[i].inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[0], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
		else if (game->rays[i].wall == 'S')
		{
			if (game->rays[i].v_or_h == 'v')
				offset_x = (int)game->rays[i].inter_y % CUBE;
			else
				offset_x = (int)game->rays[i].inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[1], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
		else if (game->rays[i].wall == 'E')
		{
			if (game->rays[i].v_or_h == 'v')
				offset_x = (int)game->rays[i].inter_y % CUBE;
			else
				offset_x = (int)game->rays[i].inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[2], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
		else if (game->rays[i].wall == 'W')
		{
			if (game->rays[i].v_or_h == 'v')
				offset_x = (int)game->rays[i].inter_y % CUBE;
			else
				offset_x = (int)game->rays[i].inter_x % CUBE;
			y = start;
			while (y <  end)
			{
				offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
				texel_color = get_pixel(&game->textures[3], offset_x, offset_y);
				my_mlx_pixel_put(game, i, y, texel_color);
				y++;
			}
		}
		ray_angle += game->value.delta_ang;
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