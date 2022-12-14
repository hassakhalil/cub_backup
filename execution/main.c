/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:58:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/11 21:53:03 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	char	**tab;
	t_info	*info;
	t_data	*game;
	int		fd;

	fd = 0;
	if (ac == 2)
	{
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
		mlx_hook(game->mlx_window, 17, 1L << 0, ft_exit, game);
		mlx_hook(game->mlx_window, 2, 1L << 0, key_hook, game);
		mlx_loop(game->mlx);
	}
}
