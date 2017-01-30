/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:18:15 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/27 23:18:16 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void	printun(f_flags **flags)
{
	f_flags *f;
	char	*tmp;
	int		length;
	int		strlen;

	f = *flags;
	strlen = ft_strlen(f->str);
	length = strlen;
	if (f->precision > length)
		length = f->precision;
	if (f->fw > length)
		tmp = unhelper(&f, length, strlen);
	else
	{
		tmp = ft_strnew(length);
		if (length > strlen)
		{
			ft_strfill(tmp, '0', 0, length - strlen);
			ft_strlcat(tmp + length - strlen, f->str, strlen + 1);
		}
		else
			tmp = f->str;
	}
	f->str = tmp;
}

char	*unhelper(f_flags **flags, int length, int strlen)
{
	f_flags	*f;
	char	*tmp;

	f = *flags;
	tmp = ft_strnew(f->fw);
	if (f->neg == 1)
	{
		if (strlen < length)
		{
			ft_strfill(tmp, '0', 0, length - strlen);
			ft_strlcat(tmp + length - strlen, f->str, strlen + 1);
		}
		else
			ft_strlcat(tmp, f->str, length + 1);
		ft_strfill(tmp, ' ', length, f->fw);
		tmp[f->fw] = '\0';
	}
	else
		miniunhelper(&f, &tmp, length);
	return (tmp);
}

void	miniunhelper(f_flags **flags, char **tp, int length)
{
	f_flags *f;
	char	*tmp;

	f = *flags;
	tmp = *tp;
	ft_strfill(tmp, ' ', 0, f->fw - length);
	if ((int)ft_strlen(f->str) < length)
	{
		ft_strfill(tmp, '0', f->fw - length, f->fw - ft_strlen(f->str));
		ft_strlcat(tmp + length, f->str, ft_strlen(f->str) + 1);
	}
	else
		ft_strlcat(tmp + f->fw - length, f->str, length + 1);
	tmp[f->fw] = '\0';
	*tp = tmp;
}
