/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** check_speed.c
*/

#include "my.h"

int check_speed_next_two(char **tab)
{
    int mid = my_getnbr(tab[15]);

    if (mid >= 600)
        exec_command("CAR_FORWARD:0.3\n", tab);
    else if (mid >= 400)
        exec_command("CAR_FORWARD:0.2\n", tab);
    else
        exec_command("CAR_FORWARD:0.1\n", tab);
    return (0);
}

int check_speed_next(char **tab)
{
    int mid = my_getnbr(tab[15]);

    if (mid >= 1000)
        exec_command("CAR_FORWARD:0.5\n", tab);
    else if (mid >= 800)
        exec_command("CAR_FORWARD:0.4\n", tab);
    else
        check_speed_next_two(tab);
    return (0);
}

int check_speed(char **tab)
{
    int mid = my_getnbr(tab[15]);

    if (mid >= 2000)
        exec_command("CAR_FORWARD:1.0\n", tab);
    else if (mid >= 1500)
        exec_command("CAR_FORWARD:0.65\n", tab);
    else
        check_speed_next(tab);
    return (0);
}