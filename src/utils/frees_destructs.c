/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** frees_destructs
*/

#include "my.h"
#include "structures.h"

static void destroy_bsprites(back_sprites_t *bsprites)
{
    sfSprite_destroy(bsprites->menu_sprite->sprite);
    sfSprite_destroy(bsprites->gameover_sprite->sprite);
    sfSprite_destroy(bsprites->inventory_sprite->sprite);
    free(bsprites->menu_sprite);
    free(bsprites->gameover_sprite);
    free(bsprites->inventory_sprite);
}

static void destroy_texts(texts_t *texts)
{
    sfText_destroy(texts->score_text);
    sfText_destroy(texts->life_text);
    sfText_destroy(texts->level_text);
    sfText_destroy(texts->highscore_text);
    free(texts);
}

static void destroy_button(button_t *button)
{
    if (button == NULL)
        return;
    sfRectangleShape_destroy(button->rect);
    sfText_destroy(button->text);
    free(button);
}

static void destroy_buttons(button_t *buttons)
{
    for (button_t *tmp = buttons; tmp != NULL; tmp = tmp->next)
        destroy_button(tmp);
}

static void destroy_sounds(sounds_t *sounds)
{
    sfMusic_destroy(sounds->main_theme);
    sfMusic_destroy(sounds->menu_theme);
    sfSound_destroy(sounds->missing_sound);
    sfSound_destroy(sounds->losing_sound);
    sfSound_destroy(sounds->touching_sound);
    sfSoundBuffer_destroy(sounds->missing_sound_buffer);
    sfSoundBuffer_destroy(sounds->losing_sound_bf);
    sfSoundBuffer_destroy(sounds->touching_sound_bf);
    free(sounds);
}

static void destroy_game(game_t *game)
{
    free(game);
}

static void destroy_mouse_cursor(sprite_t *mouse_cursor)
{
    sfSprite_destroy(mouse_cursor->sprite);
    free(mouse_cursor);
}

void destroy_config(config_t *config)
{
    sfRenderWindow_destroy(config->window);
    sfClock_destroy(config->clock);
    free(config->event);
    destroy_bsprites(config->bsprites);
    destroy_texts(config->texts);
    destroy_buttons(config->pause_menu_buttons);
    destroy_buttons(config->main_menu_buttons);
    destroy_buttons(config->settings_menu_buttons);
    destroy_sounds(config->sounds);
    destroy_game(config->game);
    destroy_mouse_cursor(config->mouse_cursor);
    free(config);
}
