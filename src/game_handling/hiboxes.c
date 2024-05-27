/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

sfVector2f get_future_pos(sfSprite *sprite, int direction)
{
    sfVector2f pos = sfSprite_getPosition(sprite);

    if (direction == 0)
        return (sfVector2f){pos.x + 48, pos.y};
    if (direction == 1)
        return (sfVector2f){pos.x - 48, pos.y};
    if (direction == 2)
        return (sfVector2f){pos.x, pos.y + 27};
    if (direction == 3)
        return (sfVector2f){pos.x, pos.y - 27};
    return (sfVector2f){0, 0};
}

sfVector2f get_pos(int direction)
{
    if (direction == 0)
        return (sfVector2f){48, 0};
    if (direction == 1)
        return (sfVector2f){-48, 0};
    if (direction == 2)
        return (sfVector2f){0, 27};
    if (direction == 3)
        return (sfVector2f){0, -27};
    return (sfVector2f){0, 0};
}

void analyse_hitbox(config_t *config, int direction)
{
    sfVector2f pos = get_future_pos(config->player->sprite->sprite, direction);
    int chest = find_chest(config, pos.x, pos.y);
    int pnj = find_pnj(config, pos.x, pos.y);

    printf("Chest: %d analysed at %f, %f at dir %d\n", chest, pos.x, pos.y,
        direction);
    if (chest != -1)
        open_chest(config, config->active_map->chests[chest], chest);
    if (pnj != -1)
        dialog_handling(config, pnj + 1, 0);
}
