/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:20:21 by fstitou           #+#    #+#             */
/*   Updated: 2022/11/11 20:02:46 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	only_space1(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_map1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (is_blank(s[i]))
	{
		while (is_blank(s[i]))
			i++;
	}
	if (s[i] == '1' || s[i] == '0')
		return (1);
	return (0);
}

void	errors(int err)
{
	if (err == 1)
	{
		write(2, "Error in the file\n", 19);
		exit(1);
	}
}

char	*fill_spaces(char *map_x, char *to_fill, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map_x[i])
	{
		to_fill[j] = map_x[i];
		j++;
		i++;
	}
	while (j < size)
	{
		to_fill[j] = ' ';
		j++;
	}
	to_fill[j] = '\0';
	return (to_fill);
}

char	**id_check(char **tab, t_parse *p)
{
	if (map_len(tab) != 6)
		p->flag = 1;
	return (tab);
}
