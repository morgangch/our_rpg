/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"

static int check_menu_click2(config_t *config)
{
    if (config->buttons->cheat_button->isMouseOver &&
    config->event->type == sfEvtMouseButtonPressed &&
    config->event->mouseButton.button == sfMouseLeft)
        return 3;
    return 0;
}

int check_menu_click(config_t *config)
{
    if (config->buttons->start_button->isMouseOver &&
    config->event->type == sfEvtMouseButtonPressed &&
    config->event->mouseButton.button == sfMouseLeft)
        return 1;
    if (config->buttons->quit_button->isMouseOver &&
    config->event->type == sfEvtMouseButtonPressed &&
    config->event->mouseButton.button == sfMouseLeft)
        return 2;
    return check_menu_click2(config);
}

static void analyse_menu2(config_t *config)
{
    switch (check_menu_click(config)) {
        case 1:
            to_game(config);
            break;
        case 2:
            sfRenderWindow_close(config->window);
            break;
        case 3:
            config->game->life = -1;
            break;
        default:
            break;
    }
}

static void on_key_press(config_t *config)
{
    if ((config)->event->type != sfEvtKeyPressed)
        return;
    switch ((config)->event->key.code) {
        case sfKeyEscape:
            to_menu(config, 1);
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

void analyse_menu(config_t *config)
{
    while (sfRenderWindow_pollEvent(config->window, config->event)) {
        if ((config)->event->type == sfEvtClosed)
            close_window(config);
        if ((config)->event->type == sfEvtMouseButtonPressed)
            analyse_menu2(config);
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

void analyse_events(config_t *config)
{
    if (config->is_menu == 0)
        analyse_game(config);
    else
        analyse_menu(config);
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
