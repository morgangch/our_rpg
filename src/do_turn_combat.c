/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** do_turn_combat
*/

#include "my.h"

int do_turn_combat(character_t *player, enemy_t *enemy, int spell_id)
{
    int dmg = calculate_dmg(player, enemy, spell_id);
    int dmg_e = calculate_dmg_teken(player, enemy);

    if (take_dmg_p(player, dmg_e))
        return 1;
    if (take_dmg_e(enemy, dmg))
        return 2;
    return 0;
}
