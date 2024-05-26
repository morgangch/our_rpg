/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** calculate_dmg_teken
*/

#include "my.h"

int calculate_dmg_teken(character_t *player, enemy_t *enemy)
{
    char *armor = read_item(player->armor);
    char *weapon = read_item(player->weapon);
    int dmg = enemy->attack;
    int crit = rand() % 100 - player->luck;

    weapon += my_strlen_until(weapon, ';') + 1;
    weapon += my_strlen_until(weapon, ';') + 1;
    if (*weapon == '4'){
        weapon += my_strlen_until(weapon, ';') + 1;
        crit -= atoi(weapon);
    }
    for (int i = 0; i < 2; i++)
        armor += my_strlen_until(armor, ';') + 1;
    if (crit > 70)
        dmg *= 2;
    dmg -= player->strength;
    dmg -= atoi(armor);
    if (dmg < 0)
        dmg = 0;
    return dmg;
}
