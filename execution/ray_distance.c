/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:35:08 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 08:50:51 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

	d_ver = hypot(game->player_x - game->ray.x_ver,
			game->player_y - game->ray.y_ver);
	d_hor = hypot(game->player_x - game->ray.x_hor,
			game->player_y - game->ray.y_hor);
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

	ray_ang = norm_angle(ang);
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
	else if (ray_ang < M_PI_2 || ray_ang > 1.5 * M_PI)
		game->ray.wall = 'E';
	else
		game->ray.wall = 'W';
}
