/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Window handling for Main Menu
*/

#include "../../includes/my.h"

void m_menu_loop(config_t *config, sprite_t *sprite)
{
    sfVector2f mousePosition = {0, 0};

    while (config->is_menu == 1 && sfRenderWindow_isOpen(config->window)) {
        analyse_events(config, 1);
        sfRenderWindow_clear(config->window, sfBlack);
        sfRenderWindow_drawSprite(config->window, sprite->sprite, NULL);
        mass_set_text_m(config, config->main_menu_buttons);
        mousePosition =
            (sfVector2f){sfMouse_getPositionRenderWindow(config->window).x,
                sfMouse_getPositionRenderWindow(config->window).y};
        update_buttons(config->main_menu_buttons, mousePosition, 2);
        sfRenderWindow_display(config->window);
    }
    if (config->is_menu == 0 && config->game->life != 0
        && sfRenderWindow_isOpen(config->window))
        to_game(config);
    return;
}

void to_m_menu(config_t *config)
{
    sprite_t *sprite = config->bsprites->menu_sprite;

    config->menu_view = sfRenderWindow_getDefaultView(config->window);
    sfRenderWindow_setView(config->window, config->menu_view);
    sfRenderWindow_setMouseCursorVisible(config->window, sfTrue);
    sfRenderWindow_drawSprite(
        config->window, config->mouse_cursor->sprite, NULL);
    sfSound_play(config->sounds->losing_sound);
    sfMusic_stop(config->sounds->main_theme);
    sfMusic_play(config->sounds->menu_theme);
    sfMusic_setVolume(config->sounds->menu_theme, 60);
    sfMusic_setLoop(config->sounds->menu_theme, sfTrue);
    sfRenderWindow_drawSprite(config->window, sprite->sprite, NULL);
    sfRenderWindow_display(config->window);
    config->is_menu = 1;
    m_menu_loop(config, sprite);
}

int check_m_menu_click(config_t *config)
{
    if (config->event->type != sfEvtMouseButtonPressed
        || config->event->mouseButton.button != sfMouseLeft)
        return 0;
    if (config->main_menu_buttons->resume_button->isMouseOver)
        return 5;
    if (config->main_menu_buttons->load_button->isMouseOver)
        return 1;
    if (config->main_menu_buttons->quit_button->isMouseOver)
        return 2;
    if (config->main_menu_buttons->new_button->isMouseOver)
        return 3;
    if (config->main_menu_buttons->settings_button->isMouseOver)
        return 4;
    return 0;
}

static void analyse_m_menu2(config_t *config)
{
    switch (check_m_menu_click(config)) {
        case 1:
            save_loader(config);
            break;
        case 2:
            sfRenderWindow_close(config->window);
            break;
        case 3:
            new_game_menu(config);
            break;
        case 4:
            settings_menu(config);
            break;
        case 5:
            to_game(config);
            break;
        default:
            break;
    }
}

void analyse_m_menu(config_t *config)
{
    while (sfRenderWindow_pollEvent(config->window, config->event)) {
        if ((config)->event->type == sfEvtClosed)
            close_window(config);
        if ((config)->event->type == sfEvtMouseButtonPressed)
            analyse_m_menu2(config);
        on_key_press(config);
    }
}
