CC =	gcc

FLAG =	-c -Wall -Wextra -Werror -O2

NAME =	libftprintf.a

LIB =	ar rc

RLIB =	ranlib

SRCS = ft_printf.c

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