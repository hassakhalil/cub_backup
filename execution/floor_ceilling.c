/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:58:09 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/09 01:31:03 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floor_ceilling(t_data *game)
{
	int	i;
	int	j;
	int	end_ceilling;

	i = 0;
	end_ceilling = RY/2;
	while (i < end_ceilling)
	{
		j = 0;
		while (j < RX)
		{
			my_mlx_pixel_put(game, j, i, game->ceilling);
			j++;
		}
		i++;
	}
	while (i < RY)
	{
		j = 0;
		while (j < RX)
		{
			my_mlx_pixel_put(game, j, i, game->floor);
			j++;
		}
		i++;
	}
}