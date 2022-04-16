/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** clean_str.c
*/

#include "server.h"

char *clean_str(char *cmd)
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
