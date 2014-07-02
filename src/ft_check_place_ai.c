/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place_ai.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:59:03 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 22:47:53 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static void	st_first_tab(char c, t_place *check)
{
	if (c == 'X')
		check->ai[0][0] = 1;
	else
		check->human[0][0] = 1;
}

void		ft_check_place_ai_up(t_map *map, int y, t_place *check, char c)
{
	int		i;
	int		x;

	if (c == 'X')
		x = map->last_x;
	else
		x = map->last_human_x;
	if (y < 1)
		return ;
	i = 0;
	st_first_tab(c, check);
	while (map->tab[y] && map->tab[y][x] == c)
	{
		if (c == 'X')
			check->ai[0][1] = check->ai[0][1] + 3;
		else
			check->human[0][1] = check->human[0][1] + 3;
		y++;
	}
	if (c == 'X')
		check->ai[0][1] = check->ai[0][1] + 2;
	else
		check->human[0][1] = check->human[0][1] + 2;
}
