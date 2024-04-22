##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME	=	my_rpg

SRCS	=	window.c 		\

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS	=  -I./includes

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	rm -f $(OBJS)
