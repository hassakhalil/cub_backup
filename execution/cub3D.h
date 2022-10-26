/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:58:20 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/26 14:36:28 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_window;
	int	map_rows;
	int	map_columns;
	double	resolution_x;
	double	resolution_y;
	double	cube;
	int window_length;
	int window_width;
	//map file
	//char	*file_name;
	//fill the map here
	char	**map;
	double	player_x;
	double	player_y;
	double	angle;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//ray data struct
typedef struct	 s_raydata {

	double	inter_x;
	double	inter_y;
	double	d;
	double	d_hor;
	double	d_ver;
	double	x_hor;
	double	y_hor;
	double	x_ver;
	double	y_ver;
	double	delta_x;
	double	delta_y;
}	t_raydata;

void	render(t_data *game);
void DDA(double x1, double y1, double x2, double y2, t_data *game);
int	key_hook(int keycode, t_data *game);
int	wall(t_data *game, double x, double y);
void	send_rays(t_data *game);
void	render(t_data *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void	map_2d(/*take struct of data*/);
#endif