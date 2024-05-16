/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** calculate_dmg
*/

#include "my.h"
#include "structures.h"

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

static char *get_spell(int spell_id)
{
    int fd = open("spells.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    char **spells;

    if (fd == -1)
        return NULL;
    read(fd, buffer, 1000);
    spells = str_to_word_array(buffer, '\n');
    for (int i = 0; spells[i]; i++){
        if (atoi(spells[i]) == spell_id){
            return spells[i];
        }
    }
    return NULL;
}

static int dmg_strength(char *weapon,
    char *spell, character_t *player, int defense)
{
    int dmg = 0;

    dmg -= defense;
    weapon += my_strlen_until(weapon, ';') + 1;
    weapon += my_strlen_until(weapon, ';') + 1;
    spell += my_strlen_until(spell, ';') + 1;
    dmg = atoi(spell);
    spell += my_strlen_until(spell, ';') + 1;
    dmg += (atoi(spell) / 100) * player->strength;
    if (atoi(weapon) == '1'){
        weapon += my_strlen_until(weapon, ';') + 1;
        dmg += (atoi(weapon) / 100) * atoi(spell);
    }
    return dmg;
}

static int dmg_intelligence(char *weapon,
    char *spell, character_t *player, int defense)
{
    int dmg = 0;

    dmg -= defense;
    weapon += my_strlen_until(weapon, ';') + 1;
    weapon += my_strlen_until(weapon, ';') + 1;
    spell += my_strlen_until(spell, ';') + 1;
    dmg = atoi(spell);
    spell += my_strlen_until(spell, ';') + 1;
    dmg += (atoi(spell) / 100) * player->intelligence;
    if (atoi(weapon) == '2'){
        weapon += my_strlen_until(weapon, ';') + 1;
        dmg += (atoi(weapon) / 100) * atoi(spell);
    }
    return dmg;
}

static int dmg_agility(char *weapon,
    char *spell, character_t *player, int defense)
{
    int dmg = 0;

    dmg -= defense;
    weapon += my_strlen_until(weapon, ';') + 1;
    weapon += my_strlen_until(weapon, ';') + 1;
    spell += my_strlen_until(spell, ';') + 1;
    dmg = atoi(spell);
    spell += my_strlen_until(spell, ';') + 1;
    dmg += (atoi(spell) / 100) * player->agility;
    if (atoi(weapon) == '3'){
        weapon += my_strlen_until(weapon, ';') + 1;
        dmg += (atoi(weapon) / 100) * atoi(spell);
    }
    return dmg;
}

static int dmg_luck(char *weapon,
    char *spell, character_t *player, int defense)
{
    int dmg = 0;

    dmg -= defense;
    weapon += my_strlen_until(weapon, ';') + 1;
    weapon += my_strlen_until(weapon, ';') + 1;
    spell += my_strlen_until(spell, ';') + 1;
    dmg = atoi(spell);
    spell += my_strlen_until(spell, ';') + 1;
    dmg += (atoi(spell) / 100) * player->luck;
    if (atoi(weapon) == '4'){
        weapon += my_strlen_until(weapon, ';') + 1;
        dmg += (atoi(weapon) / 100) * atoi(spell);
    }
    return dmg;
}

int calculate_dmg(character_t *player, enemy_t *ennemy, int spell_id)
{
    char *weapon = read_item(player->weapon);
    char *spell = get_spell(spell_id);

    weapon += my_strlen_until(weapon, ';') + 1;
    weapon += my_strlen_until(weapon, ';') + 1;
    spell += my_strlen_until(spell, ';') + 1;
    spell += my_strlen_until(spell, ';') + 1;
    if (*spell == '1')
        return dmg_strength(weapon, spell, player, ennemy->defense);
    if (*spell == '2')
        return dmg_intelligence(weapon, spell, player, ennemy->defense);
    if (*spell == '3')
        return dmg_agility(weapon, spell, player, ennemy->defense);
    if (*spell == '4')
        return dmg_luck(weapon, spell, player, ennemy->defense);
    return 0;
}
