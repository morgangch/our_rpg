/*
** EPITECH PROJECT, 2023
** altfuncs
** File description:
** other file for subsidiary funcs for bsmyhunter
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "structures.h"

static void chunk_load(config_t *config, int x, int y)
{
    int link = config->active_map->map_layers->map_links[y][x];

    if (link > 0) {
        unload_map(config->active_map);
        load_map_player(config, link);
        if (config->player->character->quest_id > 0) {
            config->player->character
                ->quests[config->player->character->quest_id - 1]
                ->pos = config->player->sprite->pos;
            config->player->character
                ->quests[config->player->character->quest_id - 1]
                ->pos.y -= 200;
        }
    }
}

void move_quest(config_t *config, sprite_t *sprite, sfVector2f value)
{
    int new_x = sprite->pos.x + value.x;
    int new_y = sprite->pos.y + value.y;

    if (new_x < 0 || new_x > 1920 || new_y < 0 || new_y > 1920)
        return;
    sprite->pos.x += value.x;
    sprite->pos.y += value.y;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
}

int move_sprite(config_t *config, sprite_t *sprite, sfVector2f value)
{
    int new_x = sprite->pos.x + value.x;
    int new_y = sprite->pos.y + value.y;
    int link = 0;

    if (new_x < 0 || new_x > 1920 || new_y < 0 || new_y > 1920)
        return 0;
    link = config->active_map->map_layers
        ->map_links[(new_y / 48) + 1][(new_x / 48) + 1];
    if (link != 0)
        chunk_load(config, (new_x / 48) + 1, (new_y / 48) + 1);
    if (config->active_map->map_layers
        ->map_collisions[(new_y / 48) + 1][(new_x / 48) + 1] != 0)
        return 0;
    sprite->pos.x += value.x;
    sprite->pos.y += value.y;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfView_move(config->view, value);
    sfRenderWindow_setView(config->window, config->view);
    return 1;
}
