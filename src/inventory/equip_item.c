/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** equip_item
*/

#include "my.h"

char *read_item(int item_id)
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
            close(fd);
            return items[i];
        }
    }
    close(fd);
    return NULL;
}

void equip_item(character_t *player, int item_id)
{
    char *item = read_item(item_id);

    if (item == NULL)
        return;
    item += my_strlen_until(item, ';') + 1;
    item += my_strlen_until(item, ';') + 1;
    if (atoi(item) == 5){
        if (player->armor != 0)
            add_item_to_inventory(player, player->armor);
        player->armor = item_id;
    } else {
        if (player->weapon != 0)
            add_item_to_inventory(player, player->weapon);
        player->weapon = item_id;
    }
    remove_item_from_inventory(player, item_id);
}

void unequip_item(character_t *player, int type)
{
    printf("Unequiping %s\n", type == 1 ? "armor" : "weapon");
    if (type == 1) {
        add_item_to_inventory(player, player->armor);
        player->armor = 0;
    } else {
        add_item_to_inventory(player, player->weapon);
        player->weapon = 0;
    }
}
