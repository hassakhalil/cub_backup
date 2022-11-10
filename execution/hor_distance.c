/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:49:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 08:52:45 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	first_inter_hor(t_data *game, double ray_ang, double *correcth)
{
	*correcth = 0;
	game->ray.y_hor = floor(game->player_y / CUBE) * CUBE;
	if (ray_ang > 0 && ray_ang < M_PI)
		game->ray.y_hor += CUBE;
	else
		*correcth = -1;
	game->ray.x_hor = game->player_x
		+ (game->ray.y_hor - game->player_y) / tan(ray_ang);
}

void	delta_hor(double ray_ang, double *delta_yh, double *delta_xh)
{
	*delta_yh = CUBE;
	if (!(ray_ang > 0 && ray_ang < M_PI))
		*delta_yh *= -1;
	*delta_xh = CUBE / tan(ray_ang);
	if ((!(ray_ang < M_PI_2 || ray_ang > 1.5 * M_PI)
			&& *delta_xh > 0) || ((ray_ang < M_PI_2
				|| ray_ang > 1.5 * M_PI) && *delta_xh < 0))
		*delta_xh *= -1;
}

void	get_hor(t_data *game, double ray_ang)
{
	double	correcth;
	double	delta_xh;
	double	delta_yh;

	game->ray.flag_hor = 0;
	first_inter_hor(game, ray_ang, &correcth);
	delta_hor(ray_ang, &delta_yh, &delta_xh);
	while (1)
	{
		if (game->ray.x_hor > 0 && game->ray.y_hor > 0 && game->ray.x_hor
			< game->map_width && game->ray.y_hor < game->map_length)
		{
			if (wall(game, game->ray.x_hor, game->ray.y_hor + correcth, 0) == 1)
				break ;
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
