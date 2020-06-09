/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "my.h"

void specific(const char *std, int i)
{
    switch (std[i]) {
    case '%':
        my_putchar('%');
        break;
    }
}

void find_two(const char *std, int i, va_list ap)
{
    switch (std[i]) {
    case 'b':
        my_binary(ap);
        break;
    case 'x':
        my_hexa(ap);
        break;
    case 'X':
        my_hexa_capital(ap);
        break;
    case 'u':
        my_put_pos(va_arg(ap, int));
        break;
    case 'S':
        no_printable(va_arg(ap, char *));
        break;
    }
}

void find(const char *std, int i, va_list ap)
{
    switch (std[i]) {
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'c':
        my_putchar(va_arg(ap, int));
        break;
    case 'd':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'o':
        my_octal(ap);
        break;
        }
    specific(std, i);
    find_two(std, i, ap);
}

int my_printf(const char *std, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, std);
    while (std[i] != '\0') {
        if (std[i] == '%') {
            i++;
            find(std, i, ap);
        } else
            my_putchar(std[i]);
        if (std[i] == 0)
            return (84);
        i++;
    }
    va_end(ap);
    return (0);
}