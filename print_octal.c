/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoctal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:18:24 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:18:25 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void	printoctal(f_flags **flags)
{
	f_flags *f;
	int 	length;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	else if (f->hash == 1)
		length += 1;
	if (f->fw > length)
		realoctalhelp(&f, length);
	else
	{
		if (length > (int)ft_strlen(f->str))
		{
			if (!(f->str[0] == '0' && f->hash == 1))
				putzeros(length - ft_strlen(f->str));
			ft_putstrf(f->str);
		}
		else
			ft_putstrf(f->str);
		f->size += length;
	}
	f->str = "";
}

void	octalhelp(f_flags **flags, int length)
{
	f_flags		*f;

	f = *flags;
	if (f->zero == 1)
		putzeros(f->fw - length);
	else
		putspaces(f->fw - length);
	if ((int)ft_strlen(f->str) < length)
	{
		putzeros(length - ft_strlen(f->str));
		ft_putstrf(f->str);
	}
	else
		ft_putstrf(f->str);
}

void	realoctalhelp(f_flags **flags, int length)
{
	f_flags		*f;

	f = *flags;
	if (f->neg == 1)
	{
		if ((int)ft_strlen(f->str) < length)
		{
			putzeros(length - ft_strlen(f->str));
			ft_putstrf(f->str);
		}
		else
			ft_putstrf(f->str);
		putspaces(f->fw - length);
	}
	else
		octalhelp(&f, length);
	f->size += f->fw;
}
