/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:21:05 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/10 09:45:33 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3D.h"

# define MSF		0.1

int		mouse_hook(int button, int x, int y, t_data *game);
void	update_bonus(t_data *game);
int		key_hook_bonus(int keycode, t_data *game);
void	render_map(t_data *game);
void	game_init_bonus(t_data *game, t_info *info);
#endif