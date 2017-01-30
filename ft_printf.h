/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:44:53 by aganesh           #+#    #+#             */
/*   Updated: 2017/01/30 13:42:54 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_flags
{
	int		hash;
	int		zero;
	int		neg;
	int		pos;
	int		space;
	int		fw;
	int		precision;
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		j;
	int		z;
	char	length;
	char	*str;
	int		size;
}				t_flags;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strfill(char *str, char c, int start, int end);
void			putspaces(int size);
void			putzeros(int size);
void			ft_putcharf(char c);
void			ft_putstrf(char *str);
void			ft_putstrl(char *str, int size);
intmax_t		find_digits(intmax_t value, intmax_t base);
uintmax_t		ufind_digits(uintmax_t value, uintmax_t base);
char			*itoa_base(intmax_t value, intmax_t base, int ucase);
char			*utoa_base(uintmax_t value, uintmax_t base, int ucase);
char			*itoa_base_signed(ssize_t value, int base, int ucase);
char			*putsignedchar(va_list ap, int base, int ucase);
char			*putshort(va_list ap, int base, int ucase);
char			*putint(va_list ap, int base, int ucase);
char			*putlong(va_list ap, int base, int ucase);
char			*putlonglong(va_list ap, int base, int ucase);
char			*putunsignedchar(va_list ap, int base, int ucase);
char			*putushort(va_list ap, int base, int ucase);
char			*putulong(va_list ap, int base, int ucase);
char			*putulonglong(va_list ap, int base, int ucase);
char			*putuintmax(va_list ap, int base, int ucase);
char			*putsizet(va_list ap, int base, int ucase);
char			*putusizet(va_list ap, int base, int ucase);
char			*putintmax(va_list ap, int base, int ucase);
void			printstr(t_flags **flags);
void			strfwlhelp(t_flags **flags, int length);
void			otherstrhelp(t_flags **flags, int length);
void			printoctal(t_flags **flags);
void			octalhelp(t_flags **flags, int length);
void			realoctalhelp(t_flags **flags, int length);
void			printhex(t_flags **flags, int ucase);
void			hexhelper(t_flags **flags, int length, int ucase);
void			realhexhelper(t_flags **flags, int length, int ucase);
void			realdealhex(t_flags **flags, int length, int ucase);
void			printun(t_flags **flags);
char			*unhelper(t_flags **flags, int length, int strlen);
void			miniunhelper(t_flags **flags, char **tp, int length);
void			printdecimal(t_flags **flags);
void			decposspace(t_flags **flags, int *length);
void			decneghelper(t_flags **flags, int length);
void			dechelp(t_flags **flags, int length);
void			putunsigned(va_list ap, t_flags **flags);
void			puthex(va_list ap, t_flags **flags, int ucase);
void			putoctal(va_list ap, t_flags **flags);
void			putlint(va_list ap, t_flags **flags);
void			putlongint(va_list ap, t_flags **flags);
void			putrandchar(char *s, t_flags **flags, int *index);
void			putstrf(va_list ap, t_flags **flags);
void			putptr(va_list ap, t_flags **flags);
void			putuchar(va_list ap, t_flags **flags);
void			putform(char *s, va_list ap, t_flags **flags, int *index);
int				issymbol(char *s, int *index);
void			populateflags(char *str, t_flags **flags, int *index);
void			populatefw(char *str, t_flags **flags, int *index);
void			populateprecision(char *str, t_flags **flags, int *index);
void			populatelength(char *str, t_flags **flags, int *index);
void			checksymbols(char *s, t_flags **flags, int *index);
int				isconv(char *str, int *index);
void			setflags(t_flags **flags);
void			convspecifier(t_flags **flags, va_list ap, int *i, char *s);
int				ft_printf(const char *format, ...);

#endif
