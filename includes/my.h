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
int move_sprite(config_t *config, sprite_t *sprite, sfVector2f value);
void move_quest(config_t *config, sprite_t *sprite, sfVector2f value);
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
void settings_menu(config_t *config);
void on_key_press(config_t *config);
void save_loader(config_t *config);
void save_maker(config_t *config);
void new_game_menu(config_t *config);
void analyse_p_menu(config_t *config);
void analyse_m_menu(config_t *config);
char *my_strcat(char *dest, char const *src);
character_t *create_character(void);
int take_dmg_p(character_t *player, int dmg);
int take_dmg_e(enemy_t *ennemy, int dmg);
int my_strlen_until(char *str, char c);
char **str_to_word_array(char *str, char delimiter);
void remove_item_from_inventory(character_t *player, int item_id);
void add_item_to_inventory(character_t *player, int item_id);
void equip_item(character_t *player, int item_id);
void switch_inventory_item(
    character_t *player, character_t *player2, int item_id);
int unload_map(map_t *map);
void map_debug(map_t *map);
void load_map_player(config_t *config, int map_name);
int calculate_dmg_teken(character_t *player, enemy_t *enemy);
int calculate_dmg(character_t *player, enemy_t *ennemy, int spell_id);
int do_turn_combat(character_t *player, enemy_t *enemy, int spell_id);
void manage_inventory(character_t *player);
void free_all_inventory(character_t *player);
void create_inventory(character_t *player);
void display_inventory(character_t *player, config_t *config);
void manage_inventory_boucle(character_t *player);
player_t *load_player(void);
void save_player(player_t *player);
void button_actions(config_t *config, int action);
button_t *create_button(
    char *text, sfVector2f pos, button_t *head, sfVector2i action);
button_t *create_buttons(sfVideoMode mode, int pause);
int check_collision(int x, int y, sfRectangleShape *rect);
void analyse_buttons(sfEvent event, config_t *config, button_t *tmp);
void load_handler(config_t *config);
void save_handler(config_t *config);
void display_button(button_t *tmp, sfRenderWindow *window);
void display_buttons(button_t *buttons, sfRenderWindow *window);
void analyse_s_menu(config_t *config);
void to_s_menu(config_t *config);
void main_loop(config_t *config);
char *read_item(int item_id);
void analyse_hitbox(config_t *config, int direction);
sfVector2f get_future_pos(sfSprite *sprite, int direction);
sfVector2f get_pos(int direction);
void handle_key(config_t *config, int direction, int is_menu);
int find_chest(config_t *config, int x, int y);
void open_chest(config_t *config, sprite_t *chest, int id);
void get_chests(map_t *map);
int get_chests_count(map_t *map);
void get_pnjs(map_t *map);
void analyse_i_menu(config_t *config);
void unequip_item(character_t *player, int item_id);
int find_pnj(config_t *config, int x, int y);
int dialog_handling(config_t *config, int pnj_id, int line);
void analyse_d_menu(config_t *config);
void quest_init(config_t *config);
void analyse_quests(config_t *config);
void analyse_f_menu(config_t *config);
void to_fight(config_t *config, int enemy_id);
