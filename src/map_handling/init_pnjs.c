/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Map loading code
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "structures.h"

static int get_pnjs_count_part(map_t *map, int y)
{
    int count = 0;

    for (int i = 0; i < 40; i++) {
        if (map->map_layers->map_interactibles[i][y] == 6)
            count++;
    }
    return count;
}

int get_pnjs_count(map_t *map)
{
    int count = 0;

    for (int y = 0; y < 40; y++)
        count += get_pnjs_count_part(map, y);
    return count;
}

static int get_pnjs_part(map_t *map, int y, int j)
{
    for (int i = 0; i < 40; i++) {
        if (map->map_layers->map_interactibles[i][y] == 6) {
            map->pnjs[j] = create_sprite("assets/sprites/RM.png",
                (sfIntRect){0, 0, 128, 128}, (offset_maxvalue_t){128, 128},
                (sfVector2f){y * 40, i * 40});
            sfSprite_setScale(map->pnjs[j]->sprite, (sfVector2f){0.7, 0.7});
            sfSprite_setTextureRect(
                map->pnjs[j]->sprite, (sfIntRect){128, 0, -128, 128});
            j++;
        }
    }
    return j;
}

void get_pnjs(map_t *map)
{
    int j = 0;
    int count = get_pnjs_count(map);

    map->pnjs = malloc(sizeof(sprite_t *) * count + 1);
    for (int y = 0; y < 40; y++)
        j = get_pnjs_part(map, y, j);
    if (j > 0)
        printf("PNJS loaded. 1st found at %f, %f\n", map->pnjs[0]->pos.x,
            map->pnjs[0]->pos.y);
    else
        printf("No PNJS found\n");
    map->pnjs[j] = NULL;
}
