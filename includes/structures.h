/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** structures
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct character_s {
    int current_hp;
    int max_hp;
    int current_mp;
    int max_mp;
    int id_current_weapon;
    int id_current_armor;
    int id_current_accessory;
    int id_current_shield;
} character_t;

typedef struct map_info_s {
    int **map;
    sfVector2i size;
    int max_range;
} map_info_t;

typedef struct mouvement_s {
    int direction;
    struct mouvement_s *next;
} mouvement_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int offset;
    int max_value;
} sprite_t;

typedef struct game_s {
    unsigned long int score;
    int life;
    int level;
    unsigned long int highscore;
} game_t;

typedef struct offset_maxvalue_s {
    int offset;
    int max_value;
} offset_maxvalue_t;

typedef struct enemies_s {
    sprite_t *enemy1;
    sprite_t *enemy2;
    sprite_t *enemy3;
    sprite_t *enemy4;
    sprite_t *enemy5;
    int base_speed;
} enemies_t;

typedef struct button_s {
    sfRectangleShape *shape;
    sfText *text;
    sfColor defaultColor;
    sfColor hoverColor;
    sfColor currentColor;
    sfVector2f position;
    sfVector2f size;
    sfFont *font;
    sfBool isMouseOver;
} button_t;

typedef struct sounds_s {
    sfMusic *main_theme;
    sfMusic *menu_theme;
    sfSound *missing_sound;
    sfSoundBuffer *missing_sound_buffer;
    sfSound *losing_sound;
    sfSoundBuffer *losing_sound_bf;
    sfSound *touching_sound;
    sfSoundBuffer *touching_sound_bf;
    bool MainThemeIsPlaying;
} sounds_t;

typedef struct back_sprites_s {
    sprite_t *background_sprite;
    sprite_t *menu_sprite;
    sprite_t *gameover_sprite;
    sprite_t *pausemenu_sprite;
} back_sprites_t;

typedef struct buttons_s {
    button_t *save_button;
    button_t *load_button;
    button_t *new_button;
    button_t *settings_button;
    button_t *quit_button;
    button_t *cheat_button;
    button_t *resume_button;
} buttons_t;

typedef struct texts_s {
    sfText *score_text;
    sfText *life_text;
    sfText *level_text;
    sfText *highscore_text;
} texts_t;

typedef struct config_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent *event;
    float delta_time;
    int enemies_nb;
    int is_menu;
    sfClock *clock;
    game_t *game;
    buttons_t *main_menu_buttons;
    buttons_t *pause_menu_buttons;
    enemies_t *enemies;
    sprite_t *mouse_cursor;
    sounds_t *sounds;
    back_sprites_t *bsprites;
    texts_t *texts;
} config_t;
