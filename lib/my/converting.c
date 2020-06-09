/*
** EPITECH PROJECT, 2019
** convertion
** File description:
** convertion
*/

#include "my.h"

int my_binary(va_list ap)
{
    int nb = va_arg(ap, int);
    int res = 0;
    int i = 1;

    while (nb != 0) {
        res = res + (nb % 2) * i;
        nb = nb / 2;
        i = i * 10;
    }
    my_put_nbr(res);
    return (nb);
}

int my_octal(va_list ap)
{
    int nb = va_arg(ap, int);
    int res = 0;
    int i = 1;

    while (nb != 0) {
        res = res + (nb % 8) * i;
        nb = nb / 8;
        i = i * 10;
    }
    my_put_nbr(res);
    return (nb);
}

int my_hexa(va_list ap)
{
    int nb = va_arg(ap, int);
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(int));

    while (nb != 0 || nb >= 16) {
        j = nb % 16;
        nb = nb / 16;
    if (j < 10)
        res[i] = j + 48;
    else
        res[i] = j + 87;
    i++;
    }
    my_putstr(my_revstr(res));
    return (0);
}

int my_hexa_capital(va_list ap)
{
    int nb = va_arg(ap, int);
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(int));

    while (nb != 0 || nb >= 16) {
        j = nb % 16;
        nb = nb / 16;
    if (j < 10)
        res[i] = j + 48;
    else
        res[i] = j + 55;
    i++;
    }
    my_putstr(my_revstr(res));
    return (0);
}

int no_printable(char const *std)
{
    int i = 0;

    while (std[i] != '\0') {
        if (std[i] < 32 || std[i] >= 127) {
            my_putchar('\\');
            (std[i] < 10) ? my_put_nbr(0) : 84;
            (std[i] < 100) ? my_put_nbr(0) : 84;
            my_put_nbr(std[i]);
        } else
            my_putchar(std[i]);
        i++;
    }
    return (0);
}