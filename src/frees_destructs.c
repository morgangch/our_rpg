/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** frees_destructs
*/

#include "my.h"
#include "structures.h"

static void destroy_enemies(enemies_t *enemies)
{
    sfSprite_destroy(enemies->enemy1->sprite);
    sfSprite_destroy(enemies->enemy2->sprite);
    sfSprite_destroy(enemies->enemy3->sprite);
    sfSprite_destroy(enemies->enemy4->sprite);
    sfSprite_destroy(enemies->enemy5->sprite);
    free(enemies->enemy1);
    free(enemies->enemy2);
    free(enemies->enemy3);
    free(enemies->enemy4);
    free(enemies->enemy5);
    free(enemies);
}

static void destroy_bsprites(back_sprites_t *bsprites)
{
    sfSprite_destroy(bsprites->background_sprite->sprite);
    sfSprite_destroy(bsprites->menu_sprite->sprite);
    sfSprite_destroy(bsprites->gameover_sprite->sprite);
    free(bsprites->background_sprite);
    free(bsprites->menu_sprite);
    free(bsprites->gameover_sprite);
    free(bsprites);
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
    sfRectangleShape_destroy(button->shape);
    sfText_destroy(button->text);
    free(button);
}

static void destroy_buttons(buttons_t *buttons)
{
    destroy_button(buttons->save_button);
    destroy_button(buttons->load_button);
    destroy_button(buttons->new_button);
    destroy_button(buttons->settings_button);
    destroy_button(buttons->quit_button);
    destroy_button(buttons->cheat_button);
    destroy_button(buttons->resume_button);
    free(buttons);
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
    destroy_enemies(config->enemies);
    destroy_bsprites(config->bsprites);
    destroy_texts(config->texts);
    destroy_buttons(config->pause_menu_buttons);
    destroy_buttons(config->main_menu_buttons);
    destroy_sounds(config->sounds);
    destroy_game(config->game);
    destroy_mouse_cursor(config->mouse_cursor);
    free(config);
}
