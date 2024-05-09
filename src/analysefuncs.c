/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

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
        (sfVector2f){(config)->event->mouseMove.x,
        (config)->event->mouseMove.y});
        sfRenderWindow_drawSprite(config->window,
        config->mouse_cursor->sprite, NULL);
    }
    if ((config)->event->type == sfEvtMouseButtonReleased) {
        move_rect(config->mouse_cursor);
        sfSprite_setTextureRect(config->mouse_cursor->sprite,
        config->mouse_cursor->rect);
        sfRenderWindow_drawSprite(config->window,
        config->mouse_cursor->sprite, NULL);
    }
}

void analyse_game(config_t *config)
{
    while (sfRenderWindow_pollEvent(config->window, config->event)) {
        if ((config)->event->type == sfEvtMouseButtonPressed) {
            manage_mouse_click(config);
            move_rect(config->mouse_cursor);
            sfSprite_setTextureRect((config->mouse_cursor)->sprite,
            (config->mouse_cursor)->rect);
            sfRenderWindow_drawSprite(config->window,
            (config->mouse_cursor)->sprite, NULL);
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
    if (check_collision(config) > 0) {
        sfSound_play(config->sounds->touching_sound);
        config->game->score += 1;
        if (config->game->score % 10 == 0 && config->game->score != 0)
            config->enemies->base_speed++;
        sfMusic_setVolume(config->sounds->main_theme, 60);
        return;
    }
    sfSound_play(config->sounds->missing_sound);
    sfMusic_setVolume(config->sounds->main_theme, 60);
}
