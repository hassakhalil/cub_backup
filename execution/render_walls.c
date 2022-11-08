/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:33:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/08 22:50:35 by hkhalil          ###   ########.fr       */
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
			if (game->ray.wall == 'N')
			{
				start = RY/2 - wallheight/2;
				end = RY/2 + wallheight/2;
				// if (game->ray.v_or_h == 0)
				// 	offset_x = CUBE  - (int)game->rays[i].inter_x % CUBE;
				// else
				// 	offset_x = (int)game->rays[i].inter_y % CUBE;
				if (fabs(game->rays[i].inter_x - CUBE*round(game->rays[i].inter_x/CUBE)) < fabs(game->rays[i].inter_y - CUBE*round(game->rays[i].inter_y/CUBE)))
					offset_x = game->rays[i].inter_y - CUBE*floor(game->rays[i].inter_y/CUBE);
				else
					offset_x =  CUBE*ceil(game->rays[i].inter_x/CUBE) - game->rays[i].inter_x; 
				y = start;
				// offset_y = 0;
				while (y <  end)
				{
					offset_y = (y - start)*(64/wallheight);
					//DDA(i, RY/2 - wallheight/2, i, RY/2 + wallheight/2, game, 0x808000);
					// texel_color =  game->textures[0].t_addr[(game->textures[0].t_width*offset_y) + offset_x];
					//debug
					texel_color = get_pixel(&game->textures[0], offset_x, offset_y);
					//end devuf
					my_mlx_pixel_put(game, i, y, texel_color);
					// game->addr[RX*y + i] = texel_color;
					y++;
					// offset_y++;
				}
			}
			else if (game->ray.wall == 'S')
				DDA(i, RY/2 - wallheight/2, i, RY/2 + wallheight/2, game, 0x3649C2);
			else if (game->ray.wall == 'E')
				DDA(i, RY/2 - wallheight/2, i, RY/2 + wallheight/2, game, 0x8ED3F1);
			else if (game->ray.wall == 'W')
				DDA(i, RY/2 - wallheight/2, i, RY/2 + wallheight/2, game, 0xF1D38E);
		}
		else
		{
			if (game->ray.wall == 'N')
				DDA(i, 0, i, RY - 1, game, 0x808000);
			else if (game->ray.wall == 'S')
				DDA(i, 0, i, RY - 1, game, 0x3649C2);
			else if (game->ray.wall == 'E')
				DDA(i, 0, i, RY - 1, game, 0x8ED3F1);
			else if (game->ray.wall == 'W')
				DDA(i, 0, i, RY - 1, game, 0xF1D38E);
				//DDA(i, 0, i, RY - 1, game, 0x808000);
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