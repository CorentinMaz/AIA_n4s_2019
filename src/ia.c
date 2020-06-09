/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** ia.c
*/

#include "my.h"

int check_end(char **tab, char *str)
{
    int nb_line = nb_lines_tab(str);

    if (my_strcmp("Track Cleared", tab[nb_line - 2]) == 0)
        return (1);
    return (0);
}

char **exec_command(char *str, char **lidar_tab)
{
    size_t size = 0;
    int get = 0;

    my_putstr(str);
    get = getline(&str, &size, stdin);
    if (get == -1)
        exit(0);
    lidar_tab = my_str_to_word_tab(str);
    if (check_end(lidar_tab, str) == 1)
        exec_command("stop_simulation\n", lidar_tab);
    return (lidar_tab);
}

int ia(void)
{
    char **lidar_tab = NULL;
    int tmp = 0;

    while (1) {
        lidar_tab = exec_command("get_info_lidar\n", lidar_tab);
        check_direction(lidar_tab);
        check_speed(lidar_tab);
    }
    return (0);
}