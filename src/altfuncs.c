/*
** EPITECH PROJECT, 2023
** altfuncs
** File description:
** other file for subsidiary funcs for bsmyhunter
*/

#include "my.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void close_window(config_t *config)
{
    sfRenderWindow_close(config->window);
}

void move_sprite(config_t *config, sprite_t *sprite, sfVector2f value)
{
    int new_x = sprite->pos.x + value.x;
    int new_y = sprite->pos.y + value.y;
    int link = 0;

    if (new_x < 0 || new_x > 1920 || new_y < 0 || new_y > 1920)
        return;
    link = config->active_map->map_layers->map_links[(new_y / 48) + 1]
        [(new_x / 48) + 1];
    if (link > 0) {
            unload_map(config->active_map);
            load_map_player(config, link);
    }
    if (config->active_map->map_layers->map_collisions[(new_y / 48) + 1]
        [(new_x / 48) + 1] != 0)
        return;
    sprite->pos.x += value.x;
    sprite->pos.y += value.y;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfView_move(config->view, value);
    sfRenderWindow_setView(config->window, config->view);
}
