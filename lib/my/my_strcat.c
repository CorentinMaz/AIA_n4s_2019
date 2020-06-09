/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;
    int i = 0;
    char *tmp = NULL;

    tmp = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
    while (dest[a] != '\0') {
        tmp[i] = dest[a];
        i++;
        a++;
    }
    while (src[b] != '\0') {
        tmp[i] = src[b];
        b++;
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}
