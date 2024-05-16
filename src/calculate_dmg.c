/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** calculate_dmg
*/

#include "my.h"
#include "structures.h"

static char **read_items(void)
{
    int fd = open("items.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    char **items;

    if (fd == -1)
        return NULL;
    read(fd, buffer, 1000);
    items = str_to_word_array(buffer, '\n');
    return items;
}

int calculate_dmg(character_t *player, enemy_t *ennemy)
{
    char **get_items = read_items();

    for (int i = 0; get_items[i]; i++){
        printf("%s\n", get_items[i]);
    }
    return 0;
}
