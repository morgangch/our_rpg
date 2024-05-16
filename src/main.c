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
    return 0;
}
