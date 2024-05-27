/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** Inventory
*/

#include "../includes/my.h"
#include "../includes/structures.h"

//  create_sprite("assets/background.jpg", (sfIntRect){0, 0, 1920, 1080},
//            (offset_maxvalue_t){0, 0}, (sfVector2f){0, 0});

static void create_inv_sprite(character_t *player, sfVector2f pos, int i)
{
    player->items_sprite[i] = create_sprite(player->item_datas[5],
        (sfIntRect){0, 0, 64, 64}, (offset_maxvalue_t){0, 0}, pos);
    sfSprite_setScale(
        player->items_sprite[i]->sprite, (sfVector2f){1.75, 1.75});
}

void init_inventory(
    character_t *player, config_t *config, linked_list_int_t *tmp)
{
    char *item = NULL;
    sfVector2f pos = {1300, 365};
    int i = 0;

    player->items_sprite =
        malloc(sizeof(sprite_t *) * player->inventory_size + 1);
    for (; tmp != NULL; tmp = tmp->next) {
        item = read_item(tmp->data);
        player->item_datas = str_to_word_array(item, ';');
        create_inv_sprite(player, pos, i);
        pos.x += 145;
        if ((i + 1) % 3 == 0) {
            pos.x = 1300;
            pos.y += 135;
        }
        free(player->item_datas);
        i++;
    }
    player->items_sprite[i] = NULL;
}

void display_items_inventory(character_t *player, config_t *config)
{
    for (int i = 0; player->items_sprite[i] != NULL; i++) {
        sfRenderWindow_drawSprite(
            config->window, player->items_sprite[i]->sprite, NULL);
    }
}

void display_inventory(character_t *player, config_t *config)
{
    linked_list_int_t *tmp = player->inventory;

    my_putstr("Inventory:\n");
    init_inventory(player, config, tmp);
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
        display_items_inventory(player, config);
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
