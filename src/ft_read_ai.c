/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_ai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:44:29 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 20:39:47 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static void	st_check_end(int ret)
{
	if (ret == 1)
	{
		ft_putendl("\033[033mHuman[O]: WIN !!!!!!!!!!\033[0m");
		ft_putendl("You are the champion ;)");
	}
	else if (ret == 2)
	{
		ft_putendl("\033[031mAI[X]: WIN !!!!!!!!!!\033[0m");
		ft_putendl("You are a bad gamer, try again");
	}
	else if (ret == 3)
		ft_putendl("No player wins, try again");
}

int			ft_check_win(t_map *map, int i, char c)
{
	int		y;

	y = 0;
	while (map->tab[y][i] != c)
		y++;
	return (ft_check_token(map, y, i, c));
}

int			ft_player_line_1(t_map *map, char **line, int x, int y)
{
	int		i;

	i = -1;
	if (*line[0] != '\0')
		i = ft_check_number(*line);
	if (i < 0 || i >= x || (*line)[0] == '\0')
	{
		ft_putstr(*line);
		ft_putendl(": \033[033mInvalid command, try again\033[0m");
		ft_putstr("\033[33mHuman[O]:\033[0m ");
		return (-1);
	}
	else
	{
		if (ft_place_piece(map, i, y - 1, 'O') == -1)
		{
			ft_putstr(*line);
			ft_putendl(": \033[033mColumn full, try again\033[0m");
			ft_putstr("\033[33mHuman[O]:\033[0m ");
			return (-1);
		}
		map->count = map->count + 1;
	}
	return (ft_check_win(map, i, 'O'));
}

void		ft_read_ai(t_map *map, int x, int y)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = 1;
	while (ret)
	{
		ft_putstr("\033[33mHuman[O]:\033[0m ");
		while (1)
		{
			ft_memdel((void **)&line);
			if ((get_next_line(0, &line)))
			{
				if ((ret = ft_player_line_1(map, &line, x, y)) >= 0)
					break ;
			}
		}
		if (ret >= 1)
			break ;
		if ((ret = ft_ai(map)) >= 1)
			break ;
		ret = 1;
	}
	st_check_end(ret);
}
