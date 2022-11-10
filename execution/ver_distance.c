/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:47:27 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 08:52:50 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	first_inter_ver(t_data *game, double ray_ang, double *correctv)
{
	*correctv = 0;
	game->ray.x_ver = floor(game->player_x / CUBE) * CUBE;
	if (ray_ang < M_PI_2 || ray_ang > 1.5 * M_PI)
		game->ray.x_ver += CUBE;
	else
		*correctv = -1;
	game->ray.y_ver = game->player_y
		+ (game->ray.x_ver - game->player_x) * tan(ray_ang);
}

void	delta_ver(double ray_ang, double *delta_yv, double *delta_xv)
{
	*delta_xv = CUBE;
	if (!(ray_ang < M_PI_2 || ray_ang > 1.5 * M_PI))
		*delta_xv *= -1;
	*delta_yv = CUBE * tan(ray_ang);
	if ((!(ray_ang > 0 && ray_ang < M_PI) && *delta_yv > 0)
		|| ((ray_ang > 0 && ray_ang < M_PI) && *delta_yv < 0))
		*delta_yv *= -1;
}

void	get_ver(t_data *game, double ray_ang)
{
	double	correctv;
	double	delta_xv;
	double	delta_yv;

	game->ray.flag_ver = 0;
	first_inter_ver(game, ray_ang, &correctv);
	delta_ver(ray_ang, &delta_yv, &delta_xv);
	while (1)
	{
		if (game->ray.x_ver > 0 && game->ray.y_ver > 0 && game->ray.x_ver
			< game->map_width && game->ray.y_ver < game->map_length)
		{
			if (wall(game, game->ray.x_ver + correctv, game->ray.y_ver, 0) == 1)
				break ;
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
