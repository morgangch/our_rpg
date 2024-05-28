/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-edgar.maurel
** File description:
** main.c
*/

#include "../../includes/my.h"
#include "../../includes/structures.h"

void display_button(button_t *tmp, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, tmp->rect, NULL);
    sfRenderWindow_drawText(window, tmp->text, NULL);
}

void display_buttons(button_t *buttons, sfRenderWindow *window)
{
    for (button_t *tmp = buttons; tmp != NULL; tmp = tmp->next)
        display_button(tmp, window);
}

static void change_resolution(config_t *config, int action)
{
    if (action == 7) {
        sfRenderWindow_setSize(config->window, (sfVector2u){1920, 1080});
        config->mode.height = 1080;
        config->mode.width = 1920;
        sfRenderWindow_setView(config->window,
            sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080}));
    }
    if (action == 8) {
        sfRenderWindow_setSize(config->window, (sfVector2u){2256, 1504});
        config->mode.height = 1504;
        config->mode.width = 2256;
    }
    if (action == 9)
        to_m_menu(config);
}

static void more_button_actions(config_t *config, int action)
{
    if (action == 7)
        do_turn_combat(config->fight->player->character, config->fight->enemy,
            1);
    if (action == 8)
        do_turn_combat(config->fight->player->character, config->fight->enemy,
            2);
    if (action == 9)
        return;
    if (action == 10)
        return;
}

void button_actions(config_t *config, int action)
{
    if (action == 0)
        return;
    if (action == 1)
        to_game(config);
    if (action == 2)
        load_handler(config);
    if (action == 3)
        save_handler(config);
    if (action == 4)
        to_s_menu(config);
    if (action == 5)
        close_window(config);
    if (action == 6)
        to_game(config);
    more_button_actions(config, action);
    change_resolution(config, action);
}

static void add_button_datas(
    button_t *new_button, sfVector2f pos, int col_preset, int text_size)
{
    sfColor hover_colors[5] = {(sfColor){87, 87, 87, 255},
        (sfColor){77, 77, 77, 255}, (sfColor){67, 67, 67, 255},
        (sfColor){57, 57, 57, 255}};
    sfColor pressed_colors[5] = {(sfColor){51, 39, 39, 255},
        (sfColor){39, 51, 39, 255}, (sfColor){39, 39, 51, 255},
        (sfColor){51, 51, 39, 255}};
    sfColor normal_colors[5] = {(sfColor){255, 255, 255, 255},
        (sfColor){255, 255, 255, 255}, (sfColor){255, 255, 255, 255},
        (sfColor){255, 255, 255, 255}};

    new_button->col_hover = hover_colors[col_preset];
    new_button->col_pressed = pressed_colors[col_preset];
    new_button->col_normal = normal_colors[col_preset];
    new_button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(new_button->rect, pos);
    sfRectangleShape_setSize(
        new_button->rect, (sfVector2f){200, 60 + text_size});
    new_button->next = NULL;
}

static void add_button_texts(
    button_t *new_button, sfVector2f pos, int col_preset, char *text)
{
    sfColor text_colors[5] = {sfBlack, sfRed, sfGreen, sfBlue, sfWhite};

    new_button->text = sfText_create();
    sfText_setString(new_button->text, text);
    sfText_setFont(
        new_button->text, sfFont_createFromFile("assets/fonts/arial.ttf"));
    sfText_setCharacterSize(new_button->text, 20);
    sfText_setColor(new_button->text, text_colors[col_preset]);
    sfText_setPosition(new_button->text, (sfVector2f){pos.x + 50, pos.y + 30});
}

button_t *create_button(
    char *text, sfVector2f pos, button_t *head, sfVector2i action)
{
    button_t *new_button = malloc(sizeof(button_t));
    button_t *tmp = head;

    add_button_datas(new_button, pos, action.y, my_strlen(text));
    add_button_texts(new_button, pos, action.y, text);
    new_button->action = action.x;
    new_button->callback = button_actions;
    sfText_setPosition(new_button->text, (sfVector2f){pos.x + 50, pos.y + 30});
    if (head == NULL)
        return new_button;
    else {
        for (; tmp->next != NULL; tmp = tmp->next)
            ;
        tmp->next = new_button;
        return head;
    }
}
