/*
** EPITECH PROJECT, 2023
** day03 - my_isneg
** File description:
** Func to display if N is negative or positive*
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0){
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
