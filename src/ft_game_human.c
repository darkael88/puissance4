/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_human.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:23:22 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 20:40:42 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static void	st_check_end(int ret)
{
	if (ret == 1)
	{
		ft_putendl("\033[033mHuman1[O]: WIN !!!!!!!!!!\033[0m");
		ft_putendl("You are the champion ;)");
	}
	else if (ret == 2)
	{
		ft_putendl("\033[031mHuman2[X]: WIN !!!!!!!!!!\033[0m");
		ft_putendl("You are a bad gamer, try again");
	}
	else if (ret == 3)
		ft_putendl("No player wins, try again");
}

static int	st_player_1(t_map *map, int y, int x, char **line)
{
	int		ret;

	ret = 1;
	ft_putstr("\033[33mHuman1[O]:\033[0m ");
	while (1)
	{
		ft_memdel((void **)line);
		if ((get_next_line(0, line)))
		{
			if ((ret = ft_player_line_1(map, line, x, y)) >= 0)
				return (ret);
		}
	}
	return (0);
}

static int	st_player_line_2(t_map *map, char **line, int x, int y)
{
	int		i;

	i = -1;
	if (*line[0] != '\0')
		i = ft_check_number(*line);
	if (i < 0 || i >= x || (*line)[0] == '\0')
	{
		ft_putstr(*line);
		ft_putendl(": \033[031mInvalid command, try again\033[0m");
		ft_putstr("\033[31mHuman2[X]:\033[0m ");
		return (-1);
	}
	else
	{
		if (ft_place_piece(map, i, y - 1, 'X') == -1)
		{
			ft_putstr(*line);
			ft_putendl(": \033[031mColumn full, try again\033[0m");
			ft_putstr("\033[31mHuman2[X]:\033[0m ");
			return (-1);
		}
		map->count = map->count + 1;
	}
	return (ft_check_win(map, i, 'X'));
}

static int	st_player_2(t_map *map, int y, int x, char **line)
{
	int		ret;

	ret = -1;
	ft_putstr("\033[31mHuman2[X]:\033[0m ");
	while (1)
	{
		ft_memdel((void **)line);
		if ((get_next_line(0, line)))
		{
			if ((ret = st_player_line_2(map, line, x, y)) >= 0)
				return (ret);
		}
	}
	return (0);
}

void		ft_game_human(t_map *map, int y, int x)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = 1;
	ft_putendl("\033[33mHuman1[O]\033[0m");
	ft_putendl("\033[31mHuman2[X]\033[0m");
	ft_print_map(map, -1, 0, 0);
	while (ret)
	{
		ret = st_player_1(map, y, x, &line);
		if (ret >= 1)
			break ;
		ret = st_player_2(map, y, x, &line);
		if (ret >= 1)
			break ;
		ret = 1;
	}
	st_check_end(ret);
}
