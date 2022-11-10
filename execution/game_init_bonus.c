/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:06:00 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 09:45:02 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	game_init_bonus(t_data *game, t_info *info)
{
	game->map = info->new_map;
	game->map_rows = info->map_y;
	game->map_columns = info->map_x;
	game->map_length = info->map_y * CUBE;
	game->map_width = info->map_x * CUBE;
	game->player_x = info->x * CUBE + CUBE / 2;
	game->player_y = info->y * CUBE + CUBE / 2;
	game->floor = info->floor;
	game->ceilling = info->ceil;
	game->angle = ft_angle(info->dir);
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, RX, RY, "cub3d");
	game->textures[0].t_file = info->no;
	game->textures[1].t_file = info->so;
	game->textures[2].t_file = info->we;
	game->textures[3].t_file = info->ea;
	free_struct(info);
	read_texture(game);
	game->d2pp = (RX / 2) / tan(M_PI / 6);
	render_walls(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
}

void	update_bonus(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img);
	render_walls(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
}
