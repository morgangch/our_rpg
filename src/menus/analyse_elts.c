/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** analyse_event.c
*/

#include "../../includes/my.h"
#include "../../includes/structures.h"

int check_collision(int x, int y, sfRectangleShape *rect)
{
    if (x < sfRectangleShape_getGlobalBounds(rect).left
        || x > sfRectangleShape_getGlobalBounds(rect).left
                + sfRectangleShape_getGlobalBounds(rect).width
        || y < sfRectangleShape_getGlobalBounds(rect).top
        || y > sfRectangleShape_getGlobalBounds(rect).top
                + sfRectangleShape_getGlobalBounds(rect).height)
        return 0;
    return 1;
}

static int handle_mouse_move(sfEvent event, button_t *tmp)
{
    if (event.type == sfEvtMouseMoved
        && check_collision(event.mouseMove.x, event.mouseMove.y, tmp->rect)
            == 1)
        sfRectangleShape_setFillColor(tmp->rect, tmp->col_hover);
    else if (check_collision(event.mouseButton.x, event.mouseButton.y,
        tmp->rect) == 0) {
        sfRectangleShape_setFillColor(tmp->rect, tmp->col_normal);
        return 1;
    }
    return 0;
}

void analyse_buttons(sfEvent event, config_t *config, button_t *tmp)
{
    for (; tmp != NULL && tmp->rect != NULL; tmp = tmp->next) {
        if (handle_mouse_move(event, tmp) == 1)
            continue;
        if (event.type == sfEvtMouseButtonPressed
            && event.mouseButton.button == sfMouseLeft) {
            sfRectangleShape_setFillColor(tmp->rect, tmp->col_pressed);
            tmp->callback(config, tmp->action);
        }
        if (event.type == sfEvtMouseButtonReleased
            && event.mouseButton.button == sfMouseLeft)
            sfRectangleShape_setFillColor(tmp->rect, tmp->col_normal);
    }
}
