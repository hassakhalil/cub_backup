/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:58:20 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/23 01:14:40 by hkhalil          ###   ########.fr       */
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

void	render(t_data *game);
//void	map_2d(/*take struct of data*/);
#endif