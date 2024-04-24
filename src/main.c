/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** tests and bootstrap for myhunter
*/
#include "my.h"

void move_rect(sprite_t *sprite)
{
    sprite->rect.left += sprite->offset;
    if (sprite->rect.left >= sprite->max_value)
        sprite->rect.left = 0;
}

void move_enemies(config_t *config)
{
    move_sprite(config, config->enemies->enemy1, 0);
    move_sprite(config, config->enemies->enemy2, 0);
    move_sprite(config, config->enemies->enemy3, 0);
    move_sprite(config, config->enemies->enemy4, 0);
    move_sprite(config, config->enemies->enemy5, 0);
}

static void mass_set_text_g(config_t *config)
{
    sfText_setString(config->texts->score_text,
    my_itoa(config->game->score));
    sfText_setString(config->texts->life_text,
    my_itoa(config->game->life));
    sfText_setString(config->texts->level_text,
    my_itoa(config->game->level));
    sfText_setString(config->texts->highscore_text,
    my_itoa(config->game->highscore));
    sfRenderWindow_drawText(config->window,
    config->texts->score_text, NULL);
    sfRenderWindow_drawText(config->window,
    config->texts->life_text, NULL);
    sfRenderWindow_drawText(config->window,
    config->texts->level_text, NULL);
    sfRenderWindow_drawText(config->window,
    config->texts->highscore_text, NULL);
}

static void mass_set_text_m(config_t *config)
{
    sfRenderWindow_drawRectangleShape(config->window,
    config->buttons->start_button->shape, NULL);
    sfRenderWindow_drawRectangleShape(config->window,
    config->buttons->quit_button->shape, NULL);
    sfRenderWindow_drawRectangleShape(config->window,
    config->buttons->cheat_button->shape, NULL);
    sfRenderWindow_drawText(config->window,
    config->buttons->start_button->text, NULL);
    sfRenderWindow_drawText(config->window,
    config->buttons->quit_button->text, NULL);
    sfRenderWindow_drawText(config->window,
    config->buttons->cheat_button->text, NULL);
}

static void clock_time_get(config_t *config)
{
    config->delta_time =
    sfClock_getElapsedTime(config->clock).microseconds;
    sfClock_restart(config->clock);
}

static void main_loop(config_t *config)
{
    float anim_delta_time = 0.0;

    while (sfRenderWindow_isOpen(config->window) &&
    config->game->life != 0 && config->is_menu == 0) {
        analyse_events(config);
        sfRenderWindow_clear(config->window, sfBlack);
        sfRenderWindow_drawSprite(config->window,
            config->bsprites->background_sprite->sprite, NULL);
        move_enemies(config);
        if (anim_delta_time > 50000) {
            animate_enemies(config);
            anim_delta_time = 0.0;
        } else
            anim_delta_time += config->delta_time;
        draw_sprites(config);
        mass_set_text_g(config);
        sfRenderWindow_display(config->window);
        clock_time_get(config);
        basic_checks(config);
    }
}

static void menu_loop(config_t *config)
{
    sfVector2f mousePosition;

    while (config->is_menu == 1 && sfRenderWindow_isOpen(config->window)) {
        analyse_events(config);
        sfRenderWindow_clear(config->window, sfBlack);
        sfRenderWindow_drawSprite(config->window,
        config->bsprites->menu_sprite->sprite, NULL);
        mass_set_text_m(config);
        mousePosition = (sfVector2f){sfMouse_getPositionRenderWindow(
        config->window).x, sfMouse_getPositionRenderWindow(config->window).y};
        update_button(config->buttons->start_button, mousePosition);
        update_button(config->buttons->quit_button, mousePosition);
        update_button(config->buttons->cheat_button, mousePosition);
        sfRenderWindow_display(config->window);
    }
    if (config->is_menu == 0 && config->game->life != 0
    && sfRenderWindow_isOpen(config->window))
        to_game(config);
    return;
}

void to_game(config_t *config)
{
    sfRenderWindow_setMouseCursorVisible(config->window, sfFalse);
    sfMusic_stop(config->sounds->menu_theme);
    sfMusic_play(config->sounds->main_theme);
    sfMusic_setVolume(config->sounds->main_theme, 60);
    sfMusic_setLoop(config->sounds->main_theme, sfTrue);
    sfRenderWindow_drawSprite(config->window,
        config->bsprites->background_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(config->window,
    config->mouse_cursor->sprite, NULL);
    sfRenderWindow_display(config->window);
    config->is_menu = 0;
    main_loop(config);
}

void to_menu(config_t *config)
{
    sfRenderWindow_setMouseCursorVisible(config->window, sfTrue);
    sfSound_play(config->sounds->losing_sound);
    sfMusic_stop(config->sounds->main_theme);
    sfMusic_play(config->sounds->menu_theme);
    sfMusic_setVolume(config->sounds->menu_theme, 60);
    sfMusic_setLoop(config->sounds->menu_theme, sfTrue);
    sfRenderWindow_drawSprite(config->window,
        config->bsprites->menu_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(config->window,
    config->mouse_cursor->sprite, NULL);
    sfRenderWindow_display(config->window);
    config->is_menu = 1;
    menu_loop(config);
}

int main(int ac, char **av)
{
    config_t *config;

    if (ac == 2 && (my_strcmp(av[1], "-h") == 0))
        return my_printf("USAGE\n\t./my_hunter\n\nDESCRIPTION\n\t\
    A game where you have to shoot american ships...\n\t\
    With kamikaze japanese planes.\n");
    config = create_config(1920, 1080, 32);
    setup_game(config);
    if (!(config->window))
        return 1;
    to_menu(config);
    return 0;
}
