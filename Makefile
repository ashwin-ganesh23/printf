CC =	gcc

FLAG =	-c -Wall -Wextra -Werror -O2

NAME =	libftprintf.a

LIB =	ar rc

RLIB =	ranlib

SRCS = 
SRCS += ft_printf.c
SRCS += basic_puts.c
SRCS += itoas.c
SRCS += libft_funcs.c
SRCS += libft_funcs_cont.c
SRCS += populate_flags.c
SRCS += print_decimal.c
SRCS += print_hex.c
SRCS += print_octal.c
SRCS += print_str.c
SRCS += print_un.c
SRCS += put_chars.c
SRCS += put_decimal.c
SRCS += put_length.c
SRCS += put_length_misc.c
SRCS += put_ulength.c

OBJS =	$(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):
		@$(CC) $(FLAG) $(SRCS)
		@$(LIB) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)

clean:
		@/bin/rm -f $(OBJS)

fclean:	clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re