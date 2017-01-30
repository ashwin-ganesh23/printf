/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:29:38 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 22:29:40 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	find_digits(intmax_t value, intmax_t base)
{
	intmax_t digits;

	digits = 0;
	while (value)
	{
		value /= base;
		digits++;
	}
	return (digits);
}

uintmax_t	ufind_digits(uintmax_t value, uintmax_t base)
{
	uintmax_t digits;

	digits = 0;
	while (value)
	{
		value /= base;
		digits++;
	}
	return (digits);
}

char		*itoa_base(intmax_t value, intmax_t base, int ucase)
{
	uintmax_t	max;
	uintmax_t	size;
	char		*bases;
	char		*str;

	bases = (ucase == 1) ? "0123456789ABCDEF" : "0123456789abcdef";
	max = (intmax_t)value;
	if (value == 0)
		return ("0");
	if (value < 0)
		max *= -1;
	size = find_digits(value, base);
	str = (char *)malloc(size + 1);
	str[size] = '\0';
	while (max)
	{
		str[--size] = bases[max % base];
		max /= base;
	}
	if (value < 0)
		str[0] = '-';
	return (str);
}

char		*utoa_base(uintmax_t value, uintmax_t base, int ucase)
{
	uintmax_t	max;
	uintmax_t	size;
	char		*bases;
	char		*str;

	bases = (ucase == 1) ? "0123456789ABCDEF" : "0123456789abcdef";
	max = value;
	if (value == 0)
		return ("0");
	size = ufind_digits(value, base);
	str = (char *)malloc(size + 1);
	str[size] = '\0';
	while (max)
	{
		str[--size] = bases[max % base];
		max /= base;
	}
	return (str);
}

char		*itoa_base_signed(ssize_t value, int base, int ucase)
{
	intmax_t	max;
	int			size;
	char		*bases;
	char		*str;

	bases = (ucase == 1) ? "0123456789ABCDEF" : "0123456789abcdef";
	max = (intmax_t)value;
	if (value == 0)
		return ("0");
	if (value < 0)
		max *= -1;
	size = find_digits(value, base);
	if (value < 0 && base == 10)
		size++;
	str = (char *)malloc(size + 1);
	str[size] = '\0';
	while (max)
	{
		str[--size] = bases[max % base];
		max /= base;
	}
	if (value < 0)
		str[0] = '-';
	return (str);
}
