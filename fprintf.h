/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:44:53 by aganesh           #+#    #+#             */
/*   Updated: 2016/12/15 15:44:56 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPRINTF_H
# define FPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct 	t_flags
{
	int 	hash;
	int 	zero;
	int 	neg;
	int 	pos;
	int 	space;
	int 	fw;
	int 	precision;
	int 	hh;
	int 	h;
	int 	l;
	int 	ll;
	int 	j;
	int		z;
	char	length;
	char	*str;
	int		size;
}				f_flags;

extern char	*l_bases = "0123456789abcdef";
exterm char	*u_bases = "0123456789ABCDEF";

int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);

size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strfill(char *str, char c, int start, int end);;

void		putspaces(int size);
void		putzeros(int size);
void 		ft_putcharf(char c);
void	 	ft_putstrf(char *str);

intmax_t	find_digits(intmax_t value, intmax_t base);
uintmax_t	ufind_digits(uintmax_t value, uintmax_t base);
char	 	*itoa_base(intmax_t value, intmax_t base, int ucase);
char 		*utoa_base(uintmax_t value, uintmax_t base, int ucase);
char 		*itoa_base_signed(ssize_t value, int base, int ucase);



char		*putsignedchar(va_list ap, int base, int ucase);
char		*putshort(va_list ap, int base, int ucase);
char 		*putint(va_list ap, int base, int ucase);
char		*putlong(va_list ap, int base, int ucase);
char		*putlonglong(va_list ap, int base, int ucase);

char		*putunsignedchar(va_list ap, int base, int ucase);
char		*putushort(va_list ap, int base, int ucase);
char		*putulong(va_list ap, int base, int ucase);
char		*putulonglong(va_list ap, int base, int ucase);
char		*putuintmax(va_list ap, int base, int ucase);

char		*putsizet(va_list ap, int base, int ucase);
char 		*putusizet(va_list ap, int base, int ucase);
char		*putintmax(va_list ap, int base, int ucase);

void		printstr(f_flags **flags);
void		strfwlhelp(f_flags **flags, int length);
void		otherstrhelp(f_flags **flags, int length);

void		printoctal(f_flags **flags);
void		octalhelp(f_flags **flags, int length);
void		realoctalhelp(f_flags **flags, int length);

void		printhex(f_flags **flags, int ucase);
void		hexhelper(f_flags **flags, int length, int ucase);
void		realhexhelper(f_flags **flags, int length, int ucase);
void		realdealhex(f_flags **flags, int length, int ucase);

void		printun(f_flags **flags);
char		*unhelper(f_flags **flags, int length);
void		miniunhelper(f_flags **flags, char **tp, int length);

void		printdecimal(f_flags **flags);
void		decposspace(f_flags **flags, int *length);
void		decneghelper(f_flags **flags, int length);
void		dechelp(f_flags **flags, int length);

void 		putunsigned(va_list ap, f_flags **flags);
void 		puthex(va_list ap, f_flags **flags, int ucase);
void 		putoctal(va_list ap, f_flags **flags);
void 		putlint(va_list ap, f_flags **flags);
void		putlongint(va_list ap, f_flags **flags);

void		putrandchar(char *s, f_flags **flags, int *index);
void 		putstrf(va_list ap, f_flags **flags);
void		putptr(va_list ap, f_flags **flags);
void 		putuchar(va_list ap, f_flags **flags);
void 		putform(char *s, va_list ap, f_flags **flags, int *index);

int			issymbol(char *s, int *index);
void		populateflags(char *str, f_flags **flags, int *index);
void 		populatefw(char *str, f_flags **flags, int *index);
void 		populateprecision(char *str, f_flags **flags, int *index);
void 		populatelength(char *str, f_flags **flags, int *index);


void		checksymbols(char *s, f_flags **flags, int *index);
int			isconv(char *str, int *index);
void		setflags(f_flags **flags);
void		convspecifier(f_flags **flags, va_list ap, int *i, char *s);
int			ft_printf(const char *format, ...);

#endif