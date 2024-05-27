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
    character->current_hp = 100;
    character->current_mp = 100;
    character->gold = 0;
    character->intelligence = 0;
    character->level = 1;
    character->luck = 0;
    character->max_hp = 100;
    character->max_mp = 100;
    character->name = my_strdup("Player");
    character->strength = 0;
    character->weapon = 0;
    character->armor = 0;
    character->xp = 0;
    character->xp_max = 100;
    character->inventory = NULL;
    return character;
}
