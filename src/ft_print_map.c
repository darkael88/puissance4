/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 08:48:36 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 15:46:11 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

void		ft_print_turn_ai(int x)
{
	ft_putstr("\033[31mPlayer: AI[X]:\033[0m ");
	ft_putnbr(x);
	ft_putchar('\n');
}

static void	st_print_last(int last, int c)
{
	int		i;

	i = 0;
	while (i < (last * 2 + 1))
	{
		ft_putchar(' ');
		i++;
	}
	if (c == 'X')
		ft_putendl("\033[31m|\033[0m");
	else
		ft_putendl("\033[33m|\033[0m");
}

void		ft_print_map(t_map *map, int last, char c, int y)
{
	int		x;

	while (map->tab[y])
	{
		x = 0;
		ft_putchar('|');
		while(map->tab[y][x] != '\0')
		{
			if (map->tab[y][x] == ' ')
				ft_putchar(' ');
			else if (map->tab[y][x] == 'O')
				ft_putstr("\033[33mO\033[0m");
			else if (map->tab[y][x] == 'X')
				ft_putstr("\033[31mX\033[0m");
			ft_putchar('|');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putendl(map->coor);
	if (last != -1)
		st_print_last(last, c);
	ft_putchar('\n');
}
