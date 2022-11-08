/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 07:15:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/08 21:19:17 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_texture(t_data *game)
{
	game->textures[0].t_image = mlx_xpm_file_to_image(game->mlx, game->textures[0].t_file, &game->textures[0].t_width, &game->textures[0].t_height);
	game->textures[0].t_addr = mlx_get_data_addr(game->textures[0].t_image, &game->textures[0].bpp, &game->textures[0].ll, &game->textures[0].end);
	game->textures[1].t_image = mlx_xpm_file_to_image(game->mlx, game->textures[1].t_file, &game->textures[1].t_width, &game->textures[1].t_height);
	game->textures[1].t_addr = mlx_get_data_addr(game->textures[1].t_image, &game->textures[1].bpp, &game->textures[1].ll, &game->textures[1].end);
	game->textures[2].t_image = mlx_xpm_file_to_image(game->mlx, game->textures[2].t_file, &game->textures[2].t_width, &game->textures[2].t_height);
	game->textures[2].t_addr = mlx_get_data_addr(game->textures[2].t_image, &game->textures[2].bpp, &game->textures[2].ll, &game->textures[2].end);
	game->textures[3].t_image = mlx_xpm_file_to_image(game->mlx, game->textures[3].t_file, &game->textures[3].t_width, &game->textures[3].t_height);
	game->textures[3].t_addr = mlx_get_data_addr(game->textures[3].t_image, &game->textures[3].bpp, &game->textures[3].ll, &game->textures[3].end);
}