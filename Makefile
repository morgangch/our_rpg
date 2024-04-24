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
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

litle: all clean
