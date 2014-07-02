/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:42:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/08 07:58:59 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

static int	ft_check_overflow(char *av)
{
	int		i;

	i = ft_strlen(av);
	if (i > 10)
		return (-2);
	else if (i == 10)
	{
		if (ft_strcmp(av, "2147483647") > 0)
			return (-2);
	}
	return (ft_atoi(av));
}

int			ft_check_number(char *av)
{
	int		i;

	i = 0;
	if (av[0] == '-')
		return (-1);
	while (av[i] != '\0')
	{
		if (av[i] < '0' || av[i] > '9')
			return (-3);
		i++;
	}
	return (ft_check_overflow(av));
}
