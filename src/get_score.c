/*
** EPITECH PROJECT, 2023
** fs_cat_500_byte
** File description:
** Read the first 500 bytes of a file.
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> // Add missing import
#include <stdlib.h> // Add missing import
#include "my.h"

unsigned long int get_score(void)
{
    int size = 500;
    char buff[size];
    int fd = 0;
    unsigned long int res = 0;
    char *filepath = "assets/score.txt";
    ssize_t bytesRead;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return 0;
    bytesRead = read(fd, buff, size);
    if (bytesRead == -1) {
        return 0;
    }
    close(fd);
    buff[bytesRead] = '\0';
    res = my_getnbr(buff);
    printf("Highest score: %lu\n", res);
    return res;
}

static char *my_itoa2(int i, char *str)
{
    int j = i - 1;
    char temp;

    i = 0;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

char *my_itoa(unsigned long int nb)
{
    unsigned long int temp = nb;
    int cpt = 0;
    char *str;
    int i = 0;

    while (temp > 0) {
        temp /= 10;
        cpt++;
    }
    str = (char *)malloc((cpt + 1) * sizeof(char));
    if (str == NULL)
        return "0";
    for (; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    return my_itoa2(i, str);
}

void write_score(unsigned long int score)
{
    int fd = 0;
    char *str = my_itoa(score);
    char *filepath = "assets/score.txt";

    if (score > get_score()) {
        fd = open(filepath, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
        if (fd == -1) {
            free(str);
            return;
        }
        write(fd, str, my_strlen(str));
        close(fd);
    }
    free(str);
    return;
}
