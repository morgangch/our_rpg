/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

void quest_init(config_t *config)
{
    sfVector2f pos =
        (sfVector2f){config->mode.width / 2 - 250, config->mode.height - 200};

    config->player->character->quests = malloc(sizeof(sprite_t *) * 3);
    config->player->character->quests[0] = create_sprite("assets/quest1.png",
        (sfIntRect){0, 0, 417, 200}, (offset_maxvalue_t){0, 0}, pos);
    config->player->character->quests[1] = create_sprite("assets/quest2.png",
        (sfIntRect){0, 0, 417, 200}, (offset_maxvalue_t){0, 0}, pos);
    config->player->character->quests[2] = NULL;
}

void analyse_quests(config_t *config)
{
    int quest_id = config->player->character->quest_id;

    if (quest_id == 1) {
        if (config->player->character->armor != 0
            && config->player->character->weapon != 0)
            config->player->character->quest_id = 2;
    }
}
