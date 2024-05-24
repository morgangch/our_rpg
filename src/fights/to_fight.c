/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** to_fight
*/

#include "my.h"
#include <string.h>

void to_fight(config_t *config, int enemy_type, int enemy_num)
{
    if (enemy_num < 0 || enemy_num > 4)
        enemy_type = 0;
    sfRenderWindow_setMouseCursorVisible(config->window, sfFalse);
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
