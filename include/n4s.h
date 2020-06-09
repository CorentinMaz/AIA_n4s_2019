/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all prototypes
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

// check_speed.c
int check_speed(char **tab);
int check_speed_next(char **tab);

// get_info_lidar.c
int check_direction(char **tab);
int moove_car(char *str, int direction, char **tab);

// ia.c
int check_end(char **tab, char *str);
int ia(void);
char **exec_command(char *str, char **lidar_tab);

// lib.c
char **my_str_to_word_tab(char const *str);
int nb_lines_tab(char const *str);
int nb_char_tab(char const *str, int i);