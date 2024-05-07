/*
** EPITECH PROJECT, 2023
** altfuncs
** File description:
** other file for subsidiary funcs for bsmyhunter
*/
#include "my.h"

void close_window(config_t *config)
{
    sfRenderWindow_close(config->window);
    destroy_config(config);
}

void animate_enemies(config_t *config)
{
    move_rect(config->enemies->enemy1);
    move_rect(config->enemies->enemy2);
    move_rect(config->enemies->enemy3);
    move_rect(config->enemies->enemy4);
    move_rect(config->enemies->enemy5);
    sfSprite_setTextureRect(
        config->enemies->enemy1->sprite, config->enemies->enemy1->rect);
    sfSprite_setTextureRect(
        config->enemies->enemy2->sprite, config->enemies->enemy2->rect);
    sfSprite_setTextureRect(
        config->enemies->enemy3->sprite, config->enemies->enemy3->rect);
    sfSprite_setTextureRect(
        config->enemies->enemy4->sprite, config->enemies->enemy4->rect);
    sfSprite_setTextureRect(
        config->enemies->enemy5->sprite, config->enemies->enemy5->rect);
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

void move_sprite(config_t *config, sprite_t *sprite, int value_y)
{
    sprite->pos.y += value_y;
    sprite->pos.x += config->enemies->base_speed;
    if (sprite->pos.x >= 1920) {
        if (config->game->life == 0)
            return;
        sprite->pos.x = -rand() % 400;
        sprite->pos.y = 900;
        config->enemies->base_speed +=
            (config->game->level * (0.000015 * config->delta_time));
        config->game->life -= 1;
    }
    if (sprite->pos.y >= 1080 || sprite->pos.y <= 700)
        sprite->pos.y = 900;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
}

enemies_t *generate_x_entities_with_sprite(int x, int time, sfVideoMode mode)
{
    enemies_t *enemies = malloc(sizeof(enemies_t));

    enemies->enemy1 = create_sprite("assets/aircraftcarrier.png",
        (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
        adapt_position((sfVector2f){0, 800}, mode));
    enemies->enemy2 = create_sprite("assets/aircraftcarrier.png",
        (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
        adapt_position((sfVector2f){rand() % 100, 800}, mode));
    enemies->enemy3 = create_sprite("assets/aircraftcarrier.png",
        (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
        adapt_position((sfVector2f){rand() % 200, 800}, mode));
    enemies->enemy4 = create_sprite("assets/aircraftcarrier.png",
        (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
        adapt_position((sfVector2f){rand() % 300, 800}, mode));
    enemies->enemy5 = create_sprite("assets/aircraftcarrier.png",
        (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
        adapt_position((sfVector2f){rand() % 400, 800}, mode));
    enemies->base_speed = 1;
    return enemies;
}
