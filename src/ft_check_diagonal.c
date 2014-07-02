/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_diagonal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:56:39 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 20:25:17 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

int				ft_check_slash(t_map *map, int y, int x, char c)
{
	int			i;
	int			j;
	int			count;

	count = 1;
	i = x + 1;
	j = y - 1;
	while (j >= 0 && map->tab[j][i] == c)
	{
		i++;
		j--;
		count++;
	}
	i = x - 1;
	j = y + 1;
	while (i >= 0 && map->tab[j] && map->tab[j][i] == c)
	{
		i--;
		j++;
		count++;
	}
	return (ft_check_count_win(count, c));
}

int				ft_check_bad_slash(t_map *map, int y, int x, char c)
{
	int			i;
	int			j;
	int			count;

	count = 1;
	i = x + 1;
	j = y + 1;
	while (map->tab[j] && map->tab[j][i] == c)
	{
		i++;
		j++;
		count++;
	}
	i = x - 1;
	j = y - 1;
	while (i >= 0 && j >= 0 && map->tab[j][i] == c)
	{
		i--;
		j--;
		count++;
	}
	return (ft_check_count_win(count, c));
}
