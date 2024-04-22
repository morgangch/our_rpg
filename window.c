/*
** EPITECH PROJECT, 2024
** B-MUL : my_rpg
** File description:
** Window.c of my_rpg project
*/

#include "my.h"
#include "struct.h"

int event_handling(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return (0);
}

int main(void)
{
    main_window_t *main = malloc(sizeof(main_window_t));
    sfVideoMode mode = {1280, 720, 32};

    main->window = sfRenderWindow_create(mode, "My_RPG", sfClose, NULL);
    while (sfRenderWindow_isOpen(main->window)) {
        event_handling(main->window, main->event);
        sfRenderWindow_clear(main->window, sfBlack);
        sfRenderWindow_display(main->window);
    }
    sfRenderWindow_destroy(main->window);
}
