/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

int find_pnj(config_t *config, int x, int y)
{
    for (int i = 0; config->active_map->pnjs[i] != NULL; i++) {
        if (config->active_map->pnjs[i]->pos.x + 30 >= x
            && config->active_map->pnjs[i]->pos.x - 30 <= x
            && config->active_map->pnjs[i]->pos.y + 30 >= y
            && config->active_map->pnjs[i]->pos.y - 30 <= y)
            return i;
    }
    return -1;
}
