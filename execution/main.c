/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:58:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/09 21:14:34 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	precalculate(t_data *game)
{
	game->value.d2pp = (RX / 2) / tan(M_PI / 6);
	game->value.delta_ang =  FOV / RX;
	game->value.RX_2 = RX / 2;
	game->value.RY_2 = RY / 2;
}

void	game_init(t_data *game, t_info *info)
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
	render_walls(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
}

int	handler(t_data *game)
{
	mlx_hook(game->mlx_window, 17, 0, ft_exit, game);
	mlx_hook(game->mlx_window, 2, 0, key_hook, game);
 	mlx_mouse_hook(game->mlx_window, mouse_hook, game);
	mlx_destroy_image(game->mlx, game->img);
	render_walls(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	char	**tab;
	t_info	*info;
	t_data	*game;
	int		fd;

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
	game = malloc(sizeof(t_data));
	game_init(game, info);
	precalculate(game);
	// mlx_hook(game->mlx_window, 17, 0, ft_exit, game);
	// mlx_hook(game->mlx_window, 2, 0, key_hook, game);
	// mlx_mouse_hook(game->mlx_window, mouse_hook, game);
	mlx_loop_hook(game->mlx, handler, game);
	mlx_loop(game->mlx);
}
