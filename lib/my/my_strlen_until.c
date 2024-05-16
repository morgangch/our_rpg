/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strlen_until
*/

int my_strlen_until(char *str, char c)
{
    int i = 0;

    while (str[i] && str[i] != c)
        i++;
    return i;
}
