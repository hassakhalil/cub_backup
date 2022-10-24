/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map_2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:58:49 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/24 01:21:37 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void DDA(double x1, double y1, double x2, double y2, t_data *game)
{
  double x;
  double y;
  double dx, dy, step;
  int i;
   
  dx = (x2 - x1);
  dy = (y2 - y1);
  if (fabs(dx) >= fabs(dy))
    step = fabs(dx);
  else
    step = fabs(dy);
  dx = dx / step;
  dy = dy / step;
  x = x1;
  y = y1;
  i = 1;
  while (i <= step) {
	my_mlx_pixel_put(game, x, y, 0x800000);
    x = x + dx;
    y = y + dy;
    i = i + 1;
  }
}

int	wall(t_data *game, int keycode)
{
	double	tmp_x;
	double	tmp_y;
	int		i;
	int		j;

	if (keycode == 126)
	{
			tmp_x = game->player_x + 8*cos(game->angle);
			tmp_y = game->player_y + 8*sin(game->angle);
	}
	else if (keycode == 125)
	{
			tmp_x = game->player_x - 8*cos(game->angle);
			tmp_y = game->player_y - 8*sin(game->angle);
	}
	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_columns)
		{
			if (((tmp_x >= j*game->cube) && (tmp_x <= (j+1)*game->cube)) && ((tmp_y >= i*game->cube) && (tmp_y <= (i+1)*game->cube)))
			{
				if (game->map[i][j] == '1')
					return (1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (0);	
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 123)
		game->angle= game->angle - 8*M_PI/180;
	else if (keycode == 124)
		game->angle = game->angle + 8*M_PI/180;
	else if (keycode == 126)
	{
		if (!wall(game, keycode))
		{
			game->player_x = game->player_x + 8*cos(game->angle);
			game->player_y = game->player_y + 8*sin(game->angle);
		}
	}
	else if (keycode == 125)
	{
		if (!wall(game, keycode))
		{
			game->player_x = game->player_x - 8*cos(game->angle);
			game->player_y = game->player_y - 8*sin(game->angle);
		}
	}
	mlx_destroy_image(game->mlx, game->img);
	render(game);
	return (0);
}

void	render(t_data *game)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	game->img = mlx_new_image(game->mlx, game->window_width, game->window_length);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	DDA(game->player_x, game->player_y, game->player_x + 100*cos(game->angle),game->player_y + 100*sin(game->angle), game);
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
						if ((game->map)[i][j] == '1')
							my_mlx_pixel_put(game, game->cube*j+l, game->cube*i+k, 0x008080);
						if (pow(((game->cube*i + k)-(game->player_y)), 2) + pow(game->cube*j + l-(game->player_x), 2) <= 100)
							my_mlx_pixel_put(game, game->cube*j+l, game->cube*i+k, 0x800000);
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, 0, 0);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop(game->mlx);
}

int main()
{
	t_data *game = malloc(sizeof(t_data));
	game->map = malloc(sizeof(char *)*25);
	game->map_rows = 24;
	game->map_columns = 24;
	game->cube = 32;
	game->window_length = game->map_rows * game->cube;
	game->window_width = game->map_columns * game->cube;
	game->player_x = 4*game->cube + game->cube/2;
	game->player_y = 4*game->cube + game->cube/2;
	game->angle = 0;
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->window_width, game->window_length, "cub3d");
	(game->map)[0] = strdup("111111111111111111111111");
	(game->map)[1] = strdup("100000000000000000000001");
	(game->map)[2] = strdup("100000000000000000000001");
	(game->map)[3] = strdup("100000000000000000000001");
	(game->map)[4] = strdup("1000P0111110000101010001");
	(game->map)[5] = strdup("100000100010000000000001");
	(game->map)[6] = strdup("100000100010000100010001");
	(game->map)[7] = strdup("100000100010000000000001");
	(game->map)[8] = strdup("100000110110000101010001");
	(game->map)[9] = strdup("100000000000000000000001");
	(game->map)[10] = strdup("100000000000000000000001");
	(game->map)[11] = strdup("100000000000000000000001");
	(game->map)[12] = strdup("100000000000000000000001");
	(game->map)[13] = strdup("100000000000000000000001");
	(game->map)[14] = strdup("100000000000000000000001");
	(game->map)[15] = strdup("100000000000000000000001");
	(game->map)[16] = strdup("111111111000000000000001");
	(game->map)[17] = strdup("110100001000000000000001");
	(game->map)[18] = strdup("110001101000000000000001");
	(game->map)[19] = strdup("110100001000000000000001");
	(game->map)[20] = strdup("110111111000000000000001");
	(game->map)[21] = strdup("110000000000000000000001");
	(game->map)[22] = strdup("111111111000000000000001");
	(game->map)[23] = strdup("111111111111111111111111");
	(game->map)[24] = NULL;
	
	render(game);
}