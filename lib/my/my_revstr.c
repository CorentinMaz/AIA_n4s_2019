/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** function that reverses a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int len = (my_strlen(str) - 1);
    int lenght = len;
    char cpy = 0;

    while (i < lenght / 2 + 1) {
        cpy = str[len];
        str[len] = str[i];
        str[i] = cpy;
        i++;
        len--;
    }
    return (str);
}