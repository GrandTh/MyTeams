/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** get_next_line.c
*/

#include "server.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (; str[i]; i++);
    return i;
}

char *add_char_to_str(char *str, char c)
{
    int i = 0;
    char *buff = calloc((my_strlen(str) + 2), sizeof(char));

    if (!str) {
        if (c != '\n')
            buff[i++] = c;
    } else {
        for (i = 0; str[i]; i++)
            buff[i] = str[i];
        buff[i++] = c;
    }
    if (str)
        free(str);
    return buff;
}

char *get_next_line(const int fd)
{
    char *buffer;
    char buff = 0;
    int fs = 0;

    buffer = NULL;
    while ((fs = read(fd, &buff, 1)) > 0) {
        if (buff == '\n')
            break;
        buffer = add_char_to_str(buffer, buff);
    }
    if (fs == 0 || fs == -1) {
        return NULL;
    }
    return ((buffer != NULL) ? buffer : "");
}
