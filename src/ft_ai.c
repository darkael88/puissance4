/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:38:29 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 22:52:17 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static t_place	st_create_place(void)
{
	t_place		place;
	int			y;

	y = 0;
	while (y < 7)
	{
		place.human[y][0] = 0;
		place.human[y][1] = 0;
		place.ai[y][0] = 0;
		place.ai[y][1] = 0;
		y++;
	}
	return (place);
}

static void		st_ai_check_left(t_map *map, int y, int x, t_place *check)
{
	check->ai[1][0] = 0;
	check->ai[2][0] = 0;
	check->ai[3][0] = 0;
	if ((x - 1) >= 0 && y < map->size_y)
	{
		if (map->tab[y + 1] && map->tab[y + 1][x - 1] == ' ')
		{
			check->ai[1][0] = 1;
			ft_ai_weight_left_down(map, y - 1, x + 1, check);
		}
		else if (map->tab[y][x - 1] == ' ')
		{
			check->ai[2][0] = 1;
			ft_ai_weight_left(map, y, x + 1, check);
		}
		else if (y > 0 && map->tab[y - 1][x - 1] == ' ')
		{
			check->ai[3][0] = 1;
			ft_ai_weight_left_up(map, y + 1, x + 1, check);
		}
	}
}

static void		st_ai_check_right(t_map *map, int y, int x, t_place *check)
{
	check->ai[4][0] = 0;
	check->ai[5][0] = 0;
	check->ai[6][0] = 0;
	if ((x + 1) < map->size_x && y < map->size_y)
	{
		if (map->tab[y + 1] && map->tab[y + 1][x + 1] == ' ')
		{
			check->ai[4][0] = 1;
			ft_ai_weight_right_down(map, y - 1, x - 1, check);
		}
		else if (map->tab[y][x + 1] == ' ')
		{
			check->ai[5][0] = 1;
			ft_ai_weight_right(map, y, x - 1, check);
		}
		else if (y > 0 && map->tab[y - 1][x + 1] == ' ')
		{
			check->ai[6][0] = 1;
			ft_ai_weight_right_up(map, y + 1, x - 1, check);
		}
	}
}

static void		st_check_place(t_map *map, int y, t_place *check, int i)
{
	int			j;

	st_ai_check_left(map, y, map->last_x, check);
	st_ai_check_right(map, y, map->last_x, check);
	ft_check_turn_human(map, i, check);
	ft_ai_search_max(map, check);
	while (map->tab[0][i] != '\0')
	{
		j = 0;
		while (map->tab[j] && map->tab[j][i] == ' ')
			j++;
		if (map->tab[j] && map->tab[j][i] == 'O')
		{
			ft_check_turn_human(map, i, check);
			ft_human_max(map, i, check);
		}
		else if (map->tab[j] && map->tab[j][i] == 'X')
		{
			st_ai_check_left(map, j, i, check);
			st_ai_check_right(map, j, i, check);
			ft_ai_max(map, i, check);
		}
		i++;
	}
}

int				ft_ai(t_map *map)
{
	int			y;
	t_place		check;

	check = st_create_place();
	map->x_max = 0;
	map->max_weight = 0;
	if (map->last_x == -1)
		map->last_x = map->size_x / 2;
	else
	{
		y = 0;
		while (map->tab[0][map->last_x] == ' '
				&& map->tab[y] && map->tab[y][map->last_x] != ' ')
			y++;
		if (map->tab[y] && map->tab[y][map->last_x] == 'O')
			y++;
		else
			ft_check_place_ai_up(map, y, &check, 'X');
		st_check_place(map, y, &check, 0);
		map->last_x = map->x_max;
	}
	map->count = map->count + 1;
	ft_print_turn_ai(map->last_x);
	ft_place_piece(map, map->last_x, map->size_y - 1, 'X');
	return (ft_check_win(map, map->last_x, 'X'));
}
