/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:25:12 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 22:04:34 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

int				ft_check_count_win(int count, char c)
{
	if (count >= 4)
	{
		if (c == 'O')
			return (1);
		else
			return (2);
	}
	return (0);
}

static int		st_check_vertical(t_map *map, int x, char c)
{
	int			i;
	int			count;
	int			ret;

	i = 0;
	ret = 0;
	while (map->tab[i])
	{
		count = 0;
		while (map->tab[i] && map->tab[i][x] != '\0' && map->tab[i][x] != c)
			i++;
		while (map->tab[i] && map->tab[i][x] == c)
		{
			count++;
			i++;
		}
		if ((ret = ft_check_count_win(count, c)) != 0)
			return (ret);
		if (map->tab[i])
			i++;
	}
	return (0);
}

static int		st_check_horizontal(t_map *map, int y, char c)
{
	int			i;
	int			count;
	int			ret;

	i = 0;
	ret = 0;
	while (map->tab[y][i] != '\0')
	{
		count = 0;
		while (map->tab[y][i] != '\0' && map->tab[y][i] != c)
			i++;
		while (map->tab[y][i] == c)
		{
			count++;
			i++;
		}
		if ((ret = ft_check_count_win(count, c)) != 0)
			return (ret);
		if (map->tab[y][i] != '\0')
			i++;
	}
	return (0);
}

int				ft_check_token(t_map *map, int y, int x, char c)
{
	int			ret;

	if (map->count == map->max)
		return (3);
	if ((ret = st_check_vertical(map, x, c)) != 0)
		return (ret);
	if ((ret = st_check_horizontal(map, y, c)) != 0)
		return (ret);
	if ((ret = ft_check_slash(map, y, x, c)) != 0)
		return (ret);
	return (ft_check_bad_slash(map, y, x, c));
}
