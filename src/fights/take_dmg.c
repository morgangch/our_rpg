/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** teke_dmg
*/

#include "my.h"
#include "structures.h"

int take_dmg_e(enemy_t *ennemy, int dmg)
{
    ennemy->current_hp -= dmg;
    if (ennemy->current_hp <= 0)
        return 1;
    return 0;
}

int take_dmg_p(character_t *player, int dmg)
{
    player->current_hp -= dmg;
    if (player->current_hp <= 0)
        return 1;
    return 0;
}
