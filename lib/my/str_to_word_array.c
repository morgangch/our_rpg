/*
** EPITECH PROJECT, 2024
** sokoban
** File description:
** str_to_word_array
*/

#include "my.h"

char **str_to_word_array(char *str, char delimiter)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **array;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == delimiter)
            j++;
    array = malloc(sizeof(char *) * (j + 2));
    for (i = 0; i < j + 1; i++) {
        for (k = 0; str[k] != '\0' && str[k] != delimiter; k++);
        array[i] = malloc(sizeof(char) * (k + 1));
        for (k = 0; str[k] != '\0' && str[k] != delimiter; k++)
            array[i][k] = str[k];
        array[i][k] = '\0';
        str += k + 1;
    }
    array[i] = NULL;
    return array;
}
