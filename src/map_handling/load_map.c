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
    char **details = malloc(sizeof(char *) * 8);
    char *path = malloc(sizeof(char) * strlen(name) + 15);
    char *names[] = {"map.png", "map.coll", "map.light", "map.height",
        "map.inter", "map.links", "map.datas", NULL};

    path = strcpy(path, "assets/maps/");
    path = my_strcat(path, name);
    path = my_strcat(path, "/");
    for (int i = 0; i < 7; i++) {
        details[i] =
            malloc(sizeof(char) * strlen(path) + strlen(names[i]) + 1);
        details[i] = my_strcpy(details[i], path);
        details[i] = my_strcat(details[i], names[i]);
    }
    details[7] = NULL;
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
    buffer = malloc(sizeof(char) * st->st_size + 1);
    read(fd, buffer, st->st_size);
    buffer[st->st_size] = '\0';
    close(fd);
    free(st);
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

static void calc_datas_to_map(map_t *map, char **details)
{
    map->map_layers->map_collisions =
        get_map_datas(details[1], get_stat(details[1]));
    map->map_layers->map_light =
        get_map_datas(details[2], get_stat(details[2]));
    map->map_layers->map_height =
        get_map_datas(details[3], get_stat(details[3]));
    map->map_layers->map_interactibles =
        get_map_datas(details[4], get_stat(details[4]));
    map->map_layers->map_links =
        get_map_datas(details[5], get_stat(details[5]));
    map->map_layers->map_datas =
        get_map_content(details[6], get_stat(details[6]));
}

static void load_map(map_t *map)
{
    char **details = get_map_details(map->name);
    int fd = open(details[0], O_RDONLY);

    if (fd == -1)
        return;
    close(fd);
    map->map_texture = sfTexture_createFromFile(details[0], NULL);
    map->map = sfSprite_create();
    sfSprite_setTexture(map->map, map->map_texture, sfTrue);
    map->map_layers = malloc(sizeof(map_layers_t));
    calc_datas_to_map(map, details);
    get_pnjs(map);
    get_chests(map);
}

void load_map_player(config_t *config, int map_name)
{
    map_t *map = config->active_map;
    sfVector2f pos = {0, 0};
    char *pos_str = NULL;

    map->name = malloc(sizeof(char) * 7);
    sprintf(map->name, "map%02d", map_name);
    config->player->map = map_name;
    load_map(map);
    pos_str = strtok(map->map_layers->map_datas, "\n");
    strtok(pos_str, "=");
    pos.x = atoi(strtok(NULL, " "));
    pos.y = atoi(strtok(NULL, " "));
    config->player->pos = pos;
    config->player->sprite->pos = pos;
    sfSprite_setPosition(config->player->sprite->sprite, pos);
    config->active_map = map;
    if (config->view != NULL)
        sfView_destroy(config->view);
    config->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfView_setCenter(config->view, config->player->pos);
}

int unload_map(map_t *map)
{
    sfTexture_destroy(map->map_texture);
    sfSprite_destroy(map->map);
    for (int i = 0; map->map_layers->map_collisions[i] != NULL; i++)
        free(map->map_layers->map_collisions[i]);
    free(map->map_layers->map_collisions);
    for (int i = 0; map->map_layers->map_light[i] != NULL; i++)
        free(map->map_layers->map_light[i]);
    free(map->map_layers->map_light);
    for (int i = 0; map->map_layers->map_height[i] != NULL; i++)
        free(map->map_layers->map_height[i]);
    free(map->map_layers->map_height);
    for (int i = 0; map->map_layers->map_interactibles[i] != NULL; i++)
        free(map->map_layers->map_interactibles[i]);
    free(map->map_layers->map_interactibles);
    for (int i = 0; map->map_layers->map_links[i] != NULL; i++)
        free(map->map_layers->map_links[i]);
    free(map->map_layers->map_links);
    free(map->map_layers);
    return 0;
}
