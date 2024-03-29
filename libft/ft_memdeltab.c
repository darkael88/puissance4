/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdeltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 14:04:55 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 15:30:27 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memdeltab(void ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		ft_memdel(&((*tab)[i]));
		i++;
	}
}
