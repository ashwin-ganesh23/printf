/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:10:53 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:10:54 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void	printstr(f_flags **flags)
{
	f_flags *f;
	int length;

	f = *flags;
	length = (int)ft_strlen(f->str);
	if (f->precision > 0 && f->precision < length)
		length = f->precision;
	if (f->fw > length)
		strfwlhelp(&f, length);
	else
		otherstrhelp(&f, length);
	f->str = "";
}

void	strfwlhelp(f_flags **flags, int length)
{
	f_flags *f;

	f = *flags;
	if (f->neg == 1)
	{
		ft_putstrl(f->str, length);
		if (ft_strncmp(f->str, "", 1) == 0)
			putspaces(f->fw);
		else
			putspaces(f->fw - (f->precision > length ? f->precision : length));
	}
	else if (f->zero == 1)
	{
		putzeros(f->fw - (f->precision > length ? f->precision : length));
		ft_putstrl(f->str, length);
	}
	else
	{
		if (ft_strncmp(f->str, "", 1) == 0)
			putspaces(f->fw);
		else
			putspaces(f->fw - (f->precision > length ? f->precision : length));
		ft_putstrl(f->str, length);
	}
	f->size += f->fw;
}

void	otherstrhelp(f_flags **flags, int length)
{
	f_flags *f;

	f = *flags;
	if (f->neg == 1)
	{
		ft_putstrl(f->str, length);
		putspaces(f->fw - (f->precision > length ? f->precision : length));
	}
	else if (f->zero == 1)
	{
		putzeros(f->fw - (f->precision > length ? f->precision : length));
		ft_putstrl(f->str, length);
	}
	else
	{
		putspaces(f->fw - (f->precision > length ? f->precision : length));
		ft_putstrl(f->str, length);
	}
	f->size += length;
}