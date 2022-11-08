/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:45:16 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/08 22:48:15 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_map_rays(t_data *game)
{
	int	i;
	double	ray_angle;

	//FOV= Pi/3
	ray_angle = game->angle - M_PI/6;
	i = 0;
	while (i < RX)
	{
		my_mlx_pixel_put(game, MSF*game->rays[i].inter_x, MSF*game->rays[i].inter_y, 0x800000);
		DDA(MSF*game->player_x, MSF*game->player_y, MSF*game->rays[i].inter_x, MSF*game->rays[i].inter_y, game, 0x800000);
		ray_angle += norm_angle(FOV / RX);
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_pixel(t_texture *data, int x, int y)
{
	char			*dst;

	dst = data->t_addr + (y * data->ll + x * (data->bpp / 8));
	return (*(unsigned int*)dst);
}

void	render_map(t_data *game)
{
	int i;
	int j;
	int k;
	int l;
	

	i = 0;
	while (i < game->map_rows)
	{
 			j = 0;
			while (j < game->map_columns)
			{
				k = 0;
				while (k < CUBE)
				{
					l = 0;
					while (l < CUBE)
					{
						if ((game->map)[i][j] == '1')
							//my_mlx_pixel_put(game, MSF*(CUBE*j+l), MSF*(CUBE*i+k), 0x008080);
						//else
							my_mlx_pixel_put(game, MSF*(CUBE*j+l), MSF*(CUBE*i+k), 0x000000);
						if (pow(((CUBE*i + k)-(game->player_y)), 2) + pow(CUBE*j + l-(game->player_x), 2) <= 200)
							my_mlx_pixel_put(game, MSF*(CUBE*j+l), MSF*(CUBE*i+k), 0xFF0000);
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
	}
	//draw_map_rays(game);
	//DDA(MSF*game->player_x, MSF*game->player_y, MSF*(game->player_x + 200*cos(game->angle)), MSF*(game->player_y +200*sin(game->angle)), game, 0xFF0000);
}