/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:41:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/25 02:35:09 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// double	check_hor_inter(t_data *game, double *x_hor, double *y_hor, double ang)
// {
// 	double	Xa;
// 	double	Ya;
// 	Xa = game->cube/tan(game->angle + ang);
// 	Ya = game->cube;
	
// }

// double	check_ver_inter(t_data *game, double *x_ver, double *y_ver, double ang)
// {
	
// }

// void	get_inter_point(t_data *game, double *inter_x, double *inter_y, double ang)
// {
// 	double	x_hor;
// 	double	y_hor;
// 	double	x_ver;
// 	double	y_ver;
// 	double	d_hor;
// 	double	d_ver;

// 	d_hor = check_hor_inter(game, &x_hor, &y_hor, ang);
// 	d_ver = check_ver_inter(game, &x_ver, &y_ver, ang);
// 	if (d_hor < d_ver)
// 	{
// 		*inter_x = x_hor;
// 		*inter_y = y_hor;
// 	}
// 	else
// 	{
// 		*inter_x = x_ver;
// 		*inter_y = y_ver;
// 	}
// }

void	get_inter_point(t_data *game, double *inter_x, double *inter_y, double ang)
{
	int	i;
	int j;

	//check_hor_inter
	//check_ver_inter
	//compare
	//get the smallest distance 
	*inter_x = game->player_x;
	*inter_y = game->player_y;	
	while(1)
	{
		*inter_x += cos(game->angle + ang);
		*inter_y += sin(game->angle + ang);
		i = 0;
		while (i < game->map_rows)
		{
			j = 0;
			while (j < game->map_columns)
			{
				if (((*inter_x >= j*game->cube) && (*inter_x <= (j+1)*game->cube)) && ((*inter_y >= i*game->cube) && (*inter_y <= (i+1)*game->cube)))
				{
					if (game->map[i][j] == '1')
						return;
				}
				j++;
			}
			i++;
		}
	}
}

void	send_rays(t_data *game)
{
	double inter_x;
	double inter_y;

	get_inter_point(game, &inter_x, &inter_y, 0);
	DDA(game->player_x, game->player_y, inter_x, inter_y, game);
	get_inter_point(game, &inter_x, &inter_y, M_PI/6);
	DDA(game->player_x, game->player_y, inter_x, inter_y, game);
	get_inter_point(game, &inter_x, &inter_y, (-1)*M_PI/6);
	DDA(game->player_x, game->player_y, inter_x,inter_y, game);
}