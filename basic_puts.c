/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:28:16 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 22:28:26 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void	putspaces(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putcharf(' ');
		i++;
	}
}

void	putzeros(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putcharf('0');
		i++;
	}
}

void	ft_putcharf(char c)
{
	write(1, &c, 1);
}

void	ft_putstrf(char *str)
{
	while (*str)
		ft_putcharf(*str++);
}

void	ft_putstrl(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putcharf(str[i++]);
}
