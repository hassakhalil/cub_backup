/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:41:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/28 05:09:47 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	hor_inter(t_data *game, t_raydata *ray, double ang)
{
	double	ray_ang;

	ray_ang =  norm_angle(ang);
	//first intersection
	ray->y_hor = floor(game->player_y / game->cube) * game->cube;
	if (ray_ang > 0 && ray_ang < M_PI)
		ray->y_hor += game->cube;
	else
		ray->y_hor -= 1;
	ray->x_hor = game->player_x + (ray->y_hor - game->player_y) / tan(ray_ang);
	//finding delta x and delta y
	ray->delta_y = game->cube;
	if (!(ray_ang > 0 && ray_ang < M_PI))
		ray->delta_y *= -1;
	ray->delta_x = game->cube / tan(ray_ang);
	if ((!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && ray->delta_x > 0) || ((ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && ray->delta_x < 0))
		ray->delta_x *= -1;
	while (wall(game, ray->x_hor, ray->y_hor) != 1 &&ray->x_hor > 0 && ray->y_hor > 0 && ray->x_hor < game->window_width && ray->y_hor < game->window_length)
	{
		ray->x_hor += ray->delta_x;
		ray->y_hor += ray->delta_y;
	}
	ray->d_hor = hypot(game->player_x - ray->x_hor, game->player_y - ray->y_hor);
}

void	ver_inter(t_data *game, t_raydata *ray, double ang)
{
	double	ray_ang;

	ray_ang = norm_angle(ang);
		//first intersection
	ray->x_ver = floor(game->player_x / game->cube) * game->cube;
	if (ray_ang < M_PI_2  || ray_ang > 1.5*M_PI)
		ray->x_ver += game->cube;
	else
		ray->x_ver -= 1;
	ray->y_ver = game->player_y + (ray->x_ver - game->player_x)*tan(ray_ang);
	//finding delta y and delta x
	ray->delta_x = game->cube;
	if (!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI))
		ray->delta_x *= -1;
	ray->delta_y = game->cube * tan(ray_ang);
	if ((!(ray_ang > 0 && ray_ang < M_PI) && ray->delta_y > 0) || ((ray_ang > 0 && ray_ang < M_PI) && ray->delta_y < 0))
		ray->delta_y *= -1;
	while (wall(game, ray->x_ver, ray->y_ver) != 1 &&ray->x_ver > 0 && ray->y_ver > 0 && ray->x_ver < game->window_width && ray->y_ver < game->window_length)
	{
		ray->x_ver += ray->delta_x;
		ray->y_ver += ray->delta_y;
	}
	ray->d_ver = hypot(game->player_x - ray->x_ver, game->player_y - ray->y_ver);
}

void	get_inter_point(t_data *game, t_raydata *ray, double ang)
{
	//debug
	dprintf(2, "{get_inter_point}\n");
	//end debug
	
	//get horizontal inter point
	hor_inter(game, ray, ang);
	ver_inter(game, ray, ang);
	//compare them and select the smallest
	if (ray->d_hor < ray->d_ver)
	{
		ray->inter_x = ray->x_hor;
		ray->inter_y = ray->y_hor;
		ray->d = ray->d_hor;
	}
	else
	{
	 	ray->inter_x = ray->x_ver;
	 	ray->inter_y = ray->y_ver;
		ray->d = ray->d_ver;
	}
	//debug
	dprintf(2, "{ get_inter_point } d_hor ==== [ %f ] & d_ver ==== [ %f ]", ray->d_hor, ray->d_ver);
	dprintf(2, "{ get_inter_point } d =================== [ %f ]", ray->d);
	//end debug
}

void	send_rays(t_data *game)
{
	int	i;
	double	ray_angle;
	t_raydata *ray0 = malloc(sizeof(t_raydata));
	//t_raydata *ray1 = malloc(sizeof(t_raydata));
	//t_raydata *ray2 = malloc(sizeof(t_raydata));

	ray_angle = game->angle - game->fov/2;
	i = 0;
	while (i < game->num_of_rays)
	{
		get_inter_point(game, ray0, ray_angle);
		DDA(game->player_x, game->player_y, ray0->inter_x, ray0->inter_y, game);
		ray_angle += game->fov / game->num_of_rays;
		i++;
	}
	// get_inter_point(game, ray1, M_PI/6);
	// DDA(game->player_x, game->player_y, ray1->inter_x, ray1->inter_y, game);
	// get_inter_point(game, ray2, (-1)*M_PI/6);
	// DDA(game->player_x, game->player_y, ray2->inter_x, ray2->inter_y, game);
}