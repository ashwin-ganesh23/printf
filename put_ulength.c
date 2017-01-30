/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putulength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:03:03 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:03:04 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*putunsignedchar(va_list ap, int base, int ucase)
{
	void	*c;

	c = va_arg(ap, void *);
	return (itoa_base((unsigned char)c, base, ucase));
}

char	*putushort(va_list ap, int base, int ucase)
{
	void	*sh;

	sh = va_arg(ap, void *);
	return (itoa_base((unsigned short)sh, base, ucase));
}

char	*putulong(va_list ap, int base, int ucase)
{
	void	*l;

	l = va_arg(ap, void *);
	return (utoa_base((unsigned long)l, base, ucase));
}

char	*putulonglong(va_list ap, int base, int ucase)
{
	void	*ll;

	ll = va_arg(ap, void *);
	return (utoa_base((unsigned long long)ll, base, ucase));
}

char	*putuintmax(va_list ap, int base, int ucase)
{
	void	*m;

	m = va_arg(ap, void *);
	return (utoa_base((uintmax_t)m, base, ucase));
}
