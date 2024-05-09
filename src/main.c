/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** tests and bootstrap for myhunter
*/

#include "my.h"
#include "structures.h"

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

static void set_text_m(config_t *config, button_t *button)
{
    if (button == NULL)
        return;
    sfRenderWindow_drawRectangleShape(config->window, button->shape, NULL);
    sfRenderWindow_drawText(config->window, button->text, NULL);
}

void mass_set_text_m(config_t *config, buttons_t *buttons)
{
    set_text_m(config, buttons->save_button);
    set_text_m(config, buttons->load_button);
    set_text_m(config, buttons->new_button);
    set_text_m(config, buttons->settings_button);
    set_text_m(config, buttons->quit_button);
    set_text_m(config, buttons->resume_button);
    set_text_m(config, buttons->cheat_button);
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
        analyse_events(config, 0);
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

void to_game(config_t *config)
{
    return;
}

/*void to_game(config_t *config)
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
}*/
int main(int ac, char **av)
{
    config_t *config;

    if (ac == 2 && (my_strcmp(av[1], "-h") == 0))
        return my_printf("USAGE\n\t./my_rpg\n\nDESCRIPTION\n\t\
    My RPG project prototype...\n\t\
    For now it should include a working menu.\n");
    config = create_config();
    setup_game(config);
    if (!(config->window))
        return 1;
    to_m_menu(config);
    return 0;
}
