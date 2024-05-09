/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** check_collisions
*/

#include "my.h"
#include "structures.h"

int check_collision1(config_t *config)
{
    if ((config->event->mouseButton.x >= config->enemies->enemy1->pos.x - 180
        && config->event->mouseButton.x <= config->enemies->enemy1->pos.x + 210
        && config->event->mouseButton.y >= config->enemies->enemy1->pos.y &&
        config->event->mouseButton.y <= config->enemies->enemy1->pos.y + 100))
        return 1;
    return 0;
}

int check_collision2(config_t *config)
{
    if ((config->event->mouseButton.x >= config->enemies->enemy2->pos.x - 180
        && config->event->mouseButton.x <= config->enemies->enemy2->pos.x
        + 210 && config->event->mouseButton.y >= config->enemies->enemy2->pos.y
        && config->event->mouseButton.y <=
        config->enemies->enemy2->pos.y + 100))
        return 1;
    return 0;
}

int check_collision3(config_t *config)
{
    if ((config->event->mouseButton.x >= config->enemies->enemy3->pos.x - 180
        && config->event->mouseButton.x <= config->enemies->enemy3->pos.x + 210
        && config->event->mouseButton.y >= config->enemies->enemy3->pos.y
        && config->event->mouseButton.y <=
        config->enemies->enemy3->pos.y + 100))
        return 1;
    return 0;
}

static int check_collision4(config_t *config)
{
    if ((config->event->mouseButton.x >= config->enemies->enemy4->pos.x - 180
        && config->event->mouseButton.x <= config->enemies->enemy4->pos.x + 210
        && config->event->mouseButton.y >= config->enemies->enemy4->pos.y &&
        config->event->mouseButton.y <= config->enemies->enemy4->pos.y + 100))
        return 1;
    return 0;
}

static int check_collision5(config_t *config)
{
    if ((config->event->mouseButton.x >= config->enemies->enemy5->pos.x - 50
        && config->event->mouseButton.x <= config->enemies->enemy5->pos.x +
        370 && config->event->mouseButton.y >= config->enemies->enemy5->pos.y
        && config->event->mouseButton.y <=
        config->enemies->enemy5->pos.y + 130))
        return 1;
    return 0;
}

static int check_collisions2(config_t *config)
{
    if (check_collision3(config) == 1) {
        config->enemies->enemy3->pos.x = 0 - (rand() % 200);
        config->enemies->enemy3->pos.y = 700 + rand() % 150;
        return 3;
    }
    if (check_collision4(config) == 1) {
        config->enemies->enemy4->pos.x = 0 - (rand() % 200);
        config->enemies->enemy4->pos.y = 700 + rand() % 150;
        return 4;
    }
    if (check_collision5(config) == 1) {
        config->enemies->enemy5->pos.x = 0 - (rand() % 200);
        config->enemies->enemy5->pos.y = 700 + rand() % 150;
        return 5;
    }
    return 0;
}

int check_collision(config_t *config)
{
    if (check_collision1(config) == 1) {
        config->enemies->enemy1->pos.x = 0 - (rand() % 200);
        config->enemies->enemy1->pos.y = 700 + rand() % 150;
        return 1;
    }
    if (check_collision2(config) == 1) {
        config->enemies->enemy2->pos.x = 0 - (rand() % 200);
        config->enemies->enemy2->pos.y = 700 + rand() % 150;
        return 2;
    }
    return check_collisions2(config);
}
