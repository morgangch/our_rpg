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

typedef struct config_s config_t;
typedef struct button_s button_t;
typedef struct sprite_s sprite_t;

typedef struct enemy_s {
    int current_hp;
    int max_hp;
    int defense;
    int attack;
    int xp;
    int gold;
    int *drops;
    int *drops_chance;
    int *drops_nb;
    sprite_t *sprite;
} enemy_t;

typedef struct linked_list_int_s {
    int data;
    struct linked_list_int_s *next;
} linked_list_int_t;

typedef struct character_s {
    char *name;
    int level;
    int strength;
    int intelligence;
    int agility;
    int luck;
    int current_hp;
    int max_hp;
    int current_mp;
    int max_mp;
    int xp;
    int xp_max;
    int gold;
    int armor;
    int weapon;
    char **item_datas;
    char **equip_datas;
    sprite_t **items_sprite;
    sprite_t **equiped_items;
    sprite_t **quests;
    linked_list_int_t *inventory;
    int inventory_size;
    int quest_id;
} character_t;

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

typedef struct player_s {
    sfVector2f pos;
    int direction;
    int speed;
    int is_moving;
    int map;
    sprite_t *sprite;
    character_t *character;
} player_t;

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
    sprite_t *menu_sprite;
    sprite_t *gameover_sprite;
    sprite_t *pausemenu_sprite;
    sprite_t *inventory_sprite;
    sprite_t *fight_sprite;
} back_sprites_t;

typedef struct texts_s {
    sfText *score_text;
    sfText *life_text;
    sfText *level_text;
    sfText *highscore_text;
} texts_t;

typedef struct map_layers_s {
    int **map_collisions;
    int **map_light;
    int **map_height;
    int **map_interactibles;
    int **map_links;
    char *map_datas;
} map_layers_t;

typedef struct map_s {
    char *name;
    sfSprite *map;
    sfTexture *map_texture;
    map_layers_t *map_layers;
    sprite_t **chests;
    sprite_t **pnjs;
} map_t;

typedef struct fight_s {
    int enemy_id;
    enemy_t *enemy;
    player_t *player;
    int turn;
} fight_t;

typedef struct config_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent *event;
    float delta_time;
    int is_menu;
    sfClock *clock;
    game_t *game;
    button_t *main_menu_buttons;
    button_t *pause_menu_buttons;
    button_t *settings_menu_buttons;
    button_t *fight_menu_buttons;
    fight_t *fight;
    sprite_t *mouse_cursor;
    sounds_t *sounds;
    back_sprites_t *bsprites;
    player_t *player;
    texts_t *texts;
    map_t *active_map;
    sfView *view;
    const sfView *menu_view;
} config_t;

typedef struct button_s {
    sfColor col_normal;
    sfColor col_pressed;
    sfColor col_hover;
    sfText *text;
    sfRectangleShape *rect;
    int action;
    void (*callback)(config_t *config, int action);
    struct button_s *next;
} button_t;

typedef struct map_info_s {
    int **map;
    sfVector2i size;
    int max_range;
} map_info_t;
