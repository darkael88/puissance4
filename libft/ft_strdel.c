/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:22:47 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 09:04:22 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}
