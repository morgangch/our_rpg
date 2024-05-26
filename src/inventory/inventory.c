/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** Inventory
*/

#include "../includes/my.h"
#include "../includes/structures.h"

void display_inventory(character_t *player)
{
    linked_list_int_t *tmp = player->inventory;

    my_putstr("Inventory:\n");
    while (tmp != NULL) {
        printf("item : %s\n", read_item(tmp->data));
        tmp = tmp->next;
    }
}

void free_all_inventory(character_t *player)
{
    linked_list_int_t *tmp = player->inventory;
    linked_list_int_t *next;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(player->inventory);
}
