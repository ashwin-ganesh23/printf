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

#include "fprintf.h"

// void (*conv_id[14])(va_list ap, f_flags ff) =
// {
// 	&convstr, 	//0
// 	&convstrf, 	//1
// 	&putptr, 	//2
// 	&putlint,	//3
// 	&putlint,	//4
// 	&putlint,	//5
// 	&putloct,	//6
// 	&putloct,	//7
// 	&putlint,	//8
// 	&putlint,	//9
// 	&putlhex,	//10
// 	&putlhex,	//11
// 	&putcharf,	//12
// 	&putcharf,	//13
// };

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if ((s3 = ft_strnew(size)) == NULL)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcpy(s3 + ft_strlen(s1), s2);
	return (s3);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		x;
	size_t		destsize;
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	x = size;
	while (x-- != 0 && *d != '\0')
		d++;
	destsize = d - dst;
	x = size - destsize;
	if (x == 0)
		return (destsize + ft_strlen(src));
	while (*s != '\0')
	{
		if (x != 1)
		{
			*d++ = *s;
			x--;
		}
		s++;
	}
	*d = '\0';
	return (destsize + (s - src));
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strnew(size_t size)
{
	char *a;

	if ((a = malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	ft_memset(a, '\0', size + 1);
	return (a);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	size_t			l;

	l = len;
	a = b;
	while (l > 0)
	{
		*a = (unsigned char)c;
		a++;
		l--;
	}
	return (b);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int x;

	x = 0;
	while (src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		strsize;
	int		a;
	char	*final;

	a = 0;
	strsize = ft_strlen(s1) + 1;
	if (!(final = (char*)malloc(sizeof(char) * strsize)))
		return (NULL);
	while (a < strsize)
	{
		final[a] = s1[a];
		a++;
	}
	final[a] = '\0';
	return (final);
}

char	*ft_strfill(char *str, char c, int start, int end)
{
	char 	*tmp;

	tmp = str;
	while (start < end)
	{
		tmp[start++] = (unsigned char)c;
	}
	str = tmp;
	return (str);
}

void	ft_putcharf(char c)
{
	write(1, &c, 1);
	// char_count++;
}

void	ft_putstrf(char *str)
{
	while (*str)
		ft_putcharf(*str++);
}

int		find_digits(ssize_t value, int base)
{
	int digits;

	digits = 0;
	while (value)
	{
		value /= base;
		digits++;
	}
	return (digits);
}

char *itoa_base_upper(ssize_t value, int base)
{
	intmax_t	max;
	int			size;
	char		bases[16] = "0123456789ABCDEF";
	char		*str;

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

char *itoa_base_lower(ssize_t value, int base)
{
	intmax_t	max;
	int			size;
	char		bases[16] = "0123456789abcdef";
	char		*str;

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

char *itoa_base_unsigned(ssize_t value, int base)
{
	ssize_t		max;
	int			size;
	char		bases[16] = "0123456789abcdef";
	char		*str;

	max = value;
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

char	*putsignedchar(va_list ap, int base)
{
	signed char	c;

	c = (signed char)va_arg(ap, void *);
	return (itoa_base_upper(c, base));
}

char	*putshort(va_list ap, int base)
{
	short 		c;

	c = (short)va_arg(ap, void *);
	return (itoa_base_upper(c, base));
}

char	*putlong(va_list ap, int base)
{
	long		l;

	l = (long)va_arg(ap, void *);
	return (itoa_base_upper(l, base));
}

char	*putlonglong(va_list ap, int base)
{
	long long	ll;

	ll = va_arg(ap, long long);
	return (itoa_base_upper(ll, base));
}

char	*putintmax(va_list ap, int base)
{
	intmax_t	m;

	m = va_arg(ap, intmax_t);
	return (itoa_base_upper(m, base));
}

char	*putunsignedchar(va_list ap, int base)
{
	unsigned char c;

	c = (unsigned char)va_arg(ap, void *);
	return (itoa_base_upper(c, base));
}

char	*putushort(va_list ap, int base)
{
	unsigned short sh;

	sh = (unsigned short)va_arg(ap, void *);
	return (itoa_base_upper(sh, base));
}

char	*putulong(va_list ap, int base)
{
	unsigned long l;

	l = va_arg(ap, unsigned long);
	return (itoa_base_upper(l, base));
}

char	*putulonglong(va_list ap, int base)
{
	unsigned long long ll;
	ll = va_arg(ap, unsigned long long);
	return (itoa_base_upper(ll, base));
}

char	*putuintmax(va_list ap, int base)
{
	uintmax_t m;

	m = va_arg(ap, uintmax_t);
	return (itoa_base_upper(m, base));
}

char	*putsizet(va_list ap, int base)
{
	size_t		s;

	s = va_arg(ap, size_t);
	return (itoa_base_upper(s, base));
}

void	printstr(f_flags **flags)
{
	f_flags *f;
	int length;
	char *tmp;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	if (f->fw > length)
	{
		tmp = ft_strnew(f->fw);
		if (f->neg == 1)
		{
			ft_strlcat(tmp, f->str, length);
			ft_strfill(tmp, ' ', length-1, f->fw);
			tmp[f->fw] = '\0';
		}
		else if (f->zero == 1)
		{
			ft_strlcat(tmp + (f->fw - length), f->str, length);
			ft_strfill(tmp, '0', 0, f->fw - length);
		}
		else
		{
			ft_strlcat(tmp + (f->fw - length), f->str, length);
			ft_strfill(tmp, ' ', 0, f->fw - length);
		}
	}
	else
	{
		tmp = ft_strnew(length);
		if (f->neg == 1)
		{
			ft_strlcat(tmp, f->str, length);
			ft_strfill(tmp, ' ', length-1, f->fw);
			tmp[f->fw] = '\0';
		}
		else if (f->zero == 1)
		{
			ft_strlcat(tmp + (f->fw - length), f->str, length + 1);
			ft_strfill(tmp, '0', 0, f->fw - length);
		}
		else
		{
			ft_strlcat(tmp + (f->fw - length), f->str, length);
			ft_strfill(tmp, ' ', 0, f->fw - length);
		}
	}
	f->str = tmp;
	// ft_strdel(&tmp); 
}

void	printhex(f_flags **flags)
{
	f_flags *f;
	char *tmp;
	int length;
	int size;

	f = *flags;
	size = 0;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	if (f->hash == 1)
		size = 2;
	length += size;
	if (f->fw > length)
	{
		tmp = ft_strnew(f->fw);
		ft_strlcat(tmp, "0x", 3);
		if (f->neg == 1)
		{
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', size, length - ft_strlen(f->str));
				ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp + size, f->str, length + 1);
			ft_strfill(tmp, ' ', length, f->fw);
			tmp[f->fw] = '\0';
		}
		else
		{
			ft_strfill(tmp, ' ', size, f->fw - length);
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', f->fw - length, f->fw - ft_strlen(f->str));
				ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp + f->fw - length, f->str, length + 1);
			tmp[f->fw] = '\0';
		}
	}
	else
	{
		tmp = ft_strnew(length);
		ft_strlcat(tmp, "0x", 3);
		if (length > (int)ft_strlen(f->str))
		{
			ft_strfill(tmp, '0', size, length - ft_strlen(f->str));
			ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
		}
		else
			ft_strlcat(tmp + size, f->str, ft_strlen(f->str) + 1);
	}
	f->str = tmp;
	// ft_strdel(&tmp);
}


void	printoctal(f_flags **flags)
{
	f_flags *f;
	char 	*tmp;
	int 	length;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	else if (f->hash == 1)
		length += 1;
	if (f->fw > length)
	{
		tmp = ft_strnew(f->fw);
		if (f->neg == 1)
		{
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', 0, length - ft_strlen(f->str));
				ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp, f->str, length + 1);
			ft_strfill(tmp, ' ', length, f->fw);
			tmp[f->fw] = '\0';
		}
		else
		{
			ft_strfill(tmp, ' ', 0, f->fw - length);
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', f->fw - length, f->fw - ft_strlen(f->str));
				ft_strlcat(tmp + f->fw - (int)ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp + f->fw - length, f->str, length + 1);
			tmp[f->fw] = '\0';
		}
	}
	else
	{
		tmp = ft_strnew(length);
		if (length > (int)ft_strlen(f->str))
		{
			ft_strfill(tmp, '0', 0, length - ft_strlen(f->str));
			ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
		}
		else
			tmp = f->str;
	}
	f->str = tmp;
}

void	printun(f_flags **flags)
{
	f_flags *f;
	char 	*tmp;
	int 	length;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	if (f->fw > length)
	{
		tmp = ft_strnew(f->fw);
		if (f->neg == 1)
		{
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', 0, length - ft_strlen(f->str));
				ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp, f->str, length + 1);
			ft_strfill(tmp, ' ', length, f->fw);
			tmp[f->fw] = '\0';
		}
		else
		{
			ft_strfill(tmp, ' ', 0, f->fw - length);
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', f->fw - length, f->fw - ft_strlen(f->str));
				ft_strlcat(tmp + length, f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp + f->fw - length, f->str, length + 1);
			tmp[f->fw] = '\0';
		}
	}
	else
	{
		tmp = ft_strnew(length);
		if (length > (int)ft_strlen(f->str))
		{
			ft_strfill(tmp, '0', 0, length - ft_strlen(f->str));
			ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
		}
		else
			tmp = f->str;
	}
	f->str = tmp;
	// ft_strdel(&tmp);
}

void	printdecimal(f_flags **flags)
{
	f_flags *f;
	char 	*tmp;
	int 	length;

	f = *flags;
	length = ft_strlen(f->str);
	if (f->precision > length)
		length = f->precision;
	if (f->fw > length)
	{
		tmp = ft_strnew(f->fw);
		if (f->neg == 1)
		{
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', 0, length - ft_strlen(f->str));
				ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp, f->str, length + 1);
			ft_strfill(tmp, ' ', length, f->fw);
			tmp[f->fw] = '\0';
		}
		else
		{
			ft_strfill(tmp, ' ', 0, f->fw - length);
			if ((int)ft_strlen(f->str) < length)
			{
				ft_strfill(tmp, '0', f->fw - length, f->fw - ft_strlen(f->str));
				ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
			}
			else 
				ft_strlcat(tmp + f->fw - length, f->str, length + 1);
			tmp[f->fw] = '\0';
		}
	}
	else
	{
		tmp = ft_strnew(length);
		if (length > (int)ft_strlen(f->str))
		{
			ft_strfill(tmp, '0', 0, length - ft_strlen(f->str));
			ft_strlcat(tmp + length - ft_strlen(f->str), f->str, ft_strlen(f->str) + 1);
		}
		else
			tmp = f->str;
	}
	f->str = tmp;
	// ft_strdel(&tmp);
}

void 	putstrf(va_list ap, f_flags **flags)
{
	f_flags *f;

	f = *flags;
	//call function to finalize str based on flags/fw/precision
	f->str = va_arg(ap, char *);
	printstr(&f);
}

void 	putunsigned(va_list ap, f_flags **flags)
{
	f_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putunsignedchar(ap, 10);
	else if (f->h == 1)
		f->str = putushort(ap, 10);
	else if (f->l == 1)
		f->str = putulong(ap, 10);
	else if (f->ll == 1)
		f->str = putulonglong(ap, 10);
	else if (f->j == 1)
		f->str = putuintmax(ap, 10);
	else if (f->z == 1)
		f->str = putsizet(ap, 10);
	else
		f->str = putuintmax(ap, 10);
	//call function to finalize str based on flags/fw/precision
	printun(&f);
}

void 	puthex(va_list ap, f_flags **flags)
{
	f_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putunsignedchar(ap, 16);
	else if (f->h == 1)
		f->str = putushort(ap, 16);
	else if (f->l == 1)
		f->str = putulong(ap, 16);
	else if (f->ll == 1)
		f->str = putulonglong(ap, 16);
	else if (f->j == 1)
		f->str = putuintmax(ap, 16);
	else if (f->z == 1)
		f->str = putsizet(ap, 16);
	else
		f->str = putuintmax(ap, 16);
	//call function to finalize str based on flags/fw/precision
	printhex(&f);
}

void 	putoctal(va_list ap, f_flags **flags)
{
	f_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putunsignedchar(ap, 8);
	else if (f->h == 1)
		f->str = putushort(ap, 8);
	else if (f->l == 1)
		f->str = putulong(ap, 8);
	else if (f->ll == 1)
		f->str = putulonglong(ap, 8);
	else if (f->j == 1)
		f->str = putuintmax(ap, 8);
	else if (f->z == 1)
		f->str = putsizet(ap, 8);
	else
		f->str = putuintmax(ap, 8);
	//call function to finalize str based on flags/fw/precision
	printoctal(&f);
}


void 	putlint(va_list ap, f_flags **flags)
{
	f_flags *f;

	f = *flags;
	if (f->hh == 1)
		f->str = putsignedchar(ap, 10);
	else if (f->h == 1)
		f->str = putshort(ap, 10);
	else if (f->l == 1)
		f->str = putlong(ap, 10);
	else if (f->ll == 1)
		f->str = putlonglong(ap, 10);
	else if (f->j == 1)
		f->str = putintmax(ap, 10);
	else if (f->z == 1)
		f->str = putsizet(ap, 10);
	else
		f->str = putintmax(ap, 10);
	//call function to finalize str based on flags/fw/precision
	printdecimal(&f);
}

void	printchar(f_flags **flags)
{
	f_flags *f;
	int 	length;
	char 	*tmp;

	f = *flags;
	length = (int)ft_strlen(f->str);
	if (f->fw > length)
	{
		tmp = ft_strnew(f->fw);
		if (f->neg == 1)
		{
			tmp[0] = f->str[0];
			ft_strfill(tmp, ' ', 1, f->fw);
			tmp[f->fw] = '\0';
		}
		else
		{
			ft_strfill(tmp, ' ', 0, f->fw - 1);
			tmp[f->fw - 1] = f->str[0];
			tmp[f->fw] = '\0';
		}
		f->str = tmp;
	}
	ft_strdel(&tmp);
}

void 	putuchar(va_list ap, f_flags **flags)
{
	f_flags		*f;
	int 		c;

	f = *flags;
	c = va_arg(ap, int);
	//call function to finalize str based on flags/fw/precision
	f->str[0] = c;
	printchar(flags);
}

void	putptr(va_list ap, f_flags **flags)
{
	f_flags		*f;
	void 		*ptr;

	f = *flags;
	ptr = va_arg(ap, void*);
	f->str = ft_strjoin("0x", itoa_base_lower((uintmax_t)ptr, 16));
}

void 	putform(char *s, va_list ap, f_flags **flags, int *index)
{
	int		t;
	f_flags *f;

	t = *index;
	f = *flags;
	if (s[t] == 's')
		putstrf(ap, &f);
	else if (s[t] == 'p')
		putptr(ap, &f);
	else if (s[t] == 'd' || s[t] == 'i')
		putlint(ap, &f);
	else if (s[t] == 'o')
		putoctal(ap, &f); //add another field for identifier
	else if (s[t] == 'u')
		putunsigned(ap, &f); //same
	else if (s[t] == 'x')
		puthex(ap, &f); //same
	else if (s[t] == 'c')
		putuchar(ap, &f);
	t++;
	ft_putstrf(f->str);
	f->size += (int)ft_strlen(f->str);
	// printf("%s\n", f->str);
	*index = t;
}

/*
assign (#0-+ ) flags to t_flags struct
*/
void	populateflags(char *str, f_flags **flags, int *index)
{
	int		i;
	f_flags *f;

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

/*
assigns fw value to t_flags struct
*/
void 	populatefw(char *str, f_flags **flags, int *index)
{
	int		i;
	int		v;
	f_flags	*f;

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

/*
assigns precision value to t_flags struct
*/
void 	populateprecision(char *str, f_flags **flags, int *index)
{
	int		i;
	int		v;
	f_flags	*f;

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

/*
assigns length modifier (hh, h, l, ll, j, z) value to t_flags struct
*/
void 	populatelength(char *str, f_flags **flags, int *index)
{
	int 	i;
	f_flags *f;

	f = *flags;
	i = *index;
	if ((str[i] == 'h' && str[i+1] == 'h') || str[i] == 'h' 
		|| str[i] == 'l' || (str[i] == 'l' && str[i+1] == 'l') 
		|| str[i] == 'j' || str[i] == 'z')
	{
		if (str[i] == 'h' && str[i+1] == 'h')
			f->hh = 1;
		else if (str[i] == 'h')
			f->h = 1;
		else if (str[i] == 'l')
			f->l = 1;
		else if (str[i] == 'l' && str[i+1] == 'l')
			f->ll = 1;
		else if (str[i] == 'j')
			f->j = 1;
		else if (str[i] == 'z')
			f->z = 1;
		i++;
	}
	*index = i;
}

/*
Returns 1 if current char is a valid symbol
*/
int		issymbol(char *s, int *index)
{
	char	*str;
	int		t;

	t = *index;
	str = s;
	if (str[t] == '#' ||str[t] == '0' || str[t] == '-' || str[t] == ' ' 
		|| str[t] == '+' || (str[t] == 'h' && str[t+1] == 'h') 
		|| str[t] == 'h' || (str[t] == 'l' && str[t+1] == 'l') 
		|| str[t] == 'l' || str[t] == 'j' || str[t] == 'z' 
		|| str[t] == ' ' || (str[t] >= '0' && str[t] <= '9')
		|| str[t] == '.')
		return (1);
	else
		return (0);
	*index = t;
}

void		checksymbols(char *s, f_flags **flags, int *index)
{
	int 	t;
	f_flags *f;

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

void	setflags(f_flags **flags)
{
	f_flags *f;

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
	f->size = 0;
}

int		ft_printf(const char *format, ...)
{
	char 	*s;
	int		index;
	va_list ap;
	f_flags	*flags;

	flags = malloc(sizeof(f_flags));
	s = (char *)format;
	va_start(ap, format);
	setflags(&flags);
	index = 0;
	while (s[index])
	{
		if (s[index] == '%')
		{
			index++;
			if (issymbol(s, &index))
				checksymbols(s, &flags, &index);
			if (isconv(s, &index))
				putform(s, ap, &flags, &index);
			else
			{
				//put undefined char to str
				ft_putcharf(s[index++]);
				flags->size += 1;
			}
			setflags(&flags);
		}
		else
		{
			ft_putcharf(s[index++]);
			flags->size += 1;
		}
	}
	va_end(ap);
	return (flags->size);
}

// int 	main(void)
// {
// 	ft_printf("%#5.4x\n", 20);
// 	printf("%#6.4x\n", 20);
// 	// ft_printf("%s\n", "abcd\0");
// 	// ft_printf("%s\n", "abcd\n");

// 	return(0);
// }
/*
populate flags/fw/precision/length/
itoabase




*/


// void putstrf(va_list ap, f_flags **flags)
// {
// 	char *str;
// 	f_flags *f;
//
// 	f = *flags;
// 	str = va_arg(ap, char *);
// 	f->str = str;
// 	*flags = f;
// }
//
// void putptr(va_list ap, f_flags **flags)
// {
//
// }
//
// void putloct(va_list ap, f_flags **flags)
// {
//
// }
//
// void putlhex(va_list ap, f_flags **flags)
// {
//
// }
