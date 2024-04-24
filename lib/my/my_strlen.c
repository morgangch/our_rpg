/*
** EPITECH PROJECT, 2023
** day04 - my_strlen
** File description:
** Func to display the count of characters of a string
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        cpt++;
    }
    return cpt;
}
