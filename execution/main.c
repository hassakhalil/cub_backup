/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:58:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/09 01:35:26 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//use get_inter one time

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
	free_tab(tab);
	// system("leaks cub3D");
	// exit(0);
	//execution
	t_data *game = malloc(sizeof(t_data));
	game->map = info->new_map;
	game->map_rows = info->map_y;
	game->map_columns = info->map_x;
	game->map_length = info->map_y * CUBE;
	game->map_width = info->map_x * CUBE;
	game->player_x = info->x*CUBE + CUBE/2;
	game->player_y = info->y*CUBE + CUBE/2;
	game->floor = info->floor;
	game->ceilling = info->ceil;
	game->angle = ft_angle(info->dir);
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, RX, RY, "cub3d");
	//n
	game->textures[0].t_file = ft_strdup(info->no);
	//s
	game->textures[1].t_file = ft_strdup(info->so);
	// w
	game->textures[2].t_file = ft_strdup(info->we);
	//e
	game->textures[3].t_file = ft_strdup(info->ea);
	//free info struct here

	//debug
	read_texture(game);
	//end debug
	render_walls(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
	mlx_hook(game->mlx_window, 17, 0, ft_exit, game);
	mlx_hook(game->mlx_window, 2, 0, key_hook, game);
	mlx_mouse_hook(game->mlx_window, mouse_hook, game);
	mlx_loop(game->mlx);
}