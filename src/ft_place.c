/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:07:04 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 18:19:02 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

int			ft_place_piece(t_map *map, int x, int y, char c)
{
	int		j;

	j = y;
	while (j >= 0)
	{
		if (map->tab[j][x] == ' ')
		{
			map->tab[j][x] = c;
			ft_print_map(map, x, c, 0);
			map->last_human_x = x;
			return (0);
		}
		j--;
	}
	return (-1);
}
