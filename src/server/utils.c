/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** utils.c
*/

#include "server.h"

t_client *add_front_list(t_client *clients, int n)
{
    t_client *nclient = calloc(1, sizeof(t_client));

    nclient->associated_user = NULL;
    nclient->team_use = NULL;
    nclient->channel_use = NULL;
    nclient->thread_use = NULL;
    nclient->fd_client = n;
    nclient->use = 0;
    nclient->next = clients;
    return nclient;
}

int count_lines(char **array)
{
    int i = 0;

    if (!array)
        return 0;
    while (array[i])
        i++;
    return i;
}

int count_char(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i])
        i++;
    return i;
}

char *clean_username(char *username)
{
    char *tmp = calloc(strlen(username) + 1, sizeof(char));
    int j = 0;

    for (size_t i = 0; i < strlen(username); i++) {
        if (username[i] != '"')
            tmp[j++] = username[i];
    }
    return tmp;
}

int my_exit_failure(char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}
