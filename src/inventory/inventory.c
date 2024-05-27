/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** Inventory
*/

#include "../includes/my.h"
#include "../includes/structures.h"

static void create_inv_sprite(
    character_t *player, sfVector2f pos, int i, int is_equip)
{
    if (is_equip == 0) {
        player->items_sprite[i] = create_sprite(player->item_datas[5],
            (sfIntRect){0, 0, 64, 64}, (offset_maxvalue_t){0, 0}, pos);
        sfSprite_setScale(
            player->items_sprite[i]->sprite, (sfVector2f){1.75, 1.75});
    } else {
        player->equiped_items[i] = create_sprite(player->equip_datas[5],
            (sfIntRect){0, 0, 64, 64}, (offset_maxvalue_t){0, 0}, pos);
        sfSprite_setScale(
            player->equiped_items[i]->sprite, (sfVector2f){1.75, 1.75});
    }
}

static void init_armor_weapon(character_t *player)
{
    char *item = NULL;

    player->equiped_items = malloc(sizeof(sprite_t *) * 3);
    for (int i = 0; i < 2; i++)
        player->equiped_items[i] = NULL;
    if (player->armor != 0) {
        item = read_item(player->armor);
        player->equip_datas = str_to_word_array(item, ';');
        create_inv_sprite(player, (sfVector2f){1385, 225}, 0, 1);
        free(player->equip_datas);
    }
    if (player->weapon != 0) {
        item = read_item(player->weapon);
        player->equip_datas = str_to_word_array(item, ';');
        create_inv_sprite(player, (sfVector2f){1585, 225}, 1, 1);
        free(player->equip_datas);
    }
}

void init_inventory(
    character_t *player, config_t *config, linked_list_int_t *tmp)
{
    char *item = NULL;
    sfVector2f pos = {1300, 365};
    int i = 0;

    player->items_sprite =
        malloc(sizeof(sprite_t *) * player->inventory_size + 3);
    for (; tmp != NULL; tmp = tmp->next) {
        item = read_item(tmp->data);
        player->item_datas = str_to_word_array(item, ';');
        create_inv_sprite(player, pos, i, 0);
        pos.x += 145;
        if ((i + 1) % 3 == 0) {
            pos.x = 1300;
            pos.y += 135;
        }
        free(player->item_datas);
        i++;
    }
    player->items_sprite[i] = NULL;
    init_armor_weapon(player);
}

void display_items_inventory(character_t *player, config_t *config)
{
    for (int i = 0; player->items_sprite[i] != NULL; i++) {
        sfRenderWindow_drawSprite(
            config->window, player->items_sprite[i]->sprite, NULL);
    }
    if (player->equiped_items[0] != NULL) {
        sfRenderWindow_drawSprite(
            config->window, player->equiped_items[0]->sprite, NULL);
    }
    if (player->equiped_items[1] != NULL) {
        sfRenderWindow_drawSprite(
            config->window, player->equiped_items[1]->sprite, NULL);
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

static int fetch_id_from_sprite(character_t *player, int i)
{
    linked_list_int_t *tmp = player->inventory;

    for (int j = 0; player->items_sprite[j] != NULL && j < i; j++)
        tmp = tmp->next;
    return tmp->data;
}

static void click_on_item(character_t *player, sfVector2i mouse_pos)
{
    int i = 0;
    sfVector2f pos = (sfVector2f){1385, 225};

    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + 64 * 1.75
        && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + 64 * 1.75)
        return;
    pos = (sfVector2f){1585, 225};
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + 64 * 1.75
        && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + 64 * 1.75)
        return;
    for (; player->items_sprite[i] != NULL; i++) {
        pos = player->items_sprite[i]->pos;
        if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + 64 * 1.75
            && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + 64 * 1.75)
            equip_item(player, fetch_id_from_sprite(player, i));
    }
}

static void click_on_equip(character_t *player, sfVector2i mouse_pos)
{
    sfVector2f pos;

    pos = (sfVector2f){1385, 225};
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + 64 * 1.75
        && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + 64 * 1.75
        && player->armor > 0) {
        unequip_item(player, 1);
        return;
    }
    pos = (sfVector2f){1585, 225};
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + 64 * 1.75
        && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + 64 * 1.75
        && player->weapon > 0) {
        unequip_item(player, 2);
        return;
    }
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
    if (config->event->type == sfEvtClosed)
        sfRenderWindow_close(config->window);
    if (config->event->type == sfEvtMouseButtonPressed) {
        if (config->event->mouseButton.button == sfMouseLeft) {
            click_on_item(config->player->character,
                (sfVector2i){config->event->mouseButton.x,
                    config->event->mouseButton.y});
            click_on_equip(config->player->character,
                (sfVector2i){config->event->mouseButton.x,
                    config->event->mouseButton.y});
            display_inventory(config->player->character, config);
        }
    }
}
