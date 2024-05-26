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
        my_put_nbr(tmp->data);
        my_putstr("\n");
        tmp = tmp->next;
    }
}

void create_inventory(character_t *player)
{
    player->inventory = malloc(sizeof(linked_list_int_t));
    player->inventory = NULL;
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

void manage_inventory_boucle(character_t *player)
{
    int running = 1;
    char input;

    if (input == 'E' || input == 'e') {
        display_inventory(&player);
    } else if (input == 'E' || input == 'e') {
        running = 0;
    }
}

void manage_inventory(character_t *player)
{
    int running = 1;
    char input;

    create_inventory(&player);
    add_item_to_inventory(&player, 1);
    add_item_to_inventory(&player, 2);
    add_item_to_inventory(&player, 3);
    while (running) {
        if (read(STDIN_FILENO, &input, 1) > 0) {
            manage_inventory_boucle(&player);
        }
        usleep(100000);
    }
    free_all_inventory(&player);
}
