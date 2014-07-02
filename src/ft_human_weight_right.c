/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_human_weight_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 17:56:32 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 19:40:07 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

void	ft_human_weight_right_down(t_map *map, int y, int x, t_place *check)
{
	int	count;

	count = 0;
	while (y >= 0 && x >= 0 && map->tab[y][x] == 'O')
	{
		count = count + 3;
		y--;
		x--;
	}
	if (y < 0 || x < 0 || map->tab[y][x] == 'X')
		count++;
	else if (count < 9)
		count = count + 2;
	else
		count = 100;
	check->human[4][1] = count;
}

void	ft_human_weight_right(t_map *map, int y, int x, t_place *check)
{
	int	count;

	count = 0;
	while (x >= 0 && map->tab[y][x] == 'O')
	{
		count = count + 3;
		x--;
	}
	if (x < 0 || map->tab[y][x] == 'X')
		count++;
	else if (count < 9)
		count = count + 2;
	else
		count = 100;
	check->human[5][1] = count;
}

void	ft_human_weight_right_up(t_map *map, int y, int x, t_place *check)
{
	int	count;

	count = 0;
	while (map->tab[y] && x >= 0 && map->tab[y][x] == 'O')
	{
		count = count + 3;
		y++;
		x--;
	}
	if (map->tab[y] == NULL || map->tab[y][x] == 'X')
		count++;
	else if (count < 9)
		count = count + 2;
	else
		count = 100;
	check->human[6][1] = count;
}
