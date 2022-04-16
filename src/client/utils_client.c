/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** utils_client.c
*/

#include "client.h"

int count_line_client(char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return i;
}

int count_occurences_client(char *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == separator)
            count++;
    return count + 1;
}

char **str_to_array_client(char *line, char *separator)
{
    size_t size = count_occurences_client(line, separator[0]);
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

char *clean_str_client(char *cmd)
{
    char *str = calloc(strlen(cmd) + 1, sizeof(char));
    int i = 0;

    if (str == NULL)
        return NULL;
    else if (strlen(cmd) == 0)
        return str;
    for (; cmd[i] && cmd[i] != '\n' && cmd[i] != '\r'; i++)
        str[i] = cmd[i];
    return str;
}
