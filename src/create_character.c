/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** create_character
*/

#include "my.h"
#include "structures.h"

character_t *create_character(void)
{
    character_t *character = malloc(sizeof(character_t));

    if (!character)
        return NULL;
    character->current_hp = -1;
    character->current_mp = -1;
    character->gold = -1;
    character->intelligence = -1;
    character->level = -1;
    character->luck = -1;
    character->max_hp = -1;
    character->max_mp = -1;
    character->name = NULL;
    character->strength = -1;
    character->weapon = -1;
    character->xp = -1;
    character->xp_max = -1;
    return character;
}
