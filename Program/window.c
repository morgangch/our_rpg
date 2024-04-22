/*
** EPITECH PROJECT, 2024
** B-MUL : my_rpg
** File description:
** Window.c of my_rpg project
*/

#include "../includes/my.h"
#include "../includes/my.h"

int main(void)
{
    MainWindow main;
    sfVideoMode mode = {1280, 720, 32};
    main.window = sfRenderWindow_create(mode, "My_RPG", sfClose, NULL);

    while (sfRenderWindow_isOpen(main.window)) {
        while (sfRenderWindow_pollEvent(main.window, &main.event)) {
            if (main.event.type == sfEvtClosed)
                sfRenderWindow_close(main.window);
            }
        sfRenderWindow_clear(main.window, sfBlack);
        sfRenderWindow_display(main.window);
        }
    // Suppression des ressources
    sfRenderWindow_destroy(main.window);
}
