/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:11:09 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/11 19:58:04 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_game(t_data *game, int flag)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(game->textures[i].t_file);
		if (flag)
			mlx_destroy_image(game->mlx, game->textures[i].t_image);
		i++;
	}
	free_tab(game->map);
	mlx_destroy_window(game->mlx, game->mlx_window);
	if (flag)
	{
		if (flag == 1)
			mlx_destroy_image(game->mlx, game->img);
		else
			write(2, "map too big\n", 13);
		free(game);
	}
}

int	ft_exit(t_data *game, int flag)
{
	free_game(game, flag);
	exit(1);
}
