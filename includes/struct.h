/*
** EPITECH PROJECT, 2024
** B-MUL : my_rpg
** File description:
** struct.h of my_rpg project
*/

#pragma once

#include "my.h"

// Structure de la fenêtre
typedef struct main_window_s {
    sfRenderWindow *window;
    sfEvent event;
} main_window_t;
