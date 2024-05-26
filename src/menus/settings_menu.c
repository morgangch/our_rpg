/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Window handling for Pause Menu
*/

#include "../../includes/my.h"

void s_menu_loop(config_t *config, sprite_t *sprite)
{
    while (config->is_menu == 1 && sfRenderWindow_isOpen(config->window)) {
        sfRenderWindow_clear(config->window, sfBlack);
        analyse_s_menu(config);
        sfRenderWindow_drawSprite(config->window, sprite->sprite, NULL);
        display_buttons(config->settings_menu_buttons, config->window);
        sfRenderWindow_display(config->window);
    }
    return;
}

void to_s_menu(config_t *config)
{
    sprite_t *sprite = config->bsprites->pausemenu_sprite;

    sfRenderWindow_clear(config->window, sfBlack);
    sfRenderWindow_drawSprite(config->window, sprite->sprite, NULL);
    display_buttons(config->pause_menu_buttons, config->window);
    sfRenderWindow_display(config->window);
    s_menu_loop(config, sprite);
}

void analyse_s_menu(config_t *config)
{
    while (sfRenderWindow_pollEvent(config->window, config->event)) {
        if ((config)->event->type == sfEvtClosed)
            close_window(config);
        analyse_buttons(*config->event, config, config->settings_menu_buttons);
    }
}
