/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** calculate_dmg_teken
*/

#include "my.h"

static char *read_item(int item_id)
{
    int fd = open("items.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    char **items;

    if (fd == -1)
        return NULL;
    read(fd, buffer, 1000);
    items = str_to_word_array(buffer, '\n');
    for (int i = 0; items[i]; i++){
        if (atoi(items[i]) == item_id){
            return items[i];
        }
    }
    return NULL;
}

int calculate_dmg_teken(character_t *player, enemy_t *enemy)
{
    char *armor = read_item(player->armor);
    char *weapon = read_item(player->weapon);
    int dmg = enemy->attack;
    int crit = rand() % 100 - player->luck;

    weapon += my_strlen_until(weapon, ';') + 1;
    weapon += my_strlen_until(weapon, ';') + 1;
    if (*weapon == '4'){
        weapon += my_strlen_until(weapon, ';') + 1;
        crit -= atoi(weapon);
    }
    for (int i = 0; i < 2; i++)
        armor += my_strlen_until(armor, ';') + 1;
    if (crit > 70)
        dmg *= 2;
    dmg -= player->strength;
    dmg -= atoi(armor);
    if (dmg < 0)
        dmg = 0;
    return dmg;
}
