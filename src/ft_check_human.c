/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_human.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 18:07:21 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 22:51:26 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static void		ft_human_check_left(t_map *map, int y, int x, t_place *check)
{
	if ((x - 1) >= 0 && y < map->size_y)
	{
		if (map->tab[y + 1] && map->tab[y + 1][x - 1] == ' ')
		{
			check->human[1][0] = 1;
			ft_human_weight_left_down(map, y - 1, x + 1, check);
		}
		else if (map->tab[y][x - 1] == ' ')
		{
			check->human[2][0] = 1;
			ft_human_weight_left(map, y, x + 1, check);
		}
		else if (y > 0 && map->tab[y - 1][x - 1] == ' ')
		{
			check->human[3][0] = 1;
			ft_human_weight_left_up(map, y + 1, x + 1, check);
		}
	}
}

static void		ft_human_check_right(t_map *map, int y, int x, t_place *check)
{
	if ((x + 1) < map->size_x && y < map->size_y)
	{
		if (map->tab[y + 1] && map->tab[y + 1][x + 1] == ' ')
		{
			check->human[4][0] = 1;
			ft_human_weight_right_down(map, y - 1, x - 1, check);
		}
		else if (map->tab[y][x + 1] == ' ')
		{
			check->human[5][0] = 1;
			ft_human_weight_right(map, y, x - 1, check);
		}
		else if (y > 0 && map->tab[y - 1][x + 1] == ' ')
		{
			check->human[6][0] = 1;
			ft_human_weight_right_up(map, y + 1, x - 1, check);
		}
	}
}

void			ft_check_turn_human(t_map *map, int x, t_place *check)
{
	int			y;

	if (map->last_human_x != -1)
	{
		y = 0;
		while (map->tab[0][x] == ' '
				&& map->tab[y] && map->tab[y][x] == ' ')
			y++;
		ft_check_place_ai_up(map, y, check, 'O');
		ft_human_check_left(map, y, x, check);
		ft_human_check_right(map, y, x, check);
	}
}
