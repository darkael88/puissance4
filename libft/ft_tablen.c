/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 07:00:41 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/04 07:15:40 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_tablen(void **tab)
{
	size_t		i;

	if (tab)
	{
		i = 0;
		while (tab[i])
			i++;
		return (i);
	}
	return (0);
}