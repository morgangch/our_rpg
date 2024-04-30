##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile myprintf
##

NAME	=	myrpg

SRCS =	src/main.c	\
		src/altfuncs.c \
		src/get_score.c \
		src/check_collisions.c \
		src/inits.c \
		src/frees_destructs.c \
		src/analysefuncs.c \
		src/altfuncs2.c \
		src/window_handling.c \
		src/get_shortest_path.c \

OBJ = $(SRCS:.c=.o)

CFLAGS = -W -Wall -Wno-unused-parameter -Wextra
CPPFLAGS = -Iincludes
LDFLAGS =  	-lcsfml-graphics -lcsfml-window -lcsfml-system \
			-lcsfml-audio -Llib/my -lmy
DBUGFLAGS = -g3
DBUGRUN_LOGNAME = valgrind-out.txt
DBUGRUN_FLAGS = --leak-check=yes --show-leak-kinds=all --track-origins=yes \
                --verbose --log-file=$(DBUGRUN_LOGNAME) \
                --trace-children=yes --track-fds=yes

all:	$(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C lib/my
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	@$(MAKE) clean -C lib/my
	@$(RM) -f $(NAME)

fclean:	clean
	@$(RM) -f $(OBJ)
	@$(MAKE) fclean -C lib/my

re: fclean all

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(OBJ)
	@$(MAKE) -C lib/my
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(DEBUGFLAGS)

debug_re: fclean debug

debug_run: debug_re
	@valgrind $(DBUGRUN_FLAGS) ./$(NAME)
	@cat $(DBBUGRUN_LOGNAME)
	@echo $$(cat $(DBBUGRUN_LOGNAME))
	@$(RM) $(DBBUGRUN_LOGNAME)
