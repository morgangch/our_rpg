/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** remove_item_from_inventory
*/

#include "my.h"

void remove_item_from_inventory(character_t *player, int item_id)
{
    linked_list_int_t *tmp = player->inventory;
    linked_list_int_t *prev = NULL;

    if (tmp != NULL && tmp->data == item_id) {
        player->inventory = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->data != item_id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    player->inventory_size--;
    free(tmp);
}
