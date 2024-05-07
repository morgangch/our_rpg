/*
** EPITECH PROJECT, 2023
** Lib header
** File description:
** header for lib
*/

#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <stdarg.h>
#include <stdbool.h>

static const char *const error_codes[] = {"None",
    "Wrong parameter", "Unknown error"};

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
    enemies_t *enemies;
    sprite_t *mouse_cursor;
    sounds_t *sounds;
    back_sprites_t *bsprites;
    buttons_t *buttons;
    texts_t *texts;
} config_t;

unsigned long int my_getnbr(char const *str);
int my_putchar(char);
long int my_put_nbr(long int);
int my_putstr(char const *);
int my_put_err(char const *);
int my_strcmp(char const *s1, char const *s2);
int char_checker(va_list ap, char c);
int char_checker2(va_list ap, char c);
int my_printf(char *s, ...);
int my_put_err(char const *str);
int my_error_handler(int code);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
int my_unsigned_nbr(unsigned long int nb);
int my_strlen(char const *str);
void open_and_read(int ac, char **path, char *str);
int buffer_display(int width, int height, int bitsPerPixel);
void analyse_events(config_t *config);
sprite_t *create_sprite(char *fp,
    sfIntRect rect, offset_maxvalue_t offset_maxvalue_v, sfVector2f pos);
config_t *create_config(void);
void close_window(config_t *config);
void move_rect(sprite_t *sprite);
void move_sprite(config_t *config, sprite_t *sprite, int value_y);
enemies_t *generate_x_entities_with_sprite(int x, int time, sfVideoMode mode);
void write_score(unsigned long int score);
unsigned long int get_score(void);
void to_menu(config_t *config, int pause);
char *my_itoa(unsigned long int nb);
void to_game(config_t *config);
int check_collision(config_t *config);
void manage_mouse_click(config_t *config);
void animate_enemies(config_t *config);
void move_enemies(config_t *config);
void analyse_menu(config_t *config);
void analyse_game(config_t *config);
void destroy_config(config_t *config);
void update_button(button_t *button, sfVector2f mousePosition);
void setup_game(config_t *config);
void draw_sprites(config_t *config);
void basic_checks(config_t *config);
void game_over(config_t *config);
char *my_strdup(const char *src);
int my_char_isupper(char c);
int my_char_islower(char c);
char my_charupcase(char c);
char my_charlowcase(char c);
int my_is_prime(int nb);
sfVector2f adapt_position(sfVector2f initial_pos, sfVideoMode mode);
mouvement_t *get_shortest_path(sfVector2i start, sfVector2i end,
    int **map, int max_range);
