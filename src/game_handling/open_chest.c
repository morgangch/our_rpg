/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

int find_chest(config_t *config, int x, int y)
{
    for (int i = 0; config->active_map->chests[i] != NULL; i++) {
        if (config->active_map->chests[i]->pos.x + 30 >= x
            && config->active_map->chests[i]->pos.x - 30 <= x
            && config->active_map->chests[i]->pos.y + 30 >= y
            && config->active_map->chests[i]->pos.y - 30 <= y)
            return i;
    }
    return -1;
}

void open_chest(config_t *config, sprite_t *chest, int id)
{
    if (chest->rect.left == 32)
        return;
    printf("Chest %d opened\n", id);
    chest->rect.left = 32;
    sfSprite_setTextureRect(chest->sprite, chest->rect);
    switch (id) {
        case 0:
            add_item_to_inventory(config->player->character, 1);
            break;
        case 1:
            add_item_to_inventory(config->player->character, 2);
            break;
        default:
            break;
    }
    return;
}
