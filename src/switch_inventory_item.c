/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** switch_inventory_item
*/

#include "my.h"

void switch_inventory_item(character_t *player,
    character_t *player2, int item_id)
{
    remove_item_from_inventory(player, item_id);
    add_item_to_inventory(player2, item_id);
}
