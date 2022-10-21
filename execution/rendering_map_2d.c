/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map_2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:58:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/21 22:20:01 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct	s_data {
	void	*mlx;
	void	*mlx_window;
	int	map_rows;
	int	map_columns;
	double	cube;
	int window_length;
	int window_width;
	//map file
	char	*file_name;
	//fill the map here
	int	**map;
	double	player_x;
	double	player_y;
	double	angle;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *game)
{
	//debug
	dprintf(2, "key pressed { %d }\n", keycode);
	//end debug
	if (keycode == 123)
	{
		dprintf(2 , "pressed left\n");
		//left
		game->angle+=M_PI/10;
	}
	else if (keycode == 124)
	{
		dprintf(2 , "pressed right\n");
		game->angle-=M_PI/10;
		//rotate right
	}
	/*else if (keycode == 38)
	{
		//move forward
		game->pla
	} 
	else if (keycode == 40)
	{
		//move backward
		
	}
	*/
	char	map[24][24] = {
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','P','0','1','1','1','1','1','0','0','0','0','1','0','1','0','1','0','0','0','1'},
{'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','1','0','0','0','1','0','0','0','1'},
{'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','1','1','0','1','1','0','0','0','0','1','0','1','0','1','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','1','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','0','0','1','1','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','1','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
	
	int i = 0;
	int j;
	int k;
	int l;
	 while (i < game->map_rows)
	 {
 			j = 0;
			while (j < game->map_columns)
			{
				k = 0;
				while (k < game->cube)
				{
					l = 0;
					while (l < game->cube)
					{
						if (game->angle == M_PI_2)
							my_mlx_pixel_put(game, game->player_x,  game->cube*i+k, 0xFFFFFF);
						if (round(((game->cube*i + k) - game->player_y)) == round((tan(game->angle))*((game->cube*j + l) - game->player_x)))
							my_mlx_pixel_put(game, game->cube*j+l, game->cube*i+k, 0xFFFFFF);
						else if (map[(int)i][(int)j] == '1')
							my_mlx_pixel_put(game, game->cube*j+l, game->cube*i+k, 0x008080);
						else if (map[(int)i][(int)j] == 'P')
							if (pow((k-(game->cube/2)), 2) + pow(l-(game->cube/2), 2) <= 100)
								my_mlx_pixel_put(game, game->cube*j+l, game->cube*i+k, 0x800000);
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
	}
	return (0);
}

void	map_2d(/*take struct of data*/)
{
	t_data game;
	game.map_rows = 24;
	game.map_columns = 24;
	game.cube = 32;
	game.window_length = game.map_rows * game.cube;
	game.window_width = game.map_columns * game.cube;
	game.player_x = 4*game.cube+game.cube/2;
	game.player_y = 4*game.cube+game.cube/2;
	game.angle = M_PI;

char	map[24][24] = {
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','P','0','1','1','1','1','1','0','0','0','0','1','0','1','0','1','0','0','0','1'},
{'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','1','0','0','0','1','0','0','0','1'},
{'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','1','1','0','1','1','0','0','0','0','1','0','1','0','1','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','1','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','0','0','1','1','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','1','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, game.window_width, game.window_length, "cub3d");
	game.img = mlx_new_image(game.mlx, game.window_width, game.window_length);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
	double	j;
	double 	k;
	double	l;
	double i = 0;

	
	 while (i < game.map_rows)
	 {
 			j = 0;
			while (j < game.map_columns)
			{
				k = 0;
				while (k < game.cube)
				{
					l = 0;
					while (l < game.cube)
					{
						if (game.angle == M_PI_2)
							my_mlx_pixel_put(&game, game.player_x,  game.cube*i+k, 0xFFFFFF);
						if (round(((game.cube*i + k) - game.player_y)) == round((tan(game.angle))*((game.cube*j + l) - game.player_x)))
							my_mlx_pixel_put(&game, game.cube*j+l, game.cube*i+k, 0xFFFFFF);
						else if (map[(int)i][(int)j] == '1')
							my_mlx_pixel_put(&game, game.cube*j+l, game.cube*i+k, 0x008080);
						else if (map[(int)i][(int)j] == 'P')
							if (pow((k-(game.cube/2)), 2) + pow(l-(game.cube/2), 2) <= 100)
								my_mlx_pixel_put(&game, game.cube*j+l, game.cube*i+k, 0x800000);
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_window, game.img, 0, 0);
	mlx_key_hook(game.mlx_window, key_hook, &game);
	mlx_loop(game.mlx);
}

int main()
{
	map_2d();
}