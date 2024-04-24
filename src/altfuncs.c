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
    sfSprite_setTextureRect(config->enemies->enemy1->sprite,
    config->enemies->enemy1->rect);
    sfSprite_setTextureRect(config->enemies->enemy2->sprite,
    config->enemies->enemy2->rect);
    sfSprite_setTextureRect(config->enemies->enemy3->sprite,
    config->enemies->enemy3->rect);
    sfSprite_setTextureRect(config->enemies->enemy4->sprite,
    config->enemies->enemy4->rect);
    sfSprite_setTextureRect(config->enemies->enemy5->sprite,
    config->enemies->enemy5->rect);
}

void update_button(button_t *button, sfVector2f mousePosition)
{
    int mouseposy = mousePosition.y;

    if (sfRectangleShape_getGlobalBounds(button->shape).left <= mousePosition.x
    && sfRectangleShape_getGlobalBounds(button->shape).left +
    sfRectangleShape_getGlobalBounds(button->shape).width >= mousePosition.x &&
    sfRectangleShape_getGlobalBounds(button->shape).top <= mouseposy &&
    sfRectangleShape_getGlobalBounds(button->shape).top +
    sfRectangleShape_getGlobalBounds(button->shape).height >= mouseposy) {
        button->isMouseOver = sfTrue;
        button->currentColor = button->hoverColor;
    } else {
        button->isMouseOver = sfFalse;
        button->currentColor = button->defaultColor;
    }
    sfRectangleShape_setFillColor(button->shape, button->currentColor);
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

enemies_t *generate_x_entities_with_sprite(int x, int time)
{
    enemies_t *enemies = malloc(sizeof(enemies_t));

    enemies->enemy1 = create_sprite("assets/aircraftcarrier.png",
    (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
    (sfVector2f){-100, 900});
    enemies->enemy2 = create_sprite("assets/aircraftcarrier.png",
    (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
    (sfVector2f){0 - (rand() % 350), 800});
    enemies->enemy3 = create_sprite("assets/aircraftcarrier.png",
    (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
    (sfVector2f){0 - (rand() % 400), 800});
    enemies->enemy4 = create_sprite("assets/aircraftcarrier.png",
    (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
    (sfVector2f){0 - (rand() % 450), 800});
    enemies->enemy5 = create_sprite("assets/aircraftcarrier.png",
    (sfIntRect){0, 0, 400, 150}, (offset_maxvalue_t){400, 2800},
    (sfVector2f){0 - (rand() % 500), 800});
    enemies->base_speed = 1;
    return enemies;
}
