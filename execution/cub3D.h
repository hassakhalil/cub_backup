/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:58:20 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/09 01:06:16 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include "../parsing/parse.h"

#define MOV_SPEED	10
#define ROT_SPEED	MOV_SPEED*M_PI/180
#define	CUBE		64
#define	FOV			M_PI/3
//minimap scale factor 
#define	MSF			0.1
#define RX			1600
#define	RY			1000

//texture struct

typedef struct s_texture
{
	char 	*t_file;
	int		t_width;
	int		t_height;
	void	*t_image;
	char	*t_addr;
	int		bpp;
	int		ll;
	int		end;
} t_texture;


//ray data struct
typedef struct	 s_raydata {

	double	inter_x;
	double	inter_y;
	double	d;
	int		v_or_h;
	int		wall;
}	t_raydata;

typedef struct	s_data {
	void	*mlx;
	void	*mlx_window;
	int		map_rows;
	int		map_columns;
	int 	map_length;
	int 	map_width;
	char	**map;
	double	player_x;
	double	player_y;
	double	angle;
	t_raydata	ray;
	t_raydata	rays[RX];
	t_texture	textures[4];
	int		floor;
	int		ceilling;
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
void	floor_ceilling(t_data *game);
int	ft_exit(t_data *game);
int	mouse_hook(int button, int x, int y,t_data *game);
void	read_texture(t_data *game);
unsigned int	get_pixel(t_texture *data, int x, int y);
#endif