/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:46:29 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 22:46:32 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void	putuchar(va_list ap, f_flags **flags)
{
	f_flags		*f;
	int			c;

	f = *flags;
	c = (unsigned char)va_arg(ap, int);
	f->size += 1;
	if (f->fw > 1)
	{
		f->size += f->fw - 1;
		if (f->neg == 1)
		{
			ft_putcharf(c);
			putspaces(f->fw - 1);
		}
		else
		{
			putspaces(f->fw - 1);
			ft_putcharf(c);
		}
	}
	else
		ft_putcharf(c);
}

void	putptr(va_list ap, f_flags **flags)
{
	f_flags		*f;
	void		*ptr;

	f = *flags;
	ptr = va_arg(ap, void*);
	f->str = ft_strjoin("0x", itoa_base((uintmax_t)ptr, 16, 0));
	ft_putstrf(f->str);
	f->size += (int)ft_strlen(f->str);
}

void	putform(char *s, va_list ap, f_flags **flags, int *index)
{
	int		t;
	f_flags *f;

	t = *index;
	f = *flags;
	if (s[t] == 's' || s[t] == 'S')
		putstrf(ap, &f);
	else if (s[t] == 'p')
		putptr(ap, &f);
	else if (s[t] == 'd' || s[t] == 'i')
		putlint(ap, &f);
	else if (s[t] == 'D')
		putlongint(ap, &f);
	else if (s[t] == 'o' || s[t] == 'O')
		putoctal(ap, &f);
	else if (s[t] == 'u' || s[t] == 'U')
		putunsigned(ap, &f);
	else if (s[t] == 'x')
		puthex(ap, &f, 0);
	else if (s[t] == 'X')
		puthex(ap, &f, 1);
	else if (s[t] == 'c' || s[t] == 'C')
		putuchar(ap, &f);
	*index = ++t;
}

void	putrandchar(char *s, f_flags **flags, int *index)
{
	f_flags *f;
	int		i;

	i = *index;
	f = *flags;
	if (f->fw > 1)
	{
		f->size += f->fw;
		if (f->neg == 0)
		{
			putspaces(f->fw - 1);
			ft_putcharf(s[i++]);
		}
		else if (f->neg == 1)
		{
			ft_putcharf(s[i++]);
			putspaces(f->fw - 1);
		}
	}
	else
	{
		ft_putcharf(s[i++]);
		f->size += 1;
	}
	*index = i;
}

void	putstrf(va_list ap, f_flags **flags)
{
	f_flags *f;
	void	*data;

	f = *flags;
	data = va_arg(ap, void *);
	if (data == NULL)
	{
		f->size += 6;
		ft_putstrf("(null)");
		return ;
	}
	f->str = (char *)data;
	printstr(&f);
}
