/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** to_game
*/

#include "my.h"
#include <string.h>

void move_rect(sprite_t *sprite)
{
    sprite->rect.left += sprite->offset;
    if (sprite->rect.left >= sprite->max_value)
        sprite->rect.left = 0;
}

static void clock_time_get(config_t *config)
{
    config->delta_time = sfClock_getElapsedTime(config->clock).microseconds;
    sfClock_restart(config->clock);
}

static void main_loop(config_t *config)
{
    float anim_delta_time = 0.0;

    anim_delta_time = anim_delta_time;
    while (sfRenderWindow_isOpen(config->window) && config->game->life != 0
        && config->is_menu == 0) {
        analyse_events(config, 0);
        sfRenderWindow_clear(config->window, sfBlack);
        sfRenderWindow_drawSprite(
            config->window, config->active_map->map, NULL);
        sfRenderWindow_drawSprite(
            config->window, config->player->sprite->sprite, NULL);
        sfRenderWindow_display(config->window);
        clock_time_get(config);
        basic_checks(config);
    }
}

void to_game(config_t *config)
{
    config->active_map = malloc(sizeof(map_t));
    load_map_player(config, 2);
    sfRenderWindow_setMouseCursorVisible(config->window, sfFalse);
    sfMusic_stop(config->sounds->menu_theme);
    sfMusic_play(config->sounds->main_theme);
    sfMusic_setVolume(config->sounds->main_theme, 60);
    sfMusic_setLoop(config->sounds->main_theme, sfTrue);
    sfRenderWindow_drawSprite(config->window, config->active_map->map, NULL);
    sfRenderWindow_drawSprite(
        config->window, config->player->sprite->sprite, NULL);
    sfRenderWindow_display(config->window);
    config->is_menu = 0;
    if (config->view == NULL) {
        config->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
        sfView_setCenter(config->view, config->player->pos);
    }
    sfRenderWindow_setView(config->window, config->view);
    main_loop(config);
}
