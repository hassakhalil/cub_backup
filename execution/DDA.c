/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:32:10 by hkhalil           #+#    #+#             */
/*   Updated: 2022/10/25 00:33:15 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void DDA(double x1, double y1, double x2, double y2, t_data *game)
{
  double x;
  double y;
  double dx, dy, step;
  int i;
   
  dx = (x2 - x1);
  dy = (y2 - y1);
  if (fabs(dx) >= fabs(dy))
    step = fabs(dx);
  else
    step = fabs(dy);
  dx = dx / step;
  dy = dy / step;
  x = x1;
  y = y1;
  i = 1;
  while (i <= step) {
	my_mlx_pixel_put(game, x, y, 0x800000);
    x = x + dx;
    y = y + dy;
    i = i + 1;
  }
}