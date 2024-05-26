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
        printf("Chest %d at %f, %f ignored\n", i,
            config->active_map->chests[i]->pos.x,
            config->active_map->chests[i]->pos.y);
    }
    return -1;
}

void open_chest(config_t *config, sprite_t *chest)
{
    printf("Chest opened\n");
    return;
}
