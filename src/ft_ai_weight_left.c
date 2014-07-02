/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ai_weight_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 13:40:53 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 18:21:04 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

void		ft_ai_weight_left_down(t_map *map, int y, int x, t_place *check)
{
	int		count;

	count = 0;
	while (y >= 0 && (x + 1) < map->size_x && map->tab[y][x] == 'X')
	{
		count = count + 3;
		y--;
		x++;
	}
	if (y < 0 || map->tab[y][x] == 'O')
		count++;
	else
		count = count + 2;
	check->ai[1][1] = count;
}

void		ft_ai_weight_left(t_map *map, int y, int x, t_place *check)
{
	int		count;

	count = 0;
	while ((x + 1) < map->size_x && map->tab[y][x] == 'X')
	{
		count = count + 3;
		x++;
	}
	if (x == map->size_x || map->tab[y][x] == 'O')
		count++;
	else
		count = count + 2;
	check->ai[2][1] = count;
}

void		ft_ai_weight_left_up(t_map *map, int y, int x, t_place *check)
{
	int		count;

	count = 0;
	while (map->tab[y] && (x + 1) < map->size_x && map->tab[y][x] == 'X')
	{
		count = count + 3;
		y++;
		x++;
	}
	if (map->tab[y] == NULL || map->tab[y][x] == 'O')
		count++;
	else
		count = count + 2;
	check->ai[3][1] = count;
}
