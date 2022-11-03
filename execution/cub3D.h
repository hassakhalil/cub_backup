/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:58:20 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/03 04:21:01 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include "../parsing/parse.h"

#define MOV_SPEED	8
#define ROT_SPEED	MOV_SPEED*M_PI/180
#define	CUBE		32
#define	FOV			M_PI/3
//minimap scale factor 
#define	MSF			0.2
#define RX			1600
#define	RY			1600

typedef struct	s_data {
	void	*mlx;
	void	*mlx_window;
	int	map_rows;
	int	map_columns;
	double	resolution_x;
	double	resolution_y;
	int map_length;
	int map_width;
	char	**map;
	double	player_x;
	double	player_y;
	double	angle;
	void	*img;
	char	*addr;
	void	*m_img;
	char	*m_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_data;

//ray data struct
typedef struct	 s_raydata {

	double	inter_x;
	double	inter_y;
	int		hit;
}	t_raydata;

void	render_map(t_data *game);
void 	DDA(double x1, double y1, double x2, double y2, t_data *game, int color);
int		key_hook(int keycode, t_data *game);
int		wall(t_data *game, double x, double y, int flag);
void	draw_map_rays(t_data *game);
void	render_map(t_data *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double 	norm_angle(double angle);
void	get_inter_point(t_data *game, t_raydata *t_raydata, double ang);
void	render_walls(t_data *game);
double 	norm_angle(double angle);
double	ft_angle(char c);
#endif