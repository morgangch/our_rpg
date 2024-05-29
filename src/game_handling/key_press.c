/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

static void on_key_press3(config_t *config)
{
    switch ((config)->event->key.code) {
        case sfKeyI:
            if (config->is_menu == 0)
                config->is_menu = 3;
            else
                config->is_menu = 0;
            display_inventory(config->player->character, config);
            break;
        case sfKeyE:
            analyse_hitbox(config, config->player->direction);
            break;
        default:
            break;
    }
}

static void on_key_press2(config_t *config)
{
    switch ((config)->event->key.code) {
        case sfKeyUp:
        case sfKeyZ:
            handle_key(config, 3, config->is_menu);
            break;
        case sfKeyDown:
        case sfKeyS:
            handle_key(config, 2, config->is_menu);
            break;
        case sfKeyLeft:
        case sfKeyQ:
            handle_key(config, 1, config->is_menu);
            break;
        case sfKeyRight:
        case sfKeyD:
            handle_key(config, 0, config->is_menu);
            break;
        default:
            break;
    }
}

void on_key_press(config_t *config)
{
    if ((config)->event->type != sfEvtKeyPressed)
        return;
    switch ((config)->event->key.code) {
        case sfKeyEscape:
            to_p_menu(config);
            break;
        case sfKeyM:
            config->sounds->MainThemeIsPlaying =
                !config->sounds->MainThemeIsPlaying;
            if (config->sounds->MainThemeIsPlaying == true)
                sfMusic_play(config->sounds->main_theme);
            else
                sfMusic_pause(config->sounds->main_theme);
            break;
        default:
            if (config->is_menu == 0)
                on_key_press2(config);
            on_key_press3(config);
            break;
    }
}

void handle_key(config_t *config, int direction, int is_menu)
{
    sfVector2f pos = get_pos(direction);

    if (is_menu == 1)
        return;
    config->player->direction = direction;
    config->player->sprite->rect.left = 128 * direction;
    sfSprite_setTextureRect(config->player->sprite->sprite,
        config->player->sprite->rect);
    if (move_sprite(config, config->player->sprite, pos) == 1
        && config->player->character->quest_id != 0) {
        move_quest(config,
            config->player->character
                ->quests[config->player->character->quest_id - 1],
            pos);
    }
}
