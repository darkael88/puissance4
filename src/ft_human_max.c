/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_human_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 22:14:41 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 22:22:32 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static int	st_check_another(t_map *map)
{
	int		x;

	x = 0;
	while (map->tab[0][x] != ' ')
		x++;
	return (x);
}

static int	st_check_place_max(t_map *map, int tab[14], int *tmp, int x)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (i < 6)
	{
		if (tab[max] < tab[i + 1])
			max = i + 1;
		i++;
	}
	if (tab[max] <= 0)
		return (st_check_another(map));
	*tmp = max;
	if (max == 0)
		return (x);
	else if (max <= 3)
		return (x - 1);
	return (x + 1);
}

int			ft_human_max(t_map *map, int x, t_place *check)
{
	int		i;
	int		tab[7];
	int		tmp;
	int		max;

	i = 0;
	while (i < 7)
	{
		tab[i] = check->human[i - 7][0] * check->human[i - 7][1];
		i++;
	}
	max = 0;
	tmp = st_check_place_max(map, tab, &max, x);
	if (map->max_weight < tab[max])
	{
		map->x_max = tmp;
		map->max_weight = tab[max];
	}
	return (map->max_weight);
}
