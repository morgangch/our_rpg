/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** tests and bootstrap for myhunter
*/

#include "my.h"
#include "structures.h"

int main(int ac, char **av)
{
    config_t *config;

    if (ac == 2 && (my_strcmp(av[1], "-h") == 0))
        return my_printf("USAGE\n\t./my_rpg\n\nDESCRIPTION\n\t\
    My RPG project prototype...\n\t\
    For now it should include a working menu.\n");
    config = create_config();
    setup_game(config);
    if (!(config->window))
        return 1;
    to_m_menu(config);
    destroy_config(config);
    return 0;
}

void map_debug(map_t *map)
{
    my_putstr("Map name: ");
    for (int j = 0; map->map_layers->map_collisions[j]; j++) {
        for (int i = 0; map->map_layers->map_collisions[j][i]; i++) {
            fprintf(stderr, "%d", map->map_layers->map_collisions[j][i]);
        }
        fprintf(stderr, "\n");
    }
}

void debug(config_t *config)
{
    map_debug(config->active_map);
    fprintf(stderr, "Player pos: %f %f\n", config->player->sprite->pos.x,
        config->player->sprite->pos.y);
    fprintf(stderr, "Player direction: %d\n", config->player->direction);
    fprintf(stderr, "Player life: %d\n", config->game->life);
    fprintf(stderr, "Player score: %ld\n", config->game->score);
    fprintf(stderr, "Player is_menu: %d\n", config->is_menu);
    fprintf(stderr, "Player speed: %d\n", config->player->speed);
}
