/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** Inventory
*/

#include "../includes/my.h"
#include "../includes/structures.h"

void display_inventory(character_t *player, config_t *config)
{
    linked_list_int_t *tmp = player->inventory;

    my_putstr("Inventory:\n");
    while (tmp != NULL) {
        printf("item : %s\n", read_item(tmp->data));
        tmp = tmp->next;
    }
    while (config->is_menu == 3) {
        sfRenderWindow_setView(config->window, config->menu_view);
        sfRenderWindow_setMouseCursorVisible(config->window, sfTrue);
        sfRenderWindow_clear(config->window, sfBlack);
        sfRenderWindow_drawSprite(
            config->window, config->bsprites->inventory_sprite->sprite, NULL);
        sfRenderWindow_display(config->window);
        analyse_events(config, 4);
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

void analyse_i_menu(config_t *config)
{
    if (config->event->type == sfEvtKeyPressed) {
        if (config->event->key.code == sfKeyI) {
            config->is_menu = 0;
            sfRenderWindow_setView(config->window, config->view);
            sfRenderWindow_setMouseCursorVisible(config->window, sfFalse);
        }
    }
}
