/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** replace_char_in_str.c
*/

#include "client.h"

char *replace_char_in_str(char *str, char current, char replace)
{
    char *tmp = calloc(strlen(str) + 1, sizeof(char));

    for (int i = 0; str[i]; i++) {
        if (str[i] == current)
            tmp[i] = replace;
        else
            tmp[i] = str[i];
    }
    return tmp;
}
