/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** get_shortest_path
*/

#include "../includes/my.h"
#include "../includes/structures.h"

static int get_len_map(int **map)
{
    int len = 0;

    for (int i = 0; map[i]; i++)
        len++;
    return (len);
}

static int get_len_int(int *map)
{
    int len = 0;

    for (int i = 0; map[i] != -1; i++)
        len++;
    return (len);
}

static int **init_paths(int **map, sfVector2i end, int width, int height)
{
    int **new_map = malloc(sizeof(int *) * width + 1);

    for (int i = 0; i < width; i++){
        new_map[i] = malloc(sizeof(int) * height + 1);
        for (int j = 0; j < height; j++){
            new_map[i][j] = -1;
        }
    }
    return new_map;
}

void set_distances(sfVector2i pos, int distance, int **path, map_info_t map)
{
    if (distance > map.max_range || pos.x < 0 || pos.y < 0 ||
        pos.x >= map.size.x || pos.y >= map.size.y ||
        map.map[pos.x][pos.y] != 0 ||
        (path[pos.x][pos.y] < distance && path[pos.x][pos.y] != -1)){
        return;
    }
    path[pos.x][pos.y] = distance;
    set_distances((sfVector2i){pos.x + 1, pos.y}, distance + 1, path, map);
    set_distances((sfVector2i){pos.x - 1, pos.y}, distance + 1, path, map);
    set_distances((sfVector2i){pos.x, pos.y + 1}, distance + 1, path, map);
    set_distances((sfVector2i){pos.x, pos.y - 1}, distance + 1, path, map);
    set_distances((sfVector2i){pos.x + 1, pos.y + 1}, distance + 1, path, map);
    set_distances((sfVector2i){pos.x - 1, pos.y - 1}, distance + 1, path, map);
    set_distances((sfVector2i){pos.x + 1, pos.y - 1}, distance + 1, path, map);
    set_distances((sfVector2i){pos.x - 1, pos.y + 1}, distance + 1, path, map);
}

static int if_mouves3(mouvement_t *current,
    map_info_t *info, int distance, sfVector2i *pos)
{
    if (pos->y + 1 < info->size.y &&
        info->map[pos->x][pos->y + 1] == distance - 1){
        pos->y++;
        return 5;
    }
    if (pos->y - 1 >= 0 &&
        info->map[pos->x][pos->y - 1] == distance - 1){
        pos->y--;
        return 4;
    }
    return 0;
}

int if_mouves2(mouvement_t *current,
    map_info_t *info, int distance, sfVector2i *pos)
{
    if (pos->x - 1 >= 0 && pos->y - 1 >= 0 &&
        info->map[pos->x - 1][pos->y - 1] == distance - 1){
        pos->x--;
        pos->y--;
        return 1;
    }
    if (pos->x + 1 < info->size.x && pos->y + 1 < info->size.y &&
        info->map[pos->x + 1][pos->y + 1] == distance - 1){
        pos->x++;
        pos->y++;
        return 8;
    }
    if (pos->x - 1 >= 0 && info->map[pos->x - 1][pos->y] == distance - 1){
        pos->x--;
        return 2;
    }
    return if_mouves3(current, info, distance, pos);
}

int if_mouves(mouvement_t *current,
    map_info_t *info, int distance, sfVector2i *pos)
{
    if (pos->x + 1 < info->size.x &&
        info->map[pos->x + 1][pos->y] == distance - 1){
        pos->x++;
        return 7;
    }
    if (pos->x - 1 >= 0 && pos->y + 1 < info->size.y &&
        info->map[pos->x - 1][pos->y + 1] == distance - 1){
        pos->x--;
        pos->y++;
        return 3;
    }
    if (pos->x + 1 < info->size.x && pos->y - 1 >= 0 &&
        info->map[pos->x + 1][pos->y - 1] == distance - 1){
        pos->x++;
        pos->y--;
        return 6;
    }
    return if_mouves2(current, info, distance, pos);
}

mouvement_t *get_mouves(sfVector2i start, int **path, int width, int height)
{
    int distance = path[start.x][start.y];
    sfVector2i pos = start;
    mouvement_t *mouv = malloc(sizeof(mouvement_t));
    mouvement_t *current = mouv;
    map_info_t info = {path, (sfVector2i){width, height}, 0};

    while (distance > 0){
        current->direction = if_mouves(current, &info, distance, &pos);
        current->next = malloc(sizeof(mouvement_t));
        current = current->next;
        distance--;
    }
    return mouv;
}

mouvement_t *get_shortest_path(sfVector2i start, sfVector2i end,
    int **map, int max_range)
{
    int width = get_len_map(map);
    int height = get_len_int(map[0]);
    int **paths = init_paths(map, end, width, height);
    map_info_t map_info = {map, (sfVector2i){width, height}, max_range};

    set_distances(end, 0, paths, map_info);
    return get_mouves(start, paths, width, height);
}
