/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdecimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:45:28 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 22:45:31 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putunsigned(va_list ap, t_flags **flags)
{
	t_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putunsignedchar(ap, 10, 0);
	else if (f->h == 1)
		f->str = putushort(ap, 10, 0);
	else if (f->l == 1)
		f->str = putulong(ap, 10, 0);
	else if (f->ll == 1)
		f->str = putulonglong(ap, 10, 0);
	else if (f->j == 1)
		f->str = putuintmax(ap, 10, 0);
	else if (f->z == 1)
		f->str = putusizet(ap, 10, 0);
	else
		f->str = putuintmax(ap, 10, 0);
	printun(&f);
	ft_putstrf(f->str);
	f->size += (int)ft_strlen(f->str);
}

void	puthex(va_list ap, t_flags **flags, int ucase)
{
	t_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putunsignedchar(ap, 16, ucase);
	else if (f->h == 1)
		f->str = putushort(ap, 16, ucase);
	else if (f->l == 1)
		f->str = putulong(ap, 16, ucase);
	else if (f->ll == 1)
		f->str = putulonglong(ap, 16, ucase);
	else if (f->j == 1)
		f->str = putuintmax(ap, 16, ucase);
	else if (f->z == 1)
		f->str = putusizet(ap, 16, ucase);
	else
		f->str = putuintmax(ap, 16, ucase);
	printhex(&f, ucase);
}

void	putoctal(va_list ap, t_flags **flags)
{
	t_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putunsignedchar(ap, 8, 0);
	else if (f->h == 1)
		f->str = putushort(ap, 8, 0);
	else if (f->l == 1)
		f->str = putulong(ap, 8, 0);
	else if (f->ll == 1)
		f->str = putulonglong(ap, 8, 0);
	else if (f->j == 1)
		f->str = putuintmax(ap, 8, 0);
	else if (f->z == 1)
		f->str = putusizet(ap, 8, 0);
	else
		f->str = putuintmax(ap, 8, 0);
	printoctal(&f);
}

void	putlint(va_list ap, t_flags **flags)
{
	t_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putsignedchar(ap, 10, 0);
	else if (f->h == 1)
		f->str = putshort(ap, 10, 0);
	else if (f->l == 1)
		f->str = putlong(ap, 10, 0);
	else if (f->ll == 1)
		f->str = putlonglong(ap, 10, 0);
	else if (f->j == 1)
		f->str = putintmax(ap, 10, 0);
	else if (f->z == 1)
		f->str = putsizet(ap, 10, 0);
	else
		f->str = putint(ap, 10, 0);
	printdecimal(&f);
}

void	putlongint(va_list ap, t_flags **flags)
{
	t_flags *f;

	f = *flags;
	f->str = putlong(ap, 10, 0);
	printdecimal(&f);
}
