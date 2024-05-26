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

static int get_chests_count_part(map_t *map, int y)
{
    int count = 0;

    for (int i = 0; i < 40; i++) {
        if (map->map_layers->map_interactibles[i][y] == 5)
            count++;
    }
    return count;
}

int get_chests_count(map_t *map)
{
    int count = 0;

    for (int y = 0; y < 40; y++)
        count += get_chests_count_part(map, y);
    return count;
}

static int get_chests_part(map_t *map, int y, int j)
{
    for (int i = 0; i < 40; i++) {
        if (map->map_layers->map_interactibles[i][y] == 5) {
            map->chests[j] = create_sprite(
                "assets/sprites/chest.png", (sfIntRect){0, 0, 16, 16},
                (offset_maxvalue_t){16, 64}, (sfVector2f){y * 40, i * 30});
            sfSprite_setScale(map->chests[j]->sprite, (sfVector2f){3, 3});
            j++;
        }
    }
    return j;
}

void get_chests(map_t *map)
{
    int j = 0;
    int y = 0;
    int count = get_chests_count(map);

    map->chests = malloc(sizeof(sprite_t *) * count + 1);
    for (; y < 40; y++)
        j = get_chests_part(map, y, j);
    map->chests[j] = NULL;
}
