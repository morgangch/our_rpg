/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** save
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *get_stats(character_t *character)
{
    int *stats = malloc(sizeof(int) * 15);

    stats[0] = character->level;
    stats[1] = character->strength;
    stats[2] = character->intelligence;
    stats[3] = character->agility;
    stats[4] = character->luck;
    stats[5] = character->current_hp;
    stats[6] = character->max_hp;
    stats[7] = character->current_mp;
    stats[8] = character->max_mp;
    stats[9] = character->xp;
    stats[10] = character->xp_max;
    stats[11] = character->gold;
    stats[12] = character->armor;
    stats[13] = character->weapon;
    return stats;
}

void save_player(player_t *player)
{
    FILE *fp = fopen("save.txt", "w");
    int *stats = get_stats(player->character);
    int name_length = strlen(player->character->name) + 1;

    fwrite(&player->pos, sizeof(player->pos), 1, fp);
    fwrite(&player->direction, sizeof(player->direction), 1, fp);
    fwrite(&player->speed, sizeof(player->speed), 1, fp);
    fwrite(&player->is_moving, sizeof(player->is_moving), 1, fp);
    fwrite(&player->map, sizeof(player->map), 1, fp);
    fwrite(stats, sizeof(int), 14, fp);
    fwrite(&name_length, sizeof(name_length), 1, fp);
    fwrite(player->character->name, sizeof(char), name_length, fp);
    fclose(fp);
}

static character_t *load_character(int *stats)
{
    character_t *character = malloc(sizeof(character_t));

    character->level = stats[0];
    character->strength = stats[1];
    character->intelligence = stats[2];
    character->agility = stats[3];
    character->luck = stats[4];
    character->current_hp = stats[5];
    character->max_hp = stats[6];
    character->current_mp = stats[7];
    character->max_mp = stats[8];
    character->xp = stats[9];
    character->xp_max = stats[10];
    character->gold = stats[11];
    character->armor = stats[12];
    character->weapon = stats[13];
    return character;
}

static player_t *create_player_stat(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->sprite = create_sprite("assets/sprites/Martin.png",
        (sfIntRect){0, 0, 128, 128}, (offset_maxvalue_t){128, 128},
        (sfVector2f){0, 0});
    sfSprite_setScale(player->sprite->sprite, (sfVector2f){0.5, 0.5});
    return player;
}

player_t *load_player(void)
{
    player_t *player = create_player_stat();
    FILE *fp = fopen("save.txt", "r");
    int *stats = malloc(sizeof(int) * 15);
    int name_length;

    fread(&player->pos, sizeof(player->pos), 1, fp);
    fread(&player->direction, sizeof(player->direction), 1, fp);
    fread(&player->speed, sizeof(player->speed), 1, fp);
    fread(&player->is_moving, sizeof(player->is_moving), 1, fp);
    fread(&player->map, sizeof(player->map), 1, fp);
    fread(stats, sizeof(int), 14, fp);
    player->character = load_character(stats);
    fread(&name_length, sizeof(name_length), 1, fp);
    player->character->name = malloc(sizeof(char) * name_length);
    fread(player->character->name, sizeof(char), name_length, fp);
    fclose(fp);
    return player;
}

void load_handler(config_t *config)
{
    config->player = load_player();
    to_game(config);
}

void save_handler(config_t *config)
{
    save_player(config->player);
    printf("Game saved\n");
    close_window(config);
}
