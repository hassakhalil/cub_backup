/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:18:17 by hkhalil           #+#    #+#             */
/*   Updated: 2022/11/09 02:17:54 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	norm_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

double	ft_angle(char c)
{
	double	angle;

	if (c == 'N')
		angle = 1.5 * M_PI;
	else if (c == 'S')
		angle = M_PI_2;
	else if (c == 'W')
		angle = M_PI;
	else
		angle = 0;
	return (angle);
}
