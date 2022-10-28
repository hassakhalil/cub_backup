/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:41:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/28 01:48:11 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_hor_inter(t_data *game, t_raydata *ray, double ang)
{
	double	ray_ang;

	ray_ang =  norm_angle(game->angle + ang);
	ray->inter_x = game->player_x;
	//first intersection
	ray->inter_y = floor(game->player_y / game->cube) * game->cube;
	if (ray_ang > 0 && ray_ang < M_PI)
	{
		//debug
		dprintf(2, "{check_hor_inter} ray is facing down\n");
		//end debug
		ray->inter_y += game->cube;
	}
	else
		ray->inter_y -= 1;
	ray->inter_x +=(game->player_y - ray->inter_y) / tan(ray_ang);
	//finding delta x and delta y
	ray->delta_y = game->cube;
	if (!(ray_ang > 0 && ray_ang < M_PI))
		ray->delta_y *= -1;
	ray->delta_x = game->cube / tan(ray_ang);
	if ((!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && ray->delta_x > 0) || ((ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && ray->delta_x < 0))
		ray->delta_x *= -1;
	//debug
	dprintf(2, "{check_hor_inter} deltaaa x == { %f }\n", ray->delta_x);
	dprintf(2, "{check_hor_inter} deltaaa y == { %f }\n", ray->delta_y);
	//end debug
	//debug
	dprintf(2, "{check_hor_inter} inter_x == [ %f ]\n", game->player_x);
	dprintf(2, "{check_hor_inter} inter_y == [ %f ]\n", game->player_y);
	//end debug
	while (wall(game, ray->inter_x, ray->inter_y) != 1)
	{
		ray->inter_x += ray->delta_x;
		ray->inter_y += ray->delta_y;
	}
	//debug
	dprintf(2, "{check_hor_inter} after checking for walls\n");
	//end debug

	ray->x_hor = ray->inter_x;
	ray->y_hor = ray->inter_y;
	ray->d_hor = hypot(ray->x_hor, ray->y_hor);
}

// void	check_ver_inter(t_data *game, t_raydata *ray, double ang)
// {
	
// }

void	get_inter_point(t_data *game, t_raydata *ray, double ang)
{
	//debug
	dprintf(2, "{get_inter_point}\n");
	//end debug
	
	//get horizontal inter point
	check_hor_inter(game, ray, ang);
	//debug
	dprintf(2,"{get_inter_point} after {check_ver_inter}\n");
	//end debug
	//get vertical inter point
	//check_ver_inter(game, ray, ang);
	//compare them and select the smallest
	// if (ray->d_hor < ray->d_ver)
	// {
		ray->inter_x = ray->x_hor;
		ray->inter_y = ray->y_hor;
	// }
	// else
	// {
	// 	ray->inter_x = ray->x_ver;
	// 	ray->inter_y = ray->y_ver;
	// }
	//debug
	dprintf(2, "inter_x == { %f } || inter_y == { %f }\n", ray->inter_x, ray->inter_y);
	//end debug
}

void	send_rays(t_data *game)
{
	t_raydata *ray0 = malloc(sizeof(t_raydata));
	//t_raydata *ray1 = malloc(sizeof(t_raydata));
	//t_raydata *ray2 = malloc(sizeof(t_raydata));
	//pass just the game and ray structs
	//send resolution_x rays and store the distances
	//draw with every ray with dda

	get_inter_point(game, ray0, 0);
	DDA(game->player_x, game->player_y, ray0->inter_x, ray0->inter_y, game);
	// get_inter_point(game, ray1, M_PI/6);
	// DDA(game->player_x, game->player_y, ray1->inter_x, ray1->inter_y, game);
	// get_inter_point(game, ray2, (-1)*M_PI/6);
	// DDA(game->player_x, game->player_y, ray2->inter_x, ray2->inter_y, game);
}