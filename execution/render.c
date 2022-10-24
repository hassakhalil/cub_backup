/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:45:16 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/25 00:45:49 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render(t_data *game)
{
	int i;
	int j;
	int k;
	int l;
	

	i = 0;
	game->img = mlx_new_image(game->mlx, game->window_width, game->window_length);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	while (i < game->map_rows)
	{
 			j = 0;
			while (j < game->map_columns)
			{
				k = 0;
				while (k < game->cube)
				{
					l = 0;
					while (l < game->cube)
					{
						if ((game->map)[i][j] == '1')
							my_mlx_pixel_put(game, game->cube*j+l, game->cube*i+k, 0x008080);
						if (pow(((game->cube*i + k)-(game->player_y)), 2) + pow(game->cube*j + l-(game->player_x), 2) <= 100)
							my_mlx_pixel_put(game, game->cube*j+l, game->cube*i+k, 0x800000);
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
	}
	send_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop(game->mlx);
}