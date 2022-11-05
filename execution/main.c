/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:58:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/04 23:43:18 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac, char **av)
{
	char	**tab;
	t_info	*info;
	int		fd;

	//parsing
	fd = 0;
	(void)ac;
	tab = init_file(av[1], fd);
	if (to_parse(tab) != 0)
	{
		close(fd);
		free_tab(tab);
		return (0);
	}
	info = fill_infos(tab);
	//execution
	t_data *game = malloc(sizeof(t_data));
	game->map = info->map;
	game->map_rows = info->map_y;
	game->map_columns = info->map_x;
	game->map_length = info->map_y * CUBE;
	game->map_width = info->map_x * CUBE;
	game->player_x = info->x*CUBE + CUBE/2;
	game->player_y = info->y*CUBE + CUBE/2;
	game->angle = ft_angle(info->dir);
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, RX, RY, "cub3d");
	
	render_walls(game);
	render_map(game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop(game->mlx);
}