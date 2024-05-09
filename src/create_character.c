/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** create_character
*/

#include "my.h"
#include "structures.h"

character_t *create_character(int hp, int mp)
{
    character_t *character = malloc(sizeof(character_t));

    if (!character)
        return NULL;
    character->current_hp = hp;
    character->max_hp = hp;
    character->current_mp = mp;
    character->max_mp = mp;
    character->id_current_weapon = -1;
    character->id_current_armor = -1;
    character->id_current_accessory = -1;
    character->id_current_shield = -1;
    return character;
}
