/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** analysefuncs
*/

#include "my.h"
#include "structures.h"

sprite_t *create_dialog(config_t *config, char *dialog)
{
    sfVector2f pos =
        (sfVector2f){config->mode.width / 2 - 250, config->mode.height - 200};
    sprite_t *dialog_sprite = create_sprite(
        dialog, (sfIntRect){0, 0, 417, 200}, (offset_maxvalue_t){0, 0}, pos);

    sfSprite_setScale(dialog_sprite->sprite, (sfVector2f){1, 1});
    sfRenderWindow_drawSprite(config->window, dialog_sprite->sprite, NULL);
    return dialog_sprite;
}

char **read_dialogs(int pnj_id)
{
    int fd = open("dialogs.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    char **dialogs;

    if (fd == -1)
        return NULL;
    read(fd, buffer, 1000);
    dialogs = str_to_word_array(buffer, '\n');
    for (int i = 0; dialogs[i]; i++) {
        if (atoi(dialogs[i]) == pnj_id) {
            close(fd);
            return str_to_word_array(dialogs[i], ';');
        }
    }
    close(fd);
    return NULL;
}

void dialog_loop(config_t *config, sprite_t *dialog_sprite)
{
    analyse_events(config, 5);
    sfRenderWindow_drawSprite(config->window, dialog_sprite->sprite, NULL);
    sfRenderWindow_display(config->window);
}

int dialog_handling(config_t *config, int pnj_id, int line)
{
    char *dialog = NULL;
    char **dialogs = NULL;
    sprite_t *dialog_sprite = NULL;

    if (pnj_id > 0 && config->player->character->quest_id != 1) {
        dialogs = read_dialogs(pnj_id);
        config->is_menu = 5;
        dialog = my_strdup(dialogs[line + 1]);
        dialog_sprite = create_dialog(config, dialog);
        free(dialog);
        free(dialogs);
    }
    while (config->is_menu == 5 && dialog_sprite != NULL)
        dialog_loop(config, dialog_sprite);
    if (dialog_sprite != NULL)
        sfSprite_destroy(dialog_sprite->sprite);
    if (pnj_id == 1 && config->player->character->quest_id == 0)
        config->player->character->quest_id = 1;
    return 0;
}

void analyse_d_menu(config_t *config)
{
    if ((config)->event->type == sfEvtClosed)
        close_window(config);
    if ((config)->event->type == sfEvtMouseButtonPressed
        || (config)->event->type == sfEvtKeyPressed) {
        config->is_menu = 0;
        return;
    }
}
