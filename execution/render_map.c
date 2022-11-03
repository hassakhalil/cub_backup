/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:45:16 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/03 04:13:59 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_map_rays(t_data *game)
{
	int	i;
	double	ray_angle;
	t_raydata	*ray = malloc(sizeof(t_raydata));

	//FOV= Pi/3
	ray_angle = game->angle - M_PI/6;
	i = 0;
	while (i < RX)
	{
		get_inter_point(game, ray, ray_angle);
		//draw with dda
		my_mlx_pixel_put(game, MSF*ray->inter_x, MSF*ray->inter_y, 0xFFFF00);
		DDA(MSF*game->player_x, MSF*game->player_y, MSF*ray->inter_x, MSF*ray->inter_y, game, 0x800000);
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
							my_mlx_pixel_put(game, MSF*(CUBE*j+l), MSF*(CUBE*i+k), 0x008080);
						if (pow(((CUBE*i + k)-(game->player_y)), 2) + pow(CUBE*j + l-(game->player_x), 2) <= 100)
							my_mlx_pixel_put(game, MSF*(CUBE*j+l), MSF*(CUBE*i+k), 0xFFFFFF);
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
	}
	draw_map_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
}