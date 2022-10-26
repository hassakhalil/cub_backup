/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:41:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/26 14:42:17 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_hor_inter(t_data *game, t_raydata *ray, double ang)
{
	ray->delta_y = game->cube;
	if (!((game->angle + ang) > 0 && (game->angle + ang)< M_PI))
			ray->delta_y *= -1;
	ray->delta_x = game->cube / tan(game->angle + ang);
	if ((!((game->angle + ang) < M_PI_2  || (game->angle + ang) > 1.5*M_PI) && ray->delta_x > 0) || (((game->angle + ang) < M_PI_2  || (game->angle + ang) > 1.5*M_PI) && ray->delta_x < 0))
		ray->delta_x *= -1;
	while (!wall(game, ray->inter_x, ray->inter_x))
	{
		ray->inter_x += ray->delta_x;
		ray->inter_y += ray->delta_y;
	}
	ray->x_hor = ray->inter_x;
	ray->y_hor = ray->inter_y;
	ray->d_hor = hypot(ray->x_hor, ray->y_hor);
}

// void	check_ver_inter(t_data *game, t_raydata *ray, double ang)
// {
	
// }

void	get_inter_point(t_data *game, t_raydata *ray, double ang)
{
	//get first inter point
	ray->inter_y = floor(game->player_y / game->cube) * game->cube;
	if ((game->angle + ang)> 0 && (game->angle + ang) < M_PI)
		ray->inter_y += game->cube;
	ray->inter_x = game->player_x + (ray->inter_y - game->player_y) / tan(game->angle + ang);
	//get delta to check for other inter points
	ray->delta_y = game->cube;
	if (!((game->angle + ang) > 0 && (game->angle + ang)< M_PI))
			ray->delta_y *= -1;
	ray->delta_x = game->cube / tan(game->angle + ang);
	if ((!((game->angle + ang) < M_PI_2  || (game->angle + ang) > 1.5*M_PI) && ray->delta_x > 0) || (((game->angle + ang) < M_PI_2  || (game->angle + ang) > 1.5*M_PI) && ray->delta_x < 0))
		ray->delta_x *= -1;
	//get horizontal inter point
	check_hor_inter(game, ray, ang);
	//get vertical inter point
	//check_ver_inter(game, ray, ang);
	//compare them and select the smallest
	if (ray->d_hor < ray->d_ver)
	{
		ray->inter_x = ray->x_hor;
		ray->inter_y = ray->y_hor;
	}
	else
	{
		ray->inter_x = ray->x_ver;
		ray->inter_y = ray->y_ver;
	}
}

void	send_rays(t_data *game)
{
	t_raydata *ray0 = malloc(sizeof(t_raydata));
	t_raydata *ray1 = malloc(sizeof(t_raydata));
	t_raydata *ray2 = malloc(sizeof(t_raydata));
	//pass just the game and ray structs
	//send resolution_x rays and store the distances
	//draw with every ray with dda

	get_inter_point(game, ray0, 0);
	DDA(game->player_x, game->player_y, ray0->inter_x, ray0->inter_y, game);
	get_inter_point(game, ray1, M_PI/6);
	DDA(game->player_x, game->player_y, ray1->inter_x, ray1->inter_y, game);
	get_inter_point(game, ray2, (-1)*M_PI/6);
	DDA(game->player_x, game->player_y, ray2->inter_x, ray2->inter_y, game);
}