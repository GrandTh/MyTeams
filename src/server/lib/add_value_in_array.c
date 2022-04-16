/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** add_value_in_array.c
*/

#include "server.h"

char **add_value_in_empty_array(char **tmp, char *str)
{
    tmp[0] = calloc(strlen(str) + 1, sizeof(char));
    for (int j = 0; str[j]; j++)
        tmp[0][j] = str[j];
    return tmp;
}

char **add_value_in_array(char **array, char *str)
{
    int i = 0;
    int size = count_lines(array);
    char **tmp = calloc(size + 2, sizeof(char *));

    if (!array)
        return add_value_in_empty_array(tmp, str);
    for (; array[i]; i++) {
        tmp[i] = calloc(strlen(array[i]) + 1, sizeof(char));
        for (int j = 0; array[i][j]; j++)
            tmp[i][j] = array[i][j];
    }
    tmp[i] = calloc(strlen(str) + 1, sizeof(char));
    for (int j = 0; str[j]; j++)
        tmp[i][j] = str[j];
    free_array(array);
    return tmp;
}
