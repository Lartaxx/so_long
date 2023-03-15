SRC = ft_putchar.c ft_puthexa.c ft_putnbr_base.c ft_putnbr_u.c ft_putnbr.c ft_putstr.c ft_printf.c

OBJS = $(SRC:.c=.o)

RM = rm -f

NAME = libftprintf.a

all : $(NAME)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean :	clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re