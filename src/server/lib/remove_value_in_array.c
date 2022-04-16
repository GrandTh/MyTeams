/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** remove_value_in_array.c
*/

#include "server.h"

char **remove_value_in_array(char **array, char *str)
{
    int i = 0;
    int tmp = 0;

    for (; array[i]; i++) {
        if (strcmp(array[i], str) == 0) {
            array[i] = array[i + 1];
            tmp = 1;
        }
        if (tmp == 1)
            array[i] = array[i + 1];
    }
    return array;
}
