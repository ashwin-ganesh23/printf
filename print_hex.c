/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:43:06 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:43:07 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printhex(t_flags **flags, int ucase)
{
	t_flags *f;
	int		length;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	if (f->hash == 1)
		length += 2;
	if (ft_strncmp(f->str, "0", 1) == 0)
	{
		ft_putcharf('0');
		f->size += 1;
	}
	else if (f->fw > length)
		realhexhelper(&f, length, ucase);
	else
		realdealhex(&f, length, ucase);
	f->str = "";
}

void	hexhelper(t_flags **flags, int length, int ucase)
{
	t_flags *f;

	f = *flags;
	if (f->zero == 0)
		putspaces(f->fw - length);
	if (f->hash == 1)
		(ucase == 1 ? ft_putstrf("0X") : ft_putstrf("0x"));
	if (f->zero == 1)
		putzeros(f->fw - length);
	if ((int)ft_strlen(f->str) < length)
	{
		putzeros(f->precision - ft_strlen(f->str));
		ft_putstrf(f->str);
	}
	else
		ft_putstrf(f->str);
}

void	realhexhelper(t_flags **flags, int length, int ucase)
{
	t_flags *f;

	f = *flags;
	if (f->neg == 1)
	{
		if (f->hash == 1)
			(ucase == 1 ? ft_putstrf("0X") : ft_putstrf("0x"));
		if ((int)ft_strlen(f->str) < length)
		{
			putzeros(f->precision - ft_strlen(f->str));
			ft_putstrf(f->str);
		}
		else
			ft_putstrf(f->str);
		putspaces(f->fw - length);
	}
	else
		hexhelper(&f, length, ucase);
	f->size += f->fw;
}

void	realdealhex(t_flags **flags, int length, int ucase)
{
	t_flags *f;

	f = *flags;
	if (f->hash == 1)
		(ucase == 1 ? ft_putstrf("0X") : ft_putstrf("0x"));
	if (length > (int)ft_strlen(f->str))
	{
		putzeros(length - ft_strlen(f->str) - (f->hash * 2));
		ft_putstrf(f->str);
	}
	else
		ft_putstrf(f->str);
	f->size += length;
}
