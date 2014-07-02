/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ai_weight_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 13:41:04 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 18:21:23 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

void		ft_ai_weight_right_down(t_map *map, int y, int x, t_place *check)
{
	int		count;

	count = 0;
	while (y >= 0 && x >= 0 && map->tab[y][x] == 'X')
	{
		count = count + 3;
		y--;
		x--;
	}
	if (y < 0 || x < 0 || map->tab[y][x] == 'O')
		count++;
	else
		count = count + 2;
	check->ai[4][1] = count;
}

void		ft_ai_weight_right(t_map *map, int y, int x, t_place *check)
{
	int		count;

	count = 0;
	while (x >= 0 && map->tab[y][x] == 'X')
	{
		count = count + 3;
		x--;
	}
	if (x < 0 || map->tab[y][x] == 'O')
		count++;
	else
		count = count + 2;
	check->ai[5][1] = count;
}

void		ft_ai_weight_right_up(t_map *map, int y, int x, t_place *check)
{
	int		count;

	count = 0;
	while (map->tab[y] && x >= 0 && map->tab[y][x] == 'X')
	{
		count = count + 3;
		y++;
		x--;
	}
	if (map->tab[y] == NULL || map->tab[y][x] == 'O')
		count++;
	else
		count = count + 2;
	check->ai[6][1] = count;
}
