/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:41:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/29 22:40:31 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_inter_point(t_data *game, t_raydata *ray, double ang)
{
	double	ray_ang;
	double	correcth;
	double	correctv;
	
	ray_ang =  norm_angle(ang);
	///hor_inter code
	//first intersection
	correcth = 0;
	ray->y_hor = floor(game->player_y / game->cube) * game->cube;
	if (ray_ang > 0 && ray_ang < M_PI)
		ray->y_hor += game->cube;
	else
		correcth = -1;
	ray->x_hor = game->player_x + (ray->y_hor - game->player_y) / tan(ray_ang);
	//finding delta x and delta y
	ray->delta_yh = game->cube;
	if (!(ray_ang > 0 && ray_ang < M_PI))
		ray->delta_yh *= -1;
	ray->delta_xh = game->cube / tan(ray_ang);
	if ((!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && ray->delta_xh > 0) || ((ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && ray->delta_xh < 0))
		ray->delta_xh *= -1;

	//ver_inter
	//first intersection
	correctv = 0;
	ray->x_ver = floor(game->player_x / game->cube) * game->cube;
	if (ray_ang < M_PI_2  || ray_ang > 1.5*M_PI)
		ray->x_ver += game->cube;
	else
		correctv = -1;
	ray->y_ver = game->player_y + (ray->x_ver - game->player_x)*tan(ray_ang);
	//finding delta y and delta x
	ray->delta_xv = game->cube;
	if (!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI))
		ray->delta_xv *= -1;
	ray->delta_yv = game->cube * tan(ray_ang);
	if ((!(ray_ang > 0 && ray_ang < M_PI) && ray->delta_yv > 0) || ((ray_ang > 0 && ray_ang < M_PI) && ray->delta_yv < 0))
		ray->delta_yv *= -1;
	while (1)
	{
		if (ray->x_ver > 0 && ray->y_ver > 0 && ray->x_ver < game->window_width && ray->y_ver < game->window_length)
		{
			if (wall(game, ray->x_ver + correctv, ray->y_ver) == 1)
			{
				ray->inter_x = ray->x_ver;
				ray->inter_y = ray->y_ver;
				ray->d = hypot(game->player_x - ray->x_ver, game->player_y - ray->y_ver);
				break;
			}
			ray->x_ver += ray->delta_xv;
			ray->y_ver += ray->delta_yv;
		}
		if (ray->x_hor > 0 && ray->y_hor > 0 && ray->x_hor < game->window_width && ray->y_hor < game->window_length)
		{
			if (wall(game, ray->x_hor, ray->y_hor + correcth) == 1)
			{
				ray->inter_x = ray->x_hor;
				ray->inter_y = ray->y_hor;
				ray->d = hypot(game->player_x - ray->x_hor, game->player_y - ray->y_hor);
				break;
			}
			ray->x_hor += ray->delta_xh;
			ray->y_hor += ray->delta_yh;
		}
	}
	my_mlx_pixel_put(game, ray->inter_x, ray->inter_y, 0xFFFF00);
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
}