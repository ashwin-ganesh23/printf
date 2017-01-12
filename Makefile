NAME = libftprintf.a

GCCFLAGS = gcc -c -Wall -Werror -Wextra

LIB = ar rc

RLIB = ranlib

HEADER_DIR = -I fprintf.h

SRCP =
SRCP += printf.c
#SRCP += flags.c
#SRCP += ft_puts.c

# SRCL =
# SRCL += ft_atoi.c
# SRCL += ft_bzero.c
# SRCL += ft_even.c
# SRCL += ft_get_size.c
# SRCL += ft_get_word.c
# SRCL += ft_isalnum.c
# SRCL += ft_isalpha.c
# SRCL += ft_isascii.c
# SRCL += ft_isdigit.c
# SRCL += ft_isprint.c
# SRCL += ft_itoa.c
# SRCL += ft_lstadd.c
# SRCL += ft_lstdel.c
# SRCL += ft_lstdelone.c
# SRCL += ft_lstiter.c
# SRCL += ft_lstmap.c
# SRCL += ft_lstnew.c
# SRCL += ft_memalloc.c
# SRCL += ft_memccpy.c
# SRCL += ft_memchr.c
# SRCL += ft_memcmp.c
# SRCL += ft_memcpy.c
# SRCL += ft_memcpy_rev.c
# SRCL += ft_memdel.c
# SRCL += ft_memmove.c
# SRCL += ft_memset.c
# SRCL += ft_odd.c
# SRCL += ft_putchar.c
# SRCL += ft_putchar_fd.c
# SRCL += ft_putendl.c
# SRCL += ft_putendl_fd.c
# SRCL += ft_putnbr.c
# SRCL += ft_putnbr_fd.c
# SRCL += ft_putstr.c
# SRCL += ft_putstr_fd.c
# SRCL += ft_strcat.c
# SRCL += ft_strchr.c
# SRCL += ft_strclr.c
# SRCL += ft_strcmp.c
# SRCL += ft_strcpy.c
# SRCL += ft_strdel.c
# SRCL += ft_strdup.c
# SRCL += ft_strequ.c
# SRCL += ft_striter.c
# SRCL += ft_striteri.c
# SRCL += ft_strjoin.c
# SRCL += ft_strlcat.c
# SRCL += ft_strlen.c
# SRCL += ft_strmap.c
# SRCL += ft_strmapi.c
# SRCL += ft_strncat.c
# SRCL += ft_strncmp.c
# SRCL += ft_strncpy.c
# SRCL += ft_strnequ.c
# SRCL += ft_strnew.c
# SRCL += ft_strnstr.c
# SRCL += ft_strrchr.c
# SRCL += ft_strsplit.c
# SRCL += ft_strstr.c
# SRCL += ft_strsub.c
# SRCL += ft_strtrim.c
# SRCL += ft_tolower.c
# SRCL += ft_toupper.c

