/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 07:15:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/11 19:16:45 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_text(t_data *game, int i)
{
	game->textures[i].t_image = mlx_xpm_file_to_image(game->mlx,
			game->textures[i].t_file, &game->textures[i].t_width,
			&game->textures[i].t_height);
	if (!game->textures[i].t_image
		|| game->textures[i].t_width != CUBE
		|| game->textures[i].t_height != CUBE)
	{
		write(2, "invalid texture\n", 17);
		i--;
		while (i > -1)
		{
			mlx_destroy_image(game->mlx, game->textures[i].t_image);
			i--;
		}
		ft_exit(game, 0);
	}
	game->textures[i].t_addr = mlx_get_data_addr(game->textures[i].t_image,
			&game->textures[i].bpp,
			&game->textures[i].ll, &game->textures[i].end);
}

void	read_texture(t_data *game)
{
	get_text(game, 0);
	get_text(game, 1);
	get_text(game, 2);
	get_text(game, 3);
}
