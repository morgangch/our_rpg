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
#include "../../includes/my.h"
#include "../../includes/structures.h"

char **get_map_details(char *name)
{
    char **details = malloc(sizeof(char *) * 7);
    char *path = malloc(sizeof(char) * strlen(name) + 15);
    char *names[] = {"map.png", "map.coll", "map.light", "map.height",
        "map.inter", "map.links", NULL};

    path = strcpy(path, "assets/maps/");
    path = my_strcat(path, name);
    path = my_strcat(path, "/");
    for (int i = 0; i < 6; i++) {
        details[i] =
            malloc(sizeof(char) * strlen(path) + strlen(names[i]) + 1);
        details[i] = my_strcpy(details[i], path);
        details[i] = my_strcat(details[i], names[i]);
    }
    details[6] = NULL;
    return details;
}

struct stat *get_stat(char *path)
{
    struct stat *st = malloc(sizeof(struct stat));

    stat(path, st);
    return st;
}

static char *get_map_content(char *path, struct stat *st)
{
    int fd = open(path, O_RDONLY);
    char *buffer;

    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * st->st_size);
    read(fd, buffer, st->st_size);
    close(fd);
    return buffer;
}

static int **alloc_map_datas(void)
{
    int **map_datas = malloc(sizeof(int *) * 41);

    for (int i = 0; i < 40; i++)
        map_datas[i] = malloc(sizeof(int) * 41);
    map_datas[40] = NULL;
    return map_datas;
}

int **get_map_datas(char *path, struct stat *st)
{
    char *buffer = get_map_content(path, st);
    int **map_datas;
    int x = 0;
    int y = 0;

    if (buffer == NULL)
        return NULL;
    map_datas = alloc_map_datas();
    for (int i = 0; i < st->st_size && buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            x = 0;
            y++;
        }
        if (buffer[i] != ' ') {
            map_datas[y][x] = buffer[i] - '0';
            x++;
        }
    }
    return map_datas;
}

int load_map(map_t *map)
{
    char **details = get_map_details(map->name);
    struct stat *st_coll = get_stat(details[1]);
    struct stat *st_light = get_stat(details[2]);
    struct stat *st_height = get_stat(details[3]);
    struct stat *st_inter = get_stat(details[4]);
    struct stat *st_links = get_stat(details[5]);

    if (open(details[0], O_RDONLY) == -1)
        return 1;
    map->map_texture = sfTexture_createFromFile(details[0], NULL);
    map->map = sfSprite_create();
    sfSprite_setTexture(map->map, map->map_texture, sfTrue);
    map->map_layers = malloc(sizeof(map_layers_t));
    map->map_layers->map_collisions = get_map_datas(details[1], st_coll);
    map->map_layers->map_light = get_map_datas(details[2], st_light);
    map->map_layers->map_height = get_map_datas(details[3], st_height);
    map->map_layers->map_interactibles = get_map_datas(details[4], st_inter);
    map->map_layers->map_links = get_map_datas(details[5], st_links);
    return 0;
}