SRC =
SRC += libft/ft_atoi.c
SRC += libft/ft_bzero.c
SRC += libft/ft_even.c
SRC += libft/ft_get_size.c
SRC += libft/ft_get_word.c
SRC += libft/ft_isalnum.c
SRC += libft/ft_isalpha.c
SRC += libft/ft_isascii.c
SRC += libft/ft_isdigit.c
SRC += libft/ft_isprint.c
SRC += libft/ft_itoa.c
SRC += libft/ft_lstadd.c
SRC += libft/ft_lstdel.c
SRC += libft/ft_lstdelone.c
SRC += libft/ft_lstiter.c
SRC += libft/ft_lstmap.c
SRC += libft/ft_lstnew.c
SRC += libft/ft_memalloc.c
SRC += libft/ft_memccpy.c
SRC += libft/ft_memchr.c
SRC += libft/ft_memcmp.c
SRC += libft/ft_memcpy.c
SRC += libft/ft_memcpy_rev.c
SRC += libft/ft_memdel.c
SRC += libft/ft_memmove.c
SRC += libft/ft_memset.c
SRC += libft/ft_odd.c
SRC += libft/ft_putchar.c
SRC += libft/ft_putchar_fd.c
SRC += libft/ft_putendl.c
SRC += libft/ft_putendl_fd.c
SRC += libft/ft_putnbr.c
SRC += libft/ft_putnbr_fd.c
SRC += libft/ft_putstr.c
SRC += libft/ft_putstr_fd.c
SRC += libft/ft_strcat.c
SRC += libft/ft_strchr.c
SRC += libft/ft_strclr.c
SRC += libft/ft_strcmp.c
SRC += libft/ft_strcpy.c
SRC += libft/ft_strdel.c
SRC += libft/ft_strdup.c
SRC += libft/ft_strequ.c
SRC += libft/ft_striter.c
SRC += libft/ft_striteri.c
SRC += libft/ft_strjoin.c
SRC += libft/ft_strlcat.c
SRC += libft/ft_strlen.c
SRC += libft/ft_strmap.c
SRC += libft/ft_strmapi.c
SRC += libft/ft_strncat.c
SRC += libft/ft_strncmp.c
SRC += libft/ft_strncpy.c
SRC += libft/ft_strnequ.c
SRC += libft/ft_strnew.c
SRC += libft/ft_strnstr.c
SRC += libft/ft_strrchr.c
SRC += libft/ft_strsplit.c
SRC += libft/ft_strstr.c
SRC += libft/ft_strsub.c
SRC += libft/ft_strtrim.c
SRC += libft/ft_tolower.c
SRC += libft/ft_toupper.c

OBJL =
OBJL += ft_atoi.o
OBJL += ft_bzero.o
OBJL += ft_even.o
OBJL += ft_get_size.o
OBJL += ft_get_word.o
OBJL += ft_isalnum.o
OBJL += ft_isalpha.o
OBJL += ft_isascii.o
OBJL += ft_isdigit.o
OBJL += ft_isprint.o
OBJL += ft_itoa.o
OBJL += ft_lstadd.o
OBJL += ft_lstdel.o
OBJL += ft_lstdelone.o
OBJL += ft_lstiter.o
OBJL += ft_lstmap.o
OBJL += ft_lstnew.o
OBJL += ft_memalloc.o
OBJL += ft_memccpy.o
OBJL += ft_memchr.o
OBJL += ft_memcmp.o
OBJL += ft_memcpy.o
OBJL += ft_memcpy_rev.o
OBJL += ft_memdel.o
OBJL += ft_memmove.o
OBJL += ft_memset.o
OBJL += ft_odd.o
OBJL += ft_putchar.o
OBJL += ft_putchar_fd.o
OBJL += ft_putendl.o
OBJL += ft_putendl_fd.o
OBJL += ft_putnbr.o
OBJL += ft_putnbr_fd.o
OBJL += ft_putstr.o
OBJL += ft_putstr_fd.o
OBJL += ft_strcat.o
OBJL += ft_strchr.o
OBJL += ft_strclr.o
OBJL += ft_strcmp.o
OBJL += ft_strcpy.o
OBJL += ft_strdel.o
OBJL += ft_strdup.o
OBJL += ft_strequ.o
OBJL += ft_striter.o
OBJL += ft_striteri.o
OBJL += ft_strjoin.o
OBJL += ft_strlcat.o
OBJL += ft_strlen.o
OBJL += ft_strmap.o
OBJL += ft_strmapi.o
OBJL += ft_strncat.o
OBJL += ft_strncmp.o
OBJL += ft_strncpy.o
OBJL += ft_strnequ.o
OBJL += ft_strnew.o
OBJL += ft_strnstr.o
OBJL += ft_strrchr.o
OBJL += ft_strsplit.o
OBJL += ft_strstr.o
OBJL += ft_strsub.o
OBJL += ft_strtrim.o
OBJL += ft_tolower.o
OBJL += ft_toupper.o


#OBJ = $(SRC:.c=.o)
OBJP = $(SRCP:.c=.o)

all: $(NAME)

$(NAME):
		@$(GCCFLAGS) $(HEADER_DIR) $(SRCP)
		@$(LIB) $(NAME) $(OBJP)
		@$(RLIB) $(NAME)

clean:
		@/bin/rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re