/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:48:01 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/04 04:42:34 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**fill_map(char **tab, int flag)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = f_malloc();
	while (tab && tab[i])
	{
		if (is_map1(tab[i]))
		{
			while (tab[i] && is_map(tab[i]) && flag)
			{
				if (tab && tab[i][0] == '\0')
					break ;
				map[j++] = ft_strdup(tab[i++]);
			}
			while (tab[i] && !flag)
				map[j++] = ft_strdup(tab[i++]);
			break ;
		}
		i++;
	}
	map[j] = NULL;
	return (map);
}

int	closed_sides(char *str)
{
	int	i;

	i = 0;
	if (only_space1(str))
		return (1);
	while (str && is_blank(str[i]))
		i++;
	if (str && str[i] && str[i] != '1')
		return (0);
	while (str && str[i])
		i++;
	i--;
	if (str && is_blank(str[i]))
		while (is_blank(str[i]))
			i--;
	if (str && str[i] != '1')
		return (0);
	return (1);
}

t_parse	*final_check(char **rest, t_parse *p, int pos)
{
	int	i;

	i = 0;
	if (pos == 0 && !p->flag)
		p->no_pos = 1;
	if (pos > 1 && !p->flag)
		p->m_pos = 1;
	while (rest[i] && !p->flag)
	{
		if (rest[i][0] != '\0' && !only_space1(rest[i]))
		{
			p->m_end = 1;
			break ;
		}
		i++;
	}
	return (p);
}

t_parse	*m_check(char **map, t_parse *p)
{
	if (!p->flag)
		if (!internal_check(map))
			p->map_open = 1;
	return (p);
}

t_parse	*parse_map(char **map, t_parse *p)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	if (map[0] == 0)
		p->no_map = 1;
	else
	{	
		while (map && map[i] && is_map(map[i]) && !p->flag)
		{
			if (map && map[i][0] == '\0')
				break ;
			thecheck(i, &pos, map, p);
			i++;
		}
		p = final_check(map + i, p, pos);
	}
	return (m_check(map, p));
}
