/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:01:44 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:01:45 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*putsignedchar(va_list ap, int base, int ucase)
{
	void	*c;

	c = va_arg(ap, void *);
	return (itoa_base_signed((signed char)c, base, ucase));
}

char	*putshort(va_list ap, int base, int ucase)
{
	void	*c;

	c = va_arg(ap, void *);
	return (itoa_base_signed((short)c, base, ucase));
}

char	*putint(va_list ap, int base, int ucase)
{
	void	*i;

	i = va_arg(ap, void *);
	return (itoa_base_signed((int)i, base, ucase));
}

char	*putlong(va_list ap, int base, int ucase)
{
	void	*l;

	l = va_arg(ap, void *);
	return (itoa_base_signed((long)l, base, ucase));
}

char	*putlonglong(va_list ap, int base, int ucase)
{
	void	*ll;

	ll = va_arg(ap, void *);
	return (itoa_base_signed((long long)ll, base, ucase));
}
