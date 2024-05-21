/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

static void handle_key(config_t *config, int direction)
{
    config->player->direction = direction;
    if (direction == 0)
        move_sprite(config, config->player->sprite, (sfVector2f){48, 0});
    if (direction == 1)
        move_sprite(config, config->player->sprite, (sfVector2f){-48, 0});
    if (direction == 2)
        move_sprite(config, config->player->sprite, (sfVector2f){0, 27});
    if (direction == 3)
        move_sprite(config, config->player->sprite, (sfVector2f){0, -27});
}

static void on_key_press2(config_t *config)
{
    switch ((config)->event->key.code) {
        case sfKeyUp:
        case sfKeyZ:
            handle_key(config, 3);
            break;
        case sfKeyDown:
        case sfKeyS:
            handle_key(config, 2);
            break;
        case sfKeyLeft:
        case sfKeyQ:
            move_sprite(config, config->player->sprite, (sfVector2f){-48, 0});
            break;
        case sfKeyRight:
        case sfKeyD:
            move_sprite(config, config->player->sprite, (sfVector2f){48, 0});
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
            on_key_press2(config);
            break;
    }
}

void analyse_menu(config_t *config, int menu)
{
    while (sfRenderWindow_pollEvent(config->window, config->event)) {
        if ((config)->event->type == sfEvtClosed)
            close_window(config);
        if (menu == 1)
            analyse_m_menu(config);
        if (menu == 2)
            analyse_p_menu(config);
        on_key_press(config);
    }
}

static void analyse_game2(config_t *config)
{
    if ((config)->event->type == sfEvtMouseMoved) {
        sfSprite_setPosition(config->mouse_cursor->sprite,
            (sfVector2f){
                (config)->event->mouseMove.x, (config)->event->mouseMove.y});
        sfRenderWindow_drawSprite(
            config->window, config->mouse_cursor->sprite, NULL);
    }
    if ((config)->event->type == sfEvtMouseButtonReleased) {
        move_rect(config->mouse_cursor);
        sfSprite_setTextureRect(
            config->mouse_cursor->sprite, config->mouse_cursor->rect);
        sfRenderWindow_drawSprite(
            config->window, config->mouse_cursor->sprite, NULL);
    }
}

void analyse_game(config_t *config)
{
    while (sfRenderWindow_pollEvent(config->window, config->event)) {
        if ((config)->event->type == sfEvtMouseButtonPressed) {
            manage_mouse_click(config);
            move_rect(config->mouse_cursor);
            sfSprite_setTextureRect(
                (config->mouse_cursor)->sprite, (config->mouse_cursor)->rect);
            sfRenderWindow_drawSprite(
                config->window, (config->mouse_cursor)->sprite, NULL);
        }
        if ((config)->event->type == sfEvtClosed)
            close_window(config);
        on_key_press(config);
        analyse_game2(config);
    }
}

void analyse_events(config_t *config, int menu)
{
    if (menu == 0) {
        analyse_game(config);
        return;
    }
    analyse_menu(config, menu);
}

void manage_mouse_click(config_t *config)
{
    sfMusic_setVolume(config->sounds->main_theme, 0);
    sfSound_play(config->sounds->missing_sound);
    sfMusic_setVolume(config->sounds->main_theme, 60);
}
