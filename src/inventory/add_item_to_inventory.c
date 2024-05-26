/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** add_item_to_inventory
*/

#include "my.h"

void add_item_to_inventory(character_t *player, int item_id)
{
    linked_list_int_t *new = malloc(sizeof(linked_list_int_t));
    linked_list_int_t *tmp = player->inventory;

    new->data = item_id;
    new->next = NULL;
    if (player->inventory == NULL) {
        player->inventory = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    player->inventory_size++;
}
