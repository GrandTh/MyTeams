/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** str_to_array.c
*/

#include "server.h"

int count_occurences(char *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == separator)
            count++;
    return count + 1;
}

char **str_to_array(char *line, char *separator)
{
    size_t size = count_occurences(line, separator[0]);
    char **array = calloc(size + 1, sizeof(char *));
    char *str = strtok(line, separator);

    for (size_t i = 0; str && i < size; i++) {
        array[i] = calloc(strlen(str) + 1, sizeof(char));
        for (size_t j = 0; j < strlen(str); j++)
            array[i][j] = str[j];
        str = strtok(NULL, separator);
    }
    return array;
}
