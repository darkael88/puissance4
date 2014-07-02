/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 08:09:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/08 15:00:46 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

int			ft_first_player(void)
{
	int		i;

	srand(time(NULL));
	i = rand();
	if (i % 2 != 0)
	{
		ft_putendl("\033[33mPlayer1: Human[O]\033[0m");
		ft_putendl("\033[31mPlayer2: AI[X]\033[0m");
		return (1);
	}
	else
	{
		ft_putendl("\033[31mPlayer1: AI[X]\033[0m");
		ft_putendl("\033[33mPlayer2: Human[O]\033[0m");
		return (2);
	}
}
