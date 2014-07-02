/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:31:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 15:43:56 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <power4.h>

int			ft_error_argv(int ac)
{
	if (ac < 3)
		ft_putendl_fd("Error: Too few arguments.", 2);
	else
		ft_putendl_fd("Error: Too much arguments.", 2);
	ft_putendl_fd("Usage : ./puissance4 [int y] [int x] -p2 1GB max", 2);
	return (0);
}

int			ft_error_number(int nb, char c)
{
	ft_putstr_fd("Error: Invalide argument for ", 2);
	ft_putchar(c);
	if (nb >= 0)
		ft_putendl_fd(": Too small number", 2);
	else if (nb == -1)
		ft_putendl_fd(": Negative number", 2);
	else if (nb == -2)
		ft_putendl_fd(": Number superior to integer", 2);
	else if (nb == -3)
		ft_putendl_fd(": Invalide format", 2);
	ft_putendl_fd("Usage : ./puissance4 [int y] [int x] 1Gb max", 2);
	return (0);
}

int			ft_error_too_memory(void)
{
	ft_putendl_fd("Error: Use memory > 1Gb ", 2);
	ft_putendl_fd("Usage : ./puissance4 [int y] [int x] 1Gb max", 2);
	return (0);
}

int			ft_error_malloc(void)
{
	ft_putendl_fd("Error: problem with malloc", 2);
	return (-1);
}
