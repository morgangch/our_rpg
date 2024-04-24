/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** inits
*/
#include "my.h"

sounds_t *create_sounds(void)
{
    sounds_t *sounds_toreturn = malloc(sizeof(sounds_t));
    sfSoundBuffer* buffer = sfSoundBuffer_createFromFile(
        "assets/missing_sound.ogg");

    sounds_toreturn->main_theme = sfMusic_createFromFile("assets/theme.ogg");
    sounds_toreturn->menu_theme = sfMusic_createFromFile("assets/menu.ogg");
    sounds_toreturn->missing_sound = sfSound_create();
    sounds_toreturn->missing_sound_buffer = buffer;
    sfSound_setBuffer(sounds_toreturn->missing_sound,
    sounds_toreturn->missing_sound_buffer);
    buffer = sfSoundBuffer_createFromFile("assets/touching_sound.ogg");
    sounds_toreturn->touching_sound = sfSound_create();
    sounds_toreturn->touching_sound_bf = buffer;
    sfSound_setBuffer(sounds_toreturn->touching_sound,
    sounds_toreturn->touching_sound_bf);
    buffer = sfSoundBuffer_createFromFile("assets/losing_sound.ogg");
    sounds_toreturn->losing_sound_bf = buffer;
    sounds_toreturn->losing_sound = sfSound_create();
    sounds_toreturn->MainThemeIsPlaying = true;
    return sounds_toreturn;
}

static void finish_button(button_t *button)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");

    button->font = font;
    sfText_setFont(button->text, font);
    sfText_setCharacterSize(button->text, 20);
    sfText_setFillColor(button->text, sfWhite);
    button->isMouseOver = sfFalse;
}

void initialize_button(button_t *button, const char *buttonText,
    sfVector2f position, sfVector2f size)
{
    button->shape = sfRectangleShape_create();
    button->text = sfText_create();
    button->defaultColor = sfRed;
    button->hoverColor = sfWhite;
    button->currentColor = button->defaultColor;
    button->position = position;
    button->size = size;
    sfRectangleShape_setPosition(button->shape, position);
    sfRectangleShape_setSize(button->shape, size);
    sfRectangleShape_setFillColor(button->shape, button->currentColor);
    sfText_setString(button->text, buttonText);
    sfText_setPosition(button->text, (sfVector2f){position.x + 10,
    position.y + 10});
    finish_button(button);
}

buttons_t *create_buttons(void)
{
    buttons_t *buttons_toreturn = malloc(sizeof(buttons_t));

    buttons_toreturn->start_button = malloc(sizeof(button_t));
    buttons_toreturn->quit_button = malloc(sizeof(button_t));
    buttons_toreturn->cheat_button = malloc(sizeof(button_t));
    initialize_button(buttons_toreturn->start_button, "Start",
    (sfVector2f){800, 410}, (sfVector2f){120, 60});
    initialize_button(buttons_toreturn->quit_button, "Quit",
    (sfVector2f){800, 510}, (sfVector2f){120, 60});
    initialize_button(buttons_toreturn->cheat_button, "Cheat",
    (sfVector2f){1200, 310}, (sfVector2f){120, 60});
    return buttons_toreturn;
}

static back_sprites_t *create_back_sprites(void)
{
    back_sprites_t *bsprites_toreturn = malloc(sizeof(back_sprites_t));

    bsprites_toreturn->background_sprite = create_sprite(
        "assets/background.jpg", (sfIntRect){0, 0, 1920, 1080},
        (offset_maxvalue_t){0, 0}, (sfVector2f){0, 0});
    bsprites_toreturn->menu_sprite = create_sprite("assets/menu.jpg",
        (sfIntRect){0, 0, 1920, 1080}, (offset_maxvalue_t){0, 0},
        (sfVector2f){0, 0});
    bsprites_toreturn->gameover_sprite = create_sprite("assets/gameover.jpg",
        (sfIntRect){0, 0, 1920, 1080}, (offset_maxvalue_t){0, 0},
        (sfVector2f){0, 0});
    return bsprites_toreturn;
}

static texts_t *finish_texts(texts_t *texts_toreturn)
{
    sfText_setPosition(texts_toreturn->score_text, (sfVector2f){10, 10});
    sfText_setPosition(texts_toreturn->life_text, (sfVector2f){10, 60});
    sfText_setPosition(texts_toreturn->level_text, (sfVector2f){10, 110});
    sfText_setPosition(texts_toreturn->highscore_text, (sfVector2f){10, 160});
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
    game_toreturn->highscore = get_score();
    return game_toreturn;
}

static config_t *finish_config(config_t *config_toreturn)
{
    config_toreturn->buttons = create_buttons();
    config_toreturn->texts = create_texts();
    config_toreturn->mouse_cursor = create_sprite("assets/mousecursor.png",
    (sfIntRect){0, 0, 50, 100}, (offset_maxvalue_t){50, 100},
    (sfVector2f){0, 0});
    config_toreturn->enemies = generate_x_entities_with_sprite(
        config_toreturn->enemies_nb, 10);
    return config_toreturn;
}

config_t *create_config(int height, int width, int bitsPerPixel)
{
    config_t *config_toreturn = malloc(sizeof(config_t));

    config_toreturn->delta_time = 0.0;
    config_toreturn->clock = sfClock_create();
    config_toreturn->mode = (sfVideoMode){height, width, bitsPerPixel};
    config_toreturn->window = sfRenderWindow_create(config_toreturn->mode,
        "Watashi no kamikazehanta", sfResize | sfClose, NULL);
    config_toreturn->event = malloc(sizeof(sfEvent));
    config_toreturn->sounds = create_sounds();
    config_toreturn->bsprites = create_back_sprites();
    config_toreturn->enemies_nb = 10;
    config_toreturn->is_menu = 1;
    config_toreturn->game = create_game();
    return finish_config(config_toreturn);
}
