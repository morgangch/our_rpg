##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile myprintf
##

NAME = myrpg

SRCS =	$(wildcard src/buttons/*.c) \
		$(wildcard src/dialogs/*.c) \
		$(wildcard src/fights/*.c) \
		$(wildcard src/game_handling/*.c) \
		$(wildcard src/game_init/*.c) \
		$(wildcard src/inventory/*.c) \
		$(wildcard src/map_handling/*.c) \
		$(wildcard src/menus/*.c) \
		$(wildcard src/movements/*.c) \
		$(wildcard src/quests/*.c) \
		$(wildcard src/pathfinding/*.c) \
		$(wildcard src/save_handling/*.c) \
		$(wildcard src/sprites/*.c) \
		$(wildcard src/utils/*.c) \

MAIN_SRC = src/main.c

OBJ = $(SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

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

$(NAME): $(OBJ) $(MAIN_OBJ)
	@$(MAKE) -C lib/my
	@$(CC) -o $(NAME) $(OBJ) $(MAIN_OBJ) -Iincludes $(LDFLAGS)

test: $(OBJ)
	@$(MAKE) -C lib/my
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	@$(MAKE) clean -C lib/my
	@$(RM) -f $(NAME)
	@$(RM) -f src/main.o

fclean:	clean
	@$(RM) -f $(OBJ)
	@$(MAKE) fclean -C lib/my

re: fclean all

debug: CFLAGS += -g3
debug: re
debug_re: fclean debug

debug_run: debug_re
	@valgrind $(DBUGRUN_FLAGS) ./$(NAME)
	@cat $(DBBUGRUN_LOGNAME)
	@echo $$(cat $(DBBUGRUN_LOGNAME))
	@$(RM) $(DBBUGRUN_LOGNAME)
