/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Buttons handling
*/

#include "my.h"

static button_t *create_m_button(sfVideoMode mode, button_t *button)
{
    button = create_button("New Game",
        adapt_position(
            (sfVector2f){mode.width / 2 - 75, mode.height / 2 - 200}, mode),
        button, (sfVector2i){1, 0});
    button = create_button("Load",
        adapt_position(
            (sfVector2f){mode.width / 2 - 75, mode.height / 2 - 100}, mode),
        button, (sfVector2i){2, 0});
    button = create_button("Settings",
        adapt_position(
            (sfVector2f){mode.width / 2 - 75, mode.height / 2}, mode),
        button, (sfVector2i){4, 0});
    button = create_button("Quit",
        adapt_position(
            (sfVector2f){mode.width / 2 - 75, mode.height / 2 + 100}, mode),
        button, (sfVector2i){5, 0});
    return button;
}

static button_t *create_p_button(sfVideoMode mode, button_t *button)
{
    button = create_button("Resume",
        adapt_position(
            (sfVector2f){mode.width / 2 - 75,
            mode.height / 2 - 200}, mode), button, (sfVector2i){1, 0});
    button = create_button("Load",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 - 100}, mode), button, (sfVector2i){2, 0});
    button = create_button("Save",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2}, mode), button, (sfVector2i){3, 0});
    button = create_button("Settings",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 + 100}, mode),
        button, (sfVector2i){4, 0});
    button = create_button("Quit",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 + 200}, mode), button, (sfVector2i){5, 0});
    return button;
}

static button_t *create_s_button(sfVideoMode mode, button_t *button)
{
    button = create_button("Resolution 1920x1080",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 - 100}, mode), button, (sfVector2i){7, 0});
    button = create_button("Resolution 2256x1504",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 - 0}, mode), button, (sfVector2i){8, 0});
    button = create_button("Back",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 + 100}, mode), button, (sfVector2i){9, 0});
    return button;
}

static button_t *create_f_button(sfVideoMode mode, button_t *button)
{
    button = create_button("Physical Attack",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 - 100}, mode), button, (sfVector2i){1, 0});
    button = create_button("Magic Attack",
        adapt_position((sfVector2f){mode.width / 2 - 75,
        mode.height / 2 - 0}, mode), button, (sfVector2i){2, 0});
    return button;
}

button_t *create_buttons(sfVideoMode mode, int pause)
{
    button_t *button = NULL;

    if (pause == 0)
        button = create_m_button(mode, button);
    if (pause == 1)
        button = create_p_button(mode, button);
    if (pause == 2)
        button = create_s_button(mode, button);
    if (pause == 3)
        button = create_f_button(mode, button);
    return button;
}
