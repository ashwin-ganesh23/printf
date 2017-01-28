/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlengthmisc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:03:22 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:03:23 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

char	*putsizet(va_list ap, int base, int ucase)
{
	void	*s;

	s = va_arg(ap, void *);
	return (itoa_base((size_t)s, base, ucase));
}

char 	*putusizet(va_list ap, int base, int ucase)
{
	void	*s;

	s = va_arg(ap, void *);
	return (utoa_base((size_t)s, base, ucase));
}

char	*putintmax(va_list ap, int base, int ucase)
{
	void	*m;

	m = va_arg(ap, void *);
	return (itoa_base_signed((intmax_t)m, base, ucase));
}
