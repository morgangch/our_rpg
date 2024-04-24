##
## EPITECH PROJECT, 2023
## Day10
## File description:
## Makefile
##

NAME	=	libmy.a

SRCS	=	my_error_handler.c \
		my_strlen.c	\
		my_strcmp.c	\
		my_put_nbr.c	\
		myprintf.c	\
		my_unsigned_nbr.c	\
		my_putchar.c	\
		my_put_err.c	\
		my_strcpy.c	\
		my_putstr.c	\
		my_strncpy.c \
		my_getnbr.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	cp $(NAME) ../

clean:
	$(RM) -f $(OBJS)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f ../$(NAME)

re:	fclean all
