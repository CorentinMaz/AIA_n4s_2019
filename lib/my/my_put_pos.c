/*
** EPITECH PROJECT, 2019
** my_put_pos
** File description:
** displays the number given as a parameter
*/

#include "my.h"

int my_put_pos(int nbr)
{
    unsigned int nb_long = nbr;
    int nbr2;

    if (nb_long <= 0) {
        my_putchar('-');
        nb_long = nb_long * (-1);
    } if (nb_long >= 10) {
        nbr2 = nb_long % 10;
        nb_long = nb_long / 10;
        my_put_pos(nb_long);
        my_putchar(nbr2 + 48);
    } else
        my_putchar((nb_long % 10) + 48);
    return (0);
}
