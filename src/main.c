/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:22:51 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 17:37:55 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static char	*st_init_coor(int x)
{
	char	*tab;
	int		i;
	int		j;

	if (!(tab = (char *)malloc(sizeof(char) * (x * 2 + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < x)
	{
		if ((tab[i] = (j % 100) / 10 + '0') == '0')
			tab[i] = ' ';
		i++;
		tab[i] = (j % 10) + '0';
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	st_ai_first(t_map *map, int y, int x)
{
	ft_print_map(map, -1, 0, 0);
	ft_putchar('\n');
	ft_print_turn_ai(x / 2);
	ft_place_piece(map, x / 2, y - 1, 'X');
	map->count = map->count + 1;
}

static void	st_clean_map(t_map *map)
{
	ft_delfulltab((void ***)&map->tab);
	ft_memdel((void **)&map->coor);
	map = NULL;
}

static void	st_human_vs_ai(t_map *map, int y, int x)
{
	map->last_x = -1;
	if (ft_first_player() == 2)
	{
		st_ai_first(map, y, x);
		map->last_x = x / 2;
	}
	else
		ft_print_map(map, -1, 0, 0);
	ft_read_ai(map, x, y);
}

int			main(int ac, char **av)
{
	t_map	map;

	if (ac != 4 && ac != 3)
		return (ft_error_argv(ac));
	if (ac == 4 && ft_strcmp(av[3], "-p2") != 0)
		return (ft_error_argv(ac));
	if ((map.size_y = ft_check_number(av[1])) < 6)
		return (ft_error_number(map.size_y, 'y'));
	if ((map.size_x = ft_check_number(av[2])) < 7)
		return (ft_error_number(map.size_x, 'x'));
	if (((map.size_x + 1) * (map.size_y + 1)) > 1000000000)
		return (ft_error_too_memory());
	if (!(map.tab = ft_create_map(map.size_y, map.size_x)))
		return (ft_error_malloc());
	if (!(map.coor = st_init_coor(map.size_x)))
		return (ft_error_malloc());
	map.max = map.size_x * map.size_y;
	map.count = 0;
	map.last_human_x = -1;
	if (ac == 4)
		ft_game_human(&map, map.size_y, map.size_x);
	else
		st_human_vs_ai(&map, map.size_y, map.size_x);
	st_clean_map(&map);
	return (0);
}
