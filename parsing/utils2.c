/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:32:32 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/11 19:34:41 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**f_malloc(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 100000);
	if (!map)
		return (NULL);
	return (map);
}

void	thecheck(int i, int *pos, char **map, t_parse *p)
{
	if ((i == 0 && !map_closed(map[i])))
		p->map_open = 1;
	if (i > 0 && map[i + 1] != 0 && !closed_sides(map[i]))
		p->map_open = 1;
	if (map[i + 1] == 0 || !is_map(map[i + 1]))
		if (!map_closed(map[i]))
			p->map_open = 1;
	if (invalid_char(map[i]))
		p->wg_char = 1;
	if (check_position(map[i]))
		*pos += check_position(map[i]);
}

void	free_struct(t_info *info)
{
	if (info)
		free(info);
}
