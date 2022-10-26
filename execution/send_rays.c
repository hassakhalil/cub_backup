/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:41:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/26 11:18:02 by hkhalil          ###   ########.fr       */
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

void	get_inter_point(t_data *game, double *inter_x, double *inter_y, double ang)
{
	double	delta_x;
	double	delta_y;
	
	//this is first inter point
	*inter_y = floor(game->player_y / game->cube) * game->cube;
	if (game->angle > 0 && game->angle < M_PI)
		*inter_y += game->cube;
	*inter_x = game->player_x + (*inter_y - game->player_y) / tan(game->angle);
	delta_y = game->cube;
	if (!(game->angle > 0 && game->angle < M_PI))
			delta_y *= -1;
	delta_x = game->cube / tan(game->angle);
	if ((!(game->angle < M_PI_2  || game->angle > 1.5*M_PI) && delta_x > 0) || ((game->angle < M_PI_2  || game->angle > 1.5*M_PI) && delta_x < 0))
		delta_x *= -1;
	//check_hor_inter
	//check_ver_inter
	//compare
	//get the smallest distance
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