##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME	=	my_rpg

SRCS	=	./Program/window.c 		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS	=  -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	rm -f $(OBJS)
