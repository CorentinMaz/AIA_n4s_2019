/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** get_info_lidar.c
*/

#include "my.h"

int moove_car(char *str, int direction, char **tab)
{
    char *tmp = NULL;

    if (direction < 0)
        tmp = my_strcat("WHEELS_DIR:-", str);
    else
        tmp = my_strcat("WHEELS_DIR:", str);
    exec_command(tmp, tab);
    return (0);
}

int check_dir_two(char **tab, int left, int right)
{
    int mid = my_getnbr(tab[15]);

    if (mid >= 200)
        moove_car("0.3\n", (left - right), tab);
    else
        moove_car("0.5\n", (left - right), tab);
    return (0);
}

int check_dir(char **tab, int left, int right)
{
    int mid = my_getnbr(tab[15]);

    if (mid >= 800)
        moove_car("0.1\n", (left - right), tab);
    else if (mid >= 400)
        moove_car("0.2\n", (left - right), tab);
    else
        check_dir_two(tab, left, right);
    return (0);
}

int check_direction(char **tab)
{
    int mid = my_getnbr(tab[15]);
    int left = my_getnbr(tab[1]);
    int right = my_getnbr(tab[31]);

    if (mid >= 1500)
        moove_car("0.05\n", (left - right), tab);
    else if (mid >= 1000)
        moove_car("0.08\n", (left - right), tab);
    else
        check_dir(tab, left, right);
    return (0);
}