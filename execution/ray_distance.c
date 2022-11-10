/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:35:08 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 07:44:44 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_hor(t_data *game, double ray_ang)
{
	double	correcth;
	double	delta_xh;
	double	delta_yh;

	game->ray.flag_hor = 0;
	///hor_inter code
	//first intersection
	correcth = 0;
	game->ray.y_hor = floor(game->player_y / CUBE) * CUBE;
	if (ray_ang > 0 && ray_ang < M_PI)
		game->ray.y_hor += CUBE;
	else
		correcth = -1;
	game->ray.x_hor = game->player_x + (game->ray.y_hor - game->player_y) / tan(ray_ang);
	//finding delta x and delta y
	delta_yh = CUBE;
	if (!(ray_ang > 0 && ray_ang < M_PI))
		delta_yh *= -1;
	delta_xh = CUBE / tan(ray_ang);
	if ((!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && delta_xh > 0) || ((ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && delta_xh < 0))
		delta_xh *= -1;
	while (1)
	{
		if (game->ray.x_hor > 0 && game->ray.y_hor > 0 && game->ray.x_hor < game->map_width && game->ray.y_hor < game->map_length)
		{
			if (wall(game, game->ray.x_hor, game->ray.y_hor + correcth, 0) == 1)
				break;
			game->ray.x_hor += delta_xh;
			game->ray.y_hor += delta_yh;
		}
		else
		{
			game->ray.flag_hor = -1;
			break ;
		}
	}
}

void	get_ver(t_data *game, double ray_ang)
{
	double	correctv;
	double	delta_xv;
	double	delta_yv;

	game->ray.flag_ver = 0;
	//ver_inter
	//first intersection
	correctv = 0;
	game->ray.x_ver = floor(game->player_x / CUBE) * CUBE;
	if (ray_ang < M_PI_2  || ray_ang > 1.5*M_PI)
		game->ray.x_ver += CUBE;
	else
		correctv = -1;
	game->ray.y_ver = game->player_y + (game->ray.x_ver - game->player_x)*tan(ray_ang);
	//finding delta y and delta x
	delta_xv = CUBE;
	if (!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI))
		delta_xv *= -1;
	delta_yv = CUBE * tan(ray_ang);
	if ((!(ray_ang > 0 && ray_ang < M_PI) && delta_yv > 0) || ((ray_ang > 0 && ray_ang < M_PI) && delta_yv < 0))
		delta_yv *= -1;
		while (1)
	{
		if (game->ray.x_ver > 0 && game->ray.y_ver > 0 && game->ray.x_ver < game->map_width && game->ray.y_ver < game->map_length)
		{
			if (wall(game, game->ray.x_ver + correctv, game->ray.y_ver, 0) == 1)
				break;
			game->ray.x_ver += delta_xv;
			game->ray.y_ver += delta_yv;
		}
		else
		{
			game->ray.flag_ver = -1;
			break ;
		}
	}
}

void	check_flag(t_data *game)
{
	if (game->ray.flag_ver)
	{
		game->ray.inter_x = game->ray.x_hor;
		game->ray.inter_y = game->ray.y_hor;
		game->ray.v_or_h = 'h';
	}
	else
	{
		game->ray.inter_x = game->ray.x_ver;
		game->ray.inter_y = game->ray.y_ver;
		game->ray.v_or_h = 'v';
	}
}

void	compare_d(t_data *game)
{
	double	d_ver;
	double	d_hor;

	d_ver = hypot(game->player_x - game->ray.x_ver, game->player_y - game->ray.y_ver);
	d_hor = hypot(game->player_x - game->ray.x_hor, game->player_y - game->ray.y_hor);
	if (d_hor > d_ver)
	{
		game->ray.inter_x = game->ray.x_ver;
		game->ray.inter_y = game->ray.y_ver;
		game->ray.v_or_h = 'v';
	}
	else
	{
		game->ray.inter_x = game->ray.x_hor;
		game->ray.inter_y = game->ray.y_hor;
		game->ray.v_or_h = 'h';
	}
}

void	get_inter_point(t_data *game, double ang)
{
	double	ray_ang;

	ray_ang =  norm_angle(ang);
	get_hor(game, ray_ang);
	get_ver(game, ray_ang);
	if (game->ray.flag_ver || game->ray.flag_hor)
		check_flag(game);
	else
		compare_d(game);
	if (ray_ang > 0 && ray_ang < M_PI && game->ray.v_or_h == 'h')
		game->ray.wall = 'S';
	else if (game->ray.v_or_h == 'h')
		game->ray.wall = 'N';
	 else if (ray_ang < M_PI_2 || ray_ang > 1.5*M_PI)
	 	game->ray.wall = 'E';
	else
	 	game->ray.wall = 'W';
}