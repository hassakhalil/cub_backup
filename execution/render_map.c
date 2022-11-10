/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:45:16 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 04:43:42 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_texture *data, int x, int y)
{
	char			*dst;

	dst = data->t_addr + (y * data->ll + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_player(t_data *game)
{
	int	i;
	int	j;

	i = -10;
	while (i < 11)
	{
		j = -10;
		while (j < 11)
		{
			my_mlx_pixel_put(game, MSF * (game->player_x + j),
				MSF * (game->player_y + i), 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *game, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	while (k < CUBE)
	{
		l = 0;
		while (l < CUBE)
		{
			if ((game->map)[i][j] == '1')
				my_mlx_pixel_put(game, MSF * (CUBE * j + l),
					MSF * (CUBE * i + k), 0x000000);
			l++;
		}
		k++;
	}
	draw_player(game);
}

void	render_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_columns)
		{
			draw_map(game, i, j);
			j++;
		}
		i++;
	}
}
