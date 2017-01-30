/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:04:16 by aganesh           #+#    #+#             */
/*   Updated: 2016/12/15 15:04:17 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checksymbols(char *s, t_flags **flags, int *index)
{
	int		t;
	t_flags *f;

	f = *flags;
	t = *index;
	while (issymbol(s, &t))
	{
		populateflags(s, &f, &t);
		populatefw(s, &f, &t);
		populateprecision(s, &f, &t);
		populatelength(s, &f, &t);
	}
	*index = t;
}

int		isconv(char *str, int *index)
{
	int		i;

	i = *index;
	if (str[i] == 's' || str[i] == 'S' || str[i] == 'p' || str[i] == 'd'
	|| str[i] == 'D' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O'
	|| str[i] == 'u' || str[i] == 'U' || str[i] == 'x' || str[i] == 'X'
	|| str[i] == 'c' || str[i] == 'C')
	{
		return (1);
	}
	return (0);
}

void	setflags(t_flags **flags)
{
	t_flags *f;

	f = *flags;
	f->hash = 0;
	f->zero = 0;
	f->neg = 0;
	f->pos = 0;
	f->space = 0;
	f->fw = 0;
	f->precision = 0;
	f->hh = 0;
	f->h = 0;
	f->l = 0;
	f->ll = 0;
	f->j = 0;
	f->z = 0;
	f->length = 0;
	f->str = "";
}

void	convspecifier(t_flags **flags, va_list ap, int *i, char *s)
{
	t_flags *f;
	int		index;

	f = *flags;
	index = *i;
	index++;
	if (issymbol(s, &index))
		checksymbols(s, &f, &index);
	if (isconv(s, &index))
		putform(s, ap, &f, &index);
	else
		putrandchar(s, &f, &index);
	setflags(&f);
	*i = index;
}

int		ft_printf(const char *format, ...)
{
	char	*s;
	int		index;
	va_list	ap;
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	s = (char *)format;
	va_start(ap, format);
	setflags(&flags);
	flags->size = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == '%')
			convspecifier(&flags, ap, &index, s);
		else
		{
			flags->size += 1;
			ft_putcharf(s[index++]);
		}
	}
	va_end(ap);
	index = flags->size;
	free(flags);
	return (index);
}
