/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Buttons handling
*/

#include "my.h"

static void finish_button(button_t *button)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    sfColor color = sfColor_fromRGB(195, 162, 107);

    button->font = font;
    sfText_setFont(button->text, font);
    sfText_setCharacterSize(button->text, 20);
    sfText_setFillColor(button->text, color);
    button->isMouseOver = sfFalse;
}

void initialize_button(button_t *button, const char *buttonText,
    sfVector2f position, sfVector2f size)
{
    button->shape = sfRectangleShape_create();
    button->text = sfText_create();
    button->defaultColor = sfColor_fromRGB(34, 94, 156);
    button->hoverColor = sfWhite;
    button->currentColor = button->defaultColor;
    button->position = position;
    button->size = size;
    sfRectangleShape_setPosition(button->shape, position);
    sfRectangleShape_setSize(button->shape, size);
    sfRectangleShape_setFillColor(button->shape, button->currentColor);
    sfText_setString(button->text, buttonText);
    sfText_setPosition(
        button->text, (sfVector2f){position.x + 10, position.y + 10});
    finish_button(button);
}

static button_t *create_button(const char *buttonText, int order)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f size = {150, 70};
    sfVector2f position = {sfVideoMode_getDesktopMode().width / 2 - size.x,
        (sfVideoMode_getDesktopMode().height / 2 - size.y + (order * 100))};

    initialize_button(button, buttonText,
        adapt_position(position, sfVideoMode_getDesktopMode()),
        adapt_position(size, sfVideoMode_getDesktopMode()));
    return button;
}

buttons_t *create_buttons(sfVideoMode mode, int pause)
{
    buttons_t *buttons = malloc(sizeof(buttons_t));

    if (pause == 1) {
        buttons->resume_button = create_button("Resume", 0);
        buttons->load_button = create_button("Load", 1);
        buttons->save_button = create_button("Save", 2);
        buttons->settings_button = create_button("Settings", 3);
        buttons->quit_button = create_button("Quit", 4);
        buttons->new_button = NULL;
        buttons->cheat_button = NULL;
    } else {
        buttons->resume_button = create_button("Continue", 0);
        buttons->load_button = create_button("Load", 1);
        buttons->new_button = create_button("New Game", 2);
        buttons->settings_button = create_button("Settings", 3);
        buttons->cheat_button = create_button("Cheat", 4);
        buttons->quit_button = create_button("Quit", 5);
        buttons->save_button = NULL;
    }
    return buttons;
}
