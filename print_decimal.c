/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:18:00 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:18:01 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void	printdecimal(f_flags **flags)
{
	f_flags *f;
	int 	length;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	decposspace(&f, &length);
	if (f->fw > length)
		dechelp(&f);
	else
	{
		if (length > (int)ft_strlen(f->str))
		{
			putzeros(length - ft_strlen(f->str));
			(f->str[0] == '-' && f->pos == 1 ? ft_putstrf(f->str + 1) : ft_putstrf(f->str));
		}
		else
			((f->str[0] == '-' && f->pos == 1) ? ft_putstrf(f->str + 1) : ft_putstrf(f->str));
		f->size += length;
	}
	f->str = "";
}

void	decposspace(f_flags **flags, int *length)
{
	f_flags *f;
	int		*l;

	f = *flags;
	l = *length;
	if (f->pos == 1)
	{
		if (f->str[0] != '-')
			if (!(f->zero != 1 && f->fw > length && f->neg != 1))
				ft_putcharf('+');
		else if (f->str[0] == '-')
		{
			ft_putcharf('-');
			length--;
		}
		f->size += 1;
		f->fw--;
	}
	else if (f->space == 1 && f->str[0] != '-')
	{
		ft_putcharf(' ');
		f->size += 1;
		f->fw--;
	}
	*length = l;
}

void	decneghelper(f_flags **flags, int length)
{
	f_flags *f;

	f = *flags;
	if (f->zero == 1 && f->str[0] == '-' && f->pos != 1)
		ft_putcharf('-');
	if (f->precision >= ft_strlen(f->str))
		putspaces(f->fw - length);
	else
		(f->zero == 1 ? putzeros(f->fw - length) : putspaces(f->fw - length));
	if ((int)ft_strlen(f->str) < length)
	{
		if (f->zero != 1 && f->str[0] != '-' && f->pos == 1)
			ft_putcharf('+');
		putzeros(length - ft_strlen(f->str));
		(f->str[0] == '-' && (f->pos == 1 || f->zero == 1) ? ft_putstrf(f->str + 1) : ft_putstrf(f->str));
	}
	else
		(f->str[0] == '-' && (f->pos == 1 || f->zero == 1) ? ft_putstrf(f->str + 1) : ft_putstrf(f->str));
}

void	dechelp(f_flags **flags)
{
	f_flags *f;

	f = *flags;
	if (f->neg == 1)
	{
		if ((int)ft_strlen(f->str) < length)
		{
			putzeros(length - ft_strlen(f->str));
			(f->str[0] == '-' && f->pos == 1 ? ft_putstrf(f->str + 1) : ft_putstrf(f->str));
		}
		else 
			(f->str[0] == '-' && f->pos == 1 ? ft_putstrf(f->str + 1) : ft_putstrf(f->str));
		putspaces(f->fw - length);
	}
	else
		decneghelper(&f, length);
	f->size += f->fw;
}
