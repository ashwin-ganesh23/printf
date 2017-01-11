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
# include "./libft/libft.h"

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
	int		specifier;
}				f_flags;

extern void (*conv_id[14])(va_list ap, f_flags ff);

char	*g_conv = "sSpdDioOuUxXcC";
//int	char_count;

void	ft_strdel(char **as);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);

char	*ft_strfill(char *str, char c, int start, int end);
void 	ft_putcharf(char c);
void 	ft_putstrf(char *str);
int		find_digits(ssize_t value, int base);
char 	*itoa_base_upper(ssize_t value, int base);
char 	*itoa_base_lower(ssize_t value, int base);
char 	*itoa_base_unsigned(ssize_t value, int base);
char	*putsignedchar(va_list ap, int base);
char	*putshort(va_list ap, int base);
char	*putlong(va_list ap, int base);
char	*putlonglong(va_list ap, int base);
char	*putintmax(va_list ap, int base);
char	*putunsignedchar(va_list ap, int base);
char	*putushort(va_list ap, int base);
char	*putulong(va_list ap, int base);
char	*putulonglong(va_list ap, int base);
char	*putuintmax(va_list ap, int base);
char	*putsizet(va_list ap, int base);

void	printstr(f_flags **flags);
void	printoctal(f_flags **flags);
void	printhex(f_flags **flags);
void	printun(f_flags **flags);
void	printchar(f_flags **flags);
void	printdecimal(f_flags **flags);

void 	putstrf(va_list ap, f_flags **flags);
void	putptr(va_list ap, f_flags **flags);
void 	putunsigned(va_list ap, f_flags **flags, int c);
void 	putlint(va_list ap, f_flags **flags);

void 	putuchar(va_list ap, f_flags **flags);
void 	putform(char *s, va_list ap, f_flags **flags, int *index);

int		issymbol(char *s, int *index);
void	populateflags(char *str, f_flags **flags, int *index);
void 	populatefw(char *str, f_flags **flags, int *index);
void 	populateprecision(char *str, f_flags **flags, int *index);
void 	populatelength(char *str, f_flags **flags, int *index);
void	checksymbols(char *s, f_flags **flags, int *index);
int		isconv(char *str, int *index);

int		ft_printf(const char *format, ...);

#endif
