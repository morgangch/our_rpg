/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Window handling for Main Menu
*/

#include "../../includes/my.h"

void m_menu_loop(config_t *config, sprite_t *sprite)
{
    while (config->is_menu == 1 && sfRenderWindow_isOpen(config->window)) {
        sfRenderWindow_clear(config->window, sfBlack);
        analyse_m_menu(config);
        sfRenderWindow_drawSprite(config->window, sprite->sprite, NULL);
        display_buttons(config->main_menu_buttons, config->window);
        sfRenderWindow_display(config->window);
    }
    return;
}

void to_m_menu(config_t *config)
{
    sprite_t *sprite = config->bsprites->menu_sprite;

    config->menu_view = sfRenderWindow_getDefaultView(config->window);
    sfRenderWindow_setView(config->window, config->menu_view);
    sfRenderWindow_setMouseCursorVisible(config->window, sfTrue);
    sfMusic_stop(config->sounds->main_theme);
    sfMusic_play(config->sounds->menu_theme);
    sfMusic_setVolume(config->sounds->menu_theme, 60);
    sfMusic_setLoop(config->sounds->menu_theme, sfTrue);
    sfRenderWindow_clear(config->window, sfBlack);
    sfRenderWindow_drawSprite(config->window, sprite->sprite, NULL);
    display_buttons(config->main_menu_buttons, config->window);
    sfRenderWindow_display(config->window);
    config->is_menu = 1;
    m_menu_loop(config, sprite);
}

void analyse_m_menu(config_t *config)
{
    while (sfRenderWindow_pollEvent(config->window, config->event)) {
        if ((config)->event->type == sfEvtClosed)
            close_window(config);
        analyse_buttons(*config->event, config, config->main_menu_buttons);
    }
}
