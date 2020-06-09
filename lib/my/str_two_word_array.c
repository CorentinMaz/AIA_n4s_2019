/*
** EPITECH PROJECT, 2019
** str_two_word_array
** File description:
** str_two_word_array.c
*/

#include "my.h"

int nb_lines(char const *str)
{
    int i = 0;
    int line = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            line++;
        i++;
    }
    return (line);
}

int nb_char(char const *str, int i)
{
    int c = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            return (c);
        c++;
        i++;
    }
    return (c);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int lines = nb_lines(str);
    char **array = malloc(sizeof(char *) * (lines + 1));

    while (i < lines) {
        array[i] = malloc(sizeof(char) * nb_char(str, k) + 1);
        j = 0;
        while (str[k] != '\n') {
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