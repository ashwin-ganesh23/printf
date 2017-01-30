/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populateflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:42:35 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 22:42:36 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	populateflags(char *str, t_flags **flags, int *index)
{
	int		i;
	t_flags *f;

	f = *flags;
	i = *index;
	while (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+'
		|| str[i] == ' ')
	{
		if (str[i] == '#')
			f->hash = 1;
		else if (str[i] == '0')
			f->zero = 1;
		else if (str[i] == '-')
			f->neg = 1;
		else if (str[i] == ' ')
			f->space = 1;
		else if (str[i] == '+')
			f->pos = 1;
		i++;
	}
	*index = i;
}

void	populatefw(char *str, t_flags **flags, int *index)
{
	int		i;
	int		v;
	t_flags	*f;

	f = *flags;
	i = *index;
	v = 0;
	if (str[i] > '0')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				v += str[i] - 48;
				v *= 10;
			}
			else
				v += str[i] - 48;
			i++;
		}
		f->fw = v;
	}
	*index = i;
}

void	populateprecision(char *str, t_flags **flags, int *index)
{
	int		i;
	int		v;
	t_flags	*f;

	f = *flags;
	i = *index;
	v = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				v += str[i] - 48;
				v *= 10;
			}
			else
				v += str[i] - 48;
			i++;
		}
	}
	f->precision = v;
	*index = i;
}

void	populatelength(char *str, t_flags **flags, int *index)
{
	int		i;
	t_flags	*f;

	f = *flags;
	i = *index;
	if ((str[i] == 'h' && str[i + 1] == 'h') || str[i] == 'h'
		|| str[i] == 'l' || (str[i] == 'l' && str[i + 1] == 'l')
		|| str[i] == 'j' || str[i] == 'z')
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			f->hh = 1;
		else if (str[i] == 'h')
			f->h = 1;
		else if (str[i] == 'l')
			f->l = 1;
		else if (str[i] == 'l' && str[i + 1] == 'l')
			f->ll = 1;
		else if (str[i] == 'j')
			f->j = 1;
		else if (str[i] == 'z')
			f->z = 1;
		i++;
	}
	*index = i;
}

int		issymbol(char *s, int *index)
{
	int		t;

	t = *index;
	if (s[t] == '#' || s[t] == '0' || s[t] == '-' || s[t] == ' '
		|| s[t] == '+' || (s[t] == 'h' && s[t + 1] == 'h')
		|| s[t] == 'h' || (s[t] == 'l' && s[t + 1] == 'l')
		|| s[t] == 'l' || s[t] == 'j' || s[t] == 'z'
		|| s[t] == ' ' || (s[t] >= '0' && s[t] <= '9')
		|| s[t] == '.')
		return (1);
	else
		return (0);
	*index = t;
}
