/*
** EPITECH PROJECT, 2023
** altfuncs
** File description:
** other file for subsidiary funcs for bsmyhunter
*/

#include "my.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void close_window(config_t *config)
{
    sfRenderWindow_close(config->window);
}

static void update_button(button_t *button, sfVector2f mousePosition)
{
    int mouseposy = mousePosition.y;

    if (sfRectangleShape_getGlobalBounds(button->shape).left <= mousePosition.x
        && sfRectangleShape_getGlobalBounds(button->shape).left
                + sfRectangleShape_getGlobalBounds(button->shape).width
            >= mousePosition.x
        && sfRectangleShape_getGlobalBounds(button->shape).top <= mouseposy
        && sfRectangleShape_getGlobalBounds(button->shape).top
                + sfRectangleShape_getGlobalBounds(button->shape).height
            >= mouseposy) {
        button->isMouseOver = sfTrue;
        button->currentColor = button->hoverColor;
    } else {
        button->isMouseOver = sfFalse;
        button->currentColor = button->defaultColor;
    }
    sfRectangleShape_setFillColor(button->shape, button->currentColor);
}

void update_buttons(buttons_t *buttons, sfVector2f mousePosition, int menu)
{
    update_button(buttons->load_button, mousePosition);
    update_button(buttons->settings_button, mousePosition);
    update_button(buttons->quit_button, mousePosition);
    update_button(buttons->resume_button, mousePosition);
    if (menu == 1)
        update_button(buttons->save_button, mousePosition);
    if (menu == 2) {
        update_button(buttons->cheat_button, mousePosition);
        update_button(buttons->new_button, mousePosition);
    }
}

void move_sprite(config_t *config, sprite_t *sprite, sfVector2f value)
{
    int new_x = sprite->pos.x + value.x;
    int new_y = sprite->pos.y + value.y;
    int link = 0;

    if (new_x < 0 || new_x > 1920 || new_y < 0 || new_y > 1920)
        return;
    link = config->active_map->map_layers->map_links[(new_y / 48) + 1]
        [(new_x / 48) + 1];
    if (link > 0) {
            unload_map(config->active_map);
            load_map_player(config, link);
    }
    if (config->active_map->map_layers->map_collisions[(new_y / 48) + 1]
        [(new_x / 48) + 1] != 0)
        return;
    sprite->pos.x += value.x;
    sprite->pos.y += value.y;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfView_move(config->view, value);
    sfRenderWindow_setView(config->window, config->view);
}
