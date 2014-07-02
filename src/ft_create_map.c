/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:52:49 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/08 14:27:31 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

char		**ft_create_map(int y, int x)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char **)malloc(sizeof(char *) * (y + 1))))
		return (NULL);
	j = 0;
	while (j < y)
	{
		if (!(tab[j] = (char *)malloc(sizeof(char) * (x + 1))))
			return (NULL);
		i = 0;
		while (i < x)
		{
			tab[j][i] = ' ';
			i++;
		}
		tab[j][i] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
