##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile myprintf
##

NAME	=	myrpg

SRCS =	src/frees_destructs.c \
		src/analysefuncs.c \
		src/altfuncs.c \
		src/altfuncs2.c \
		src/window_handling.c \
		src/get_shortest_path.c \
		src/get_score.c \
		src/inits.c \
		src/menus/m_menu_window.c \
		src/menus/p_menu_window.c \
		src/utils/buttons.c \
		src/settings/settings_menu.c \
		src/save_handling/new_game.c \
		src/save_handling/save_load.c \
		src/save_handling/save_make.c \
		src/create_character.c \
		src/map_handling/load_map.c \
		src/take_dmg.c \
		src/calculate_dmg.c \
		src/to_game.c \
		##src/dialogs/*.c \
		##src/fights/*.c \
		##src/map_handling/*.c \
		##src/movements/*.c \
		##src/quests/*.c \
		##src/save_handling/*.c \
		##src/settings/*.c \

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
	@$(CC) -o $(NAME) $(OBJ) src/main.c -Iincludes $(LDFLAGS)

tests_run: $(OBJ)
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
