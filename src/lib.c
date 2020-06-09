/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** lib.c
*/

#include "my.h"

int nb_char_tab(char const *str, int i)
{
    int c = 0;

    while (str[i] != '\0') {
        if (str[i] == ':')
            return (c);
        c++;
        i++;
    }
    return (c);
}

int nb_lines_tab(char const *str)
{
    int i = 0;
    int line = 0;

    while (str[i] != '\0') {
        if (str[i] == ':')
            line++;
        i++;
    }
    return (line + 1);
}

char **my_str_to_word_tab(char const *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int lines = nb_lines_tab(str);
    char **array = malloc(sizeof(char *) * (lines + 1));

    while (i < lines) {
        j = 0;
        array[i] = malloc(sizeof(char) * (nb_char_tab(str, k) + 1));
        while (str[k] != '\0' && str[k] != ':') {
            array[i][j] = str[k];
            j++;
            k++;
        }
        array[i][j] = '\0';
        i++;
        k++;
    }
    array[i] = NULL;
    return (array);
}