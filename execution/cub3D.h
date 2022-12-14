/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:58:20 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 09:51:44 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "../parsing/parse.h"

# define MOV_SPEED	10
# define ROT_SPEED	0.17453292519
# define CUBE		64
# define FOV		1.0471975512
# define RX			1600
# define RY			1000

//texture struct

typedef struct s_texture
{
	char	*t_file;
	int		t_width;
	int		t_height;
	void	*t_image;
	char	*t_addr;
	int		bpp;
	int		ll;
	int		end;
}	t_texture;

//ray data struct
typedef struct s_raydata {
	double	inter_x;
	double	inter_y;
	char	v_or_h;
	char	wall;
	int		flag_ver;
	int		flag_hor;
	double	x_ver;
	double	y_ver;
	double	x_hor;
	double	y_hor;
}	t_raydata;

typedef struct s_data {
	void			*mlx;
	void			*mlx_window;
	int				map_rows;
	int				map_columns;
	int				map_length;
	int				map_width;
	char			**map;
	double			player_x;
	double			player_y;
	double			angle;
	double			d2pp;	
	t_raydata		ray;
	t_texture		textures[4];
	int				floor;
	int				ceilling;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

int				key_hook(int keycode, t_data *game);
int				wall(t_data *game, double x, double y, int flag);
void			draw_map_rays(t_data *game);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			get_inter_point(t_data *game, double ang);
void			render_walls(t_data *game);
double			norm_angle(double angle);
double			ft_angle(char c);
void			floor_ceilling(t_data *game);
void			read_texture(t_data *game);
unsigned int	get_pixel(t_texture *data, int x, int y);
int				ft_exit(t_data *game, int flag);
void			update(t_data *game);
void			get_ver(t_data *game, double ray_ang);
void			get_hor(t_data *game, double ray_ang);
void			game_init(t_data *game, t_info *info);
#endif