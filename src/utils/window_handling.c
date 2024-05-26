/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** create_sprite
*/

#include "my.h"
#include "structures.h"

sfVector2f adapt_position(sfVector2f initial_pos, sfVideoMode mode)
{
    sfVector2f pos = {0, 0};

    pos.x = (initial_pos.x * mode.width) / 1920;
    pos.y = (initial_pos.y * mode.height) / 1080;
    return pos;
}

void close_window(config_t *config)
{
    sfRenderWindow_close(config->window);
}
