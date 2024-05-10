/*
** EPITECH PROJECT, 2023
** Lib header
** File description:
** header for lib
*/

#pragma once
#include "structures.h"

static const char *const error_codes[] = {
    "None", "Wrong parameter", "Unknown error"};

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
void analyse_events(config_t *config, int menu);
sprite_t *create_sprite(char *fp, sfIntRect rect,
    offset_maxvalue_t offset_maxvalue_v, sfVector2f pos);
config_t *create_config(void);
void close_window(config_t *config);
void move_rect(sprite_t *sprite);
void move_sprite(config_t *config, sprite_t *sprite, sfVector2f value);
void write_score(unsigned long int score);
unsigned long int get_score(void);
void to_p_menu(config_t *config);
void to_m_menu(config_t *config);
char *my_itoa(unsigned long int nb);
void to_game(config_t *config);
void manage_mouse_click(config_t *config);
void analyse_game(config_t *config);
void destroy_config(config_t *config);
void setup_game(config_t *config);
void basic_checks(config_t *config);
void game_over(config_t *config);
char *my_strdup(const char *src);
int my_char_isupper(char c);
int my_char_islower(char c);
char my_charupcase(char c);
char my_charlowcase(char c);
int my_is_prime(int nb);
sfVector2f adapt_position(sfVector2f initial_pos, sfVideoMode mode);
mouvement_t *get_shortest_path(
    sfVector2i start, sfVector2i end, int **map, int max_range);
void mass_set_text_m(config_t *config, buttons_t *buttons);
void settings_menu(config_t *config);
void on_key_press(config_t *config);
void save_loader(config_t *config);
void save_maker(config_t *config);
void new_game_menu(config_t *config);
void analyse_p_menu(config_t *config);
void analyse_m_menu(config_t *config);
void update_buttons(buttons_t *buttons, sfVector2f mousePosition, int menu);
buttons_t *create_buttons(sfVideoMode mode, int pause);
char *my_strcat(char *dest, char const *src);
character_t *create_character(void);
void take_dmg_p(character_t *player, int dmg);
int take_dmg_e(character_t *ennemy, int dmg);
int load_map(map_t *map);
