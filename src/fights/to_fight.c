/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** to_fight
*/

#include <string.h>
#include "my.h"

enemy_t *get_enemy_datas(int enemy_id)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->current_hp = 500;
    enemy->max_hp = 500;
    enemy->defense = 10;
    enemy->attack = 10;
    enemy->xp = 10;
    enemy->gold = 10;
    enemy->drops = malloc(sizeof(int) * 5);
    enemy->drops_chance = malloc(sizeof(int) * 5);
    enemy->drops_nb = malloc(sizeof(int) * 5);
    enemy->sprite = create_sprite("assets/sprites/TheoPossess.png",
        (sfIntRect){0, 0, 128, 128}, (offset_maxvalue_t){0, 0},
        (sfVector2f){1920 / 2, 1080 / 2});
    return enemy;
}

static void free_fight(config_t *config)
{
    free(config->fight->enemy->drops);
    free(config->fight->enemy->drops_chance);
    free(config->fight->enemy->drops_nb);
    sfSprite_destroy(config->fight->enemy->sprite->sprite);
    free(config->fight->enemy->sprite);
    free(config->fight->enemy);
}

void init_fight(config_t *config, int enemy_id)
{
    if (config->fight != NULL)
        free_fight(config);
    config->fight = malloc(sizeof(fight_t));
    config->fight->enemy = get_enemy_datas(enemy_id);
    config->fight->enemy_id = enemy_id;
    config->fight->turn = 0;
    config->fight->player = config->player;
}

static void display_fight(config_t *config)
{
    sfRenderWindow_clear(config->window, sfBlack);
    sfRenderWindow_drawSprite(
        config->window, config->fight->enemy->sprite->sprite, NULL);
    sfRenderWindow_drawSprite(
        config->window, config->fight->player->sprite->sprite, NULL);
    display_buttons(config->fight_menu_buttons, config->window);
    sfRenderWindow_display(config->window);
}

static void display_victory(config_t *config)
{
    config->fight->player->character->xp += config->fight->enemy->xp;
    config->fight->player->character->gold += config->fight->enemy->gold;
    config->is_menu = 0;
}

static void to_game_over(config_t *config)
{
    return;
}

void to_fight(config_t *config, int enemy_id)
{
    sfRenderWindow_setMouseCursorVisible(config->window, sfTrue);
    init_fight(config, enemy_id);
    config->is_menu = 6;
    while (config->is_menu == 6) {
        analyse_events(config, 6);
        display_fight(config);
        if (config->fight->player->character->current_hp <= 0)
            return to_game_over(config);
        if (config->fight->enemy->current_hp <= 0)
            return display_victory(config);
    }
}

void analyse_f_menu(config_t *config)
{
    if (config->event->type == sfEvtClosed)
        close_window(config);
    analyse_buttons(*config->event, config, config->fight_menu_buttons);
}
