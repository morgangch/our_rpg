/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** inits
*/

#include "my.h"
#include "structures.h"

sounds_t *create_sounds(void)
{
    sounds_t *sounds_toreturn = malloc(sizeof(sounds_t));
    sfSoundBuffer *buffer =
        sfSoundBuffer_createFromFile("assets/missing_sound.ogg");

    sounds_toreturn->main_theme = sfMusic_createFromFile("assets/theme.ogg");
    sounds_toreturn->menu_theme = sfMusic_createFromFile("assets/menu.ogg");
    sounds_toreturn->missing_sound = sfSound_create();
    sounds_toreturn->missing_sound_buffer = buffer;
    sfSound_setBuffer(
        sounds_toreturn->missing_sound, sounds_toreturn->missing_sound_buffer);
    buffer = sfSoundBuffer_createFromFile("assets/touching_sound.ogg");
    sounds_toreturn->touching_sound = sfSound_create();
    sounds_toreturn->touching_sound_bf = buffer;
    sfSound_setBuffer(
        sounds_toreturn->touching_sound, sounds_toreturn->touching_sound_bf);
    buffer = sfSoundBuffer_createFromFile("assets/losing_sound.ogg");
    sounds_toreturn->losing_sound_bf = buffer;
    sounds_toreturn->losing_sound = sfSound_create();
    sounds_toreturn->MainThemeIsPlaying = true;
    return sounds_toreturn;
}

static void create_back_sprites_2(config_t *config, back_sprites_t *bsprite)
{
    bsprite->inventory_sprite = create_sprite("assets/inventory.png",
        (sfIntRect){0, 0, config->mode.width, config->mode.height},
        (offset_maxvalue_t){0, 0}, (sfVector2f){0, 0});
    bsprite->fight_sprite = create_sprite("assets/fight.jpg",
        (sfIntRect){0, 0, config->mode.width, config->mode.height},
        (offset_maxvalue_t){0, 0}, (sfVector2f){0, 0});
}

static back_sprites_t *create_back_sprites(config_t *config)
{
    back_sprites_t *bsprite = malloc(sizeof(back_sprites_t));

    bsprite->menu_sprite = create_sprite("assets/menu.jpg",
        (sfIntRect){0, 0, config->mode.width, config->mode.height},
        (offset_maxvalue_t){0, 0}, (sfVector2f){0, 0});
    bsprite->gameover_sprite = create_sprite("assets/gameover.jpg",
        (sfIntRect){0, 0, config->mode.width, config->mode.height},
        (offset_maxvalue_t){0, 0}, (sfVector2f){0, 0});
    bsprite->pausemenu_sprite = create_sprite("assets/pause_menu.jpg",
        (sfIntRect){0, 0, config->mode.width, config->mode.height},
        (offset_maxvalue_t){0, 0}, (sfVector2f){0, 0});
    create_back_sprites_2(config, bsprite);
    return bsprite;
}

static texts_t *finish_texts(texts_t *texts_toreturn)
{
    sfText_setPosition(texts_toreturn->score_text,
        adapt_position((sfVector2f){10, 10}, sfVideoMode_getDesktopMode()));
    sfText_setPosition(texts_toreturn->life_text,
        adapt_position((sfVector2f){10, 60}, sfVideoMode_getDesktopMode()));
    sfText_setPosition(texts_toreturn->level_text,
        adapt_position((sfVector2f){10, 110}, sfVideoMode_getDesktopMode()));
    sfText_setPosition(texts_toreturn->highscore_text,
        adapt_position((sfVector2f){10, 160}, sfVideoMode_getDesktopMode()));
    return texts_toreturn;
}

static texts_t *create_texts(void)
{
    texts_t *texts_toreturn = malloc(sizeof(texts_t));

    texts_toreturn->score_text = sfText_create();
    texts_toreturn->life_text = sfText_create();
    texts_toreturn->level_text = sfText_create();
    texts_toreturn->highscore_text = sfText_create();
    sfText_setFont(texts_toreturn->score_text,
        sfFont_createFromFile("assets/fonts/arial.ttf"));
    sfText_setFont(texts_toreturn->life_text,
        sfFont_createFromFile("assets/fonts/arial.ttf"));
    sfText_setFont(texts_toreturn->level_text,
        sfFont_createFromFile("assets/fonts/arial.ttf"));
    sfText_setFont(texts_toreturn->highscore_text,
        sfFont_createFromFile("assets/fonts/arial.ttf"));
    sfText_setCharacterSize(texts_toreturn->score_text, 50);
    sfText_setCharacterSize(texts_toreturn->life_text, 50);
    sfText_setCharacterSize(texts_toreturn->level_text, 50);
    sfText_setCharacterSize(texts_toreturn->highscore_text, 50);
    return finish_texts(texts_toreturn);
}

static game_t *create_game(void)
{
    game_t *game_toreturn = malloc(sizeof(game_t));

    game_toreturn->score = 0;
    game_toreturn->life = 3;
    game_toreturn->level = 1;
    game_toreturn->highscore = 0;
    return game_toreturn;
}

player_t *create_player(void)
{
    player_t *player_toreturn = malloc(sizeof(player_t));

    player_toreturn->sprite =
        create_sprite("assets/sprites/Martin.png", (sfIntRect){0, 0, 128, 128},
            (offset_maxvalue_t){128, 128}, (sfVector2f){0, 0});
    sfSprite_setScale(player_toreturn->sprite->sprite, (sfVector2f){0.5, 0.5});
    player_toreturn->pos = (sfVector2f){0, 0};
    player_toreturn->speed = 10;
    player_toreturn->direction = 0;
    player_toreturn->is_moving = 0;
    player_toreturn->map = 2;
    player_toreturn->character = create_character();
    return player_toreturn;
}

static config_t *finish_config(config_t *config_toreturn)
{
    config_toreturn->main_menu_buttons =
        create_buttons(config_toreturn->mode, 0);
    config_toreturn->pause_menu_buttons =
        create_buttons(config_toreturn->mode, 1);
    config_toreturn->settings_menu_buttons =
        create_buttons(config_toreturn->mode, 2);
    config_toreturn->fight_menu_buttons =
        create_buttons(config_toreturn->mode, 3);
    config_toreturn->texts = create_texts();
    config_toreturn->mouse_cursor =
        create_sprite("assets/mousecursor.png", (sfIntRect){0, 0, 50, 100},
            (offset_maxvalue_t){50, 100}, (sfVector2f){0, 0});
    config_toreturn->player = malloc(sizeof(player_t));
    config_toreturn->player = create_player();
    quest_init(config_toreturn);
    return config_toreturn;
}

config_t *create_config(void)
{
    config_t *config_toreturn = malloc(sizeof(config_t));

    config_toreturn->delta_time = 0.0;
    config_toreturn->clock = sfClock_create();
    config_toreturn->mode = sfVideoMode_getDesktopMode();
    config_toreturn->window = sfRenderWindow_create(
        config_toreturn->mode, "MyRPG", sfResize | sfClose, NULL);
    config_toreturn->event = malloc(sizeof(sfEvent));
    config_toreturn->sounds = create_sounds();
    config_toreturn->bsprites = create_back_sprites(config_toreturn);
    config_toreturn->is_menu = 1;
    config_toreturn->game = create_game();
    return finish_config(config_toreturn);
}
