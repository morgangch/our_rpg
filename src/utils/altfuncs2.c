/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** create_sprite
*/

#include "my.h"
#include "structures.h"

sprite_t *create_sprite(char *fp, sfIntRect rect,
    offset_maxvalue_t offset_maxvalue_v, sfVector2f pos)
{
    sprite_t *sprite_toreturn = malloc(sizeof(sprite_t));

    sprite_toreturn->sprite = sfSprite_create();
    sprite_toreturn->texture = sfTexture_createFromFile(fp, NULL);
    sprite_toreturn->pos = pos;
    sprite_toreturn->rect = rect;
    sfSprite_setTexture(
        sprite_toreturn->sprite, sprite_toreturn->texture, sfTrue);
    sfSprite_setTextureRect(sprite_toreturn->sprite, sprite_toreturn->rect);
    sfSprite_setPosition(sprite_toreturn->sprite, sprite_toreturn->pos);
    sprite_toreturn->offset = offset_maxvalue_v.offset;
    sprite_toreturn->max_value = offset_maxvalue_v.max_value;
    sfTexture_setSmooth(sprite_toreturn->texture, sfTrue);
    return sprite_toreturn;
}

void setup_game(config_t *config)
{
    sfImage *icon = sfImage_createFromFile("assets/gameicon.png");
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);

    sfRenderWindow_setFramerateLimit(config->window, 60);
    sfRenderWindow_setMouseCursorVisible(config->window, sfFalse);
    if (!config->sounds->main_theme)
        return;
    sfRenderWindow_setIcon(config->window, 64, 64, pixels);
}

void basic_checks(config_t *config)
{
    if (config->game->score > config->game->highscore)
        config->game->highscore = config->game->score;
    if (config->game->score % 100 == 0 && config->game->score != 0) {
        config->game->level++;
    }
    if (config->game->life == 0)
        game_over(config);
    if (config->is_menu == 1)
        to_p_menu(config);
}

static void reset_game(config_t *config)
{
    sfMusic_stop(config->sounds->main_theme);
    sfMusic_play(config->sounds->menu_theme);
    sfMusic_setVolume(config->sounds->menu_theme, 60);
    sfMusic_setLoop(config->sounds->menu_theme, sfTrue);
    sfRenderWindow_clear(config->window, sfBlack);
    sfRenderWindow_drawSprite(
        config->window, config->bsprites->gameover_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(
        config->window, config->mouse_cursor->sprite, NULL);
    sfRenderWindow_display(config->window);
    config->game->life = 3;
    config->game->score = 0;
    config->game->level = 1;
}

void game_over(config_t *config)
{
    sfClock *clock = sfClock_create();

    sfSound_play(config->sounds->losing_sound);
    reset_game(config);
    while (sfRenderWindow_isOpen(config->window)) {
        if (sfClock_getElapsedTime(clock).microseconds > 5000) {
            to_m_menu(config);
            break;
        }
    }
}
