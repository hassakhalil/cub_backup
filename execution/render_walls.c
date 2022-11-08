/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/08 23:08:38 by hkhalil          ###   ########.fr       */
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
	//distance from player to projection plan
	double	d2pp;

	ray_angle = norm_angle(game->angle - M_PI/6);
	i = 0;
	d2pp = (CUBE/2)/tan(M_PI/6);
	beta = norm_angle(ray_angle - game->angle);
	while (i < RX)
	{
		get_inter_point(game, &(game->ray), ray_angle);
		game->rays[i].d = hypot(game->player_x - game->ray.inter_x, game->player_y - game->ray.inter_y);
		game->rays[i].inter_x = game->ray.inter_x;
		game->rays[i].inter_y = game->ray.inter_y;
		game->rays[i].hit = game->ray.hit;
		game->rays[i].v_or_h = game->ray.v_or_h;
		wallheight = round(((RY*d2pp)/((game->rays[i]).d*cos(beta))));
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
			if (game->ray.wall == 'N')
			{
				if (game->ray.v_or_h == 0)
					offset_x = (int)game->rays[i].inter_y % CUBE;
				else
					offset_x = (int)game->rays[i].inter_x % CUBE;
				// if (fabs(game->rays[i].inter_x - CUBE*round(game->rays[i].inter_x/CUBE)) < fabs(game->rays[i].inter_y - CUBE*round(game->rays[i].inter_y/CUBE)))
				// 	offset_x = game->rays[i].inter_y - CUBE*floor(game->rays[i].inter_y/CUBE);
				// else
				// 	offset_x =  CUBE*ceil(game->rays[i].inter_x/CUBE) - game->rays[i].inter_x; 
				y = start;
				while (y <  end)
				{
					offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
					texel_color = get_pixel(&game->textures[0], offset_x, offset_y);
					my_mlx_pixel_put(game, i, y, texel_color);
					y++;
				}
			}
			else if (game->ray.wall == 'S')
			{
				if (game->ray.v_or_h == 0)
					offset_x = (int)game->rays[i].inter_y % CUBE;
				else
					offset_x = (int)game->rays[i].inter_x % CUBE;
				// if (fabs(game->rays[i].inter_x - CUBE*round(game->rays[i].inter_x/CUBE)) < fabs(game->rays[i].inter_y - CUBE*round(game->rays[i].inter_y/CUBE)))
				// 	offset_x = game->rays[i].inter_y - CUBE*floor(game->rays[i].inter_y/CUBE);
				// else
				// 	offset_x =  CUBE*ceil(game->rays[i].inter_x/CUBE) - game->rays[i].inter_x; 
				y = start;
				while (y <  end)
				{
					offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
					texel_color = get_pixel(&game->textures[1], offset_x, offset_y);
					my_mlx_pixel_put(game, i, y, texel_color);
					y++;
				}
			}
			else if (game->ray.wall == 'E')
			{
				if (game->ray.v_or_h == 0)
					offset_x = (int)game->rays[i].inter_y % CUBE;
				else
					offset_x = (int)game->rays[i].inter_x % CUBE;
				// if (fabs(game->rays[i].inter_x - CUBE*round(game->rays[i].inter_x/CUBE)) < fabs(game->rays[i].inter_y - CUBE*round(game->rays[i].inter_y/CUBE)))
				// 	offset_x = game->rays[i].inter_y - CUBE*floor(game->rays[i].inter_y/CUBE);
				// else
				// 	offset_x =  CUBE*ceil(game->rays[i].inter_x/CUBE) - game->rays[i].inter_x; 
				y = start;
				while (y <  end)
				{
					offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
					texel_color = get_pixel(&game->textures[2], offset_x, offset_y);
					my_mlx_pixel_put(game, i, y, texel_color);
					y++;
				}
			}
			else if (game->ray.wall == 'W')
			{
				if (game->ray.v_or_h == 0)
					offset_x = (int)game->rays[i].inter_y % CUBE;
				else
					offset_x = (int)game->rays[i].inter_x % CUBE;
				// if (fabs(game->rays[i].inter_x - CUBE*round(game->rays[i].inter_x/CUBE)) < fabs(game->rays[i].inter_y - CUBE*round(game->rays[i].inter_y/CUBE)))
				// 	offset_x = game->rays[i].inter_y - CUBE*floor(game->rays[i].inter_y/CUBE);
				// else
				// 	offset_x = CUBE*ceil(game->rays[i].inter_x/CUBE) - game->rays[i].inter_x;
				y = start;
				while (y <  end)
				{
					offset_y = (y + (wallheight/2) - (RY/2))*((float)game->textures[3].t_height/wallheight);
					texel_color = get_pixel(&game->textures[3], offset_x, offset_y);
					my_mlx_pixel_put(game, i, y, texel_color);
					y++;
				}
			}
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