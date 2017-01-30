/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:18:00 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:18:01 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printdecimal(t_flags **flags)
{
	t_flags *f;
	int		length;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	decposspace(&f, &length);
	if (f->fw > length)
		dechelp(&f, length);
	else
	{
		if (length > (int)ft_strlen(f->str))
		{
			putzeros(length - ft_strlen(f->str));
			ft_putstrf(f->str[0] == '-' && f->pos == 1 ? f->str + 1 : f->str);
		}
		else
			ft_putstrf(f->str[0] == '-' && f->pos == 1 ? f->str + 1 : f->str);
		f->size += length;
	}
	f->str = "";
}

void	decposspace(t_flags **flags, int *length)
{
	t_flags *f;
	int		l;

	f = *flags;
	l = *length;
	if (f->pos == 1)
	{
		if (f->str[0] != '-')
		{
			if (!(f->zero != 1 && f->fw > l && f->neg != 1))
				ft_putcharf('+');
		}
		else if (f->str[0] == '-' && l--)
			ft_putcharf('-');
	}
	else if (f->space == 1 && f->str[0] != '-')
		ft_putcharf(' ');
	if (f->pos == 1 || (f->space == 1 && f->str[0] != '-'))
	{
		f->size += 1;
		f->fw--;
	}
	*length = l;
}

void	decneghelper(t_flags **flags, int length)
{
	t_flags *f;
	int		bol;

	f = *flags;
	bol = (f->str[0] == '-' && (f->pos == 1 || f->zero == 1)) ? 1 : 0;
	if (f->zero == 1 && f->str[0] == '-' && f->pos != 1)
		ft_putcharf('-');
	if (f->precision >= (int)ft_strlen(f->str))
		putspaces(f->fw - length);
	else
		(f->zero == 1 ? putzeros(f->fw - length) : putspaces(f->fw - length));
	if ((int)ft_strlen(f->str) < length)
	{
		if (f->zero != 1 && f->str[0] != '-' && f->pos == 1)
			ft_putcharf('+');
		putzeros(length - ft_strlen(f->str));
		ft_putstrf(f->str + bol);
	}
	else
		ft_putstrf(f->str + bol);
}

void	dechelp(t_flags **flags, int length)
{
	t_flags *f;

	f = *flags;
	if (f->neg == 1)
	{
		if ((int)ft_strlen(f->str) < length)
		{
			putzeros(length - ft_strlen(f->str));
			ft_putstrf(f->str[0] == '-' && f->pos == 1 ? f->str + 1 : f->str);
		}
		else
			ft_putstrf(f->str[0] == '-' && f->pos == 1 ? f->str + 1 : f->str);
		putspaces(f->fw - length);
	}
	else
		decneghelper(&f, length);
	f->size += f->fw;
}
