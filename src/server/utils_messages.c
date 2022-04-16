/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** utils_messages.c
*/

#include "server.h"

int fd_client_receive(t_data data, char *uuid)
{
    t_client *tmp = data.client;
    int fd_receive = 0;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->associated_user
            && strcmp(clean_username(uuid), tmp->associated_user) == 0)
            fd_receive = tmp->fd_client;
    return fd_receive;
}

char *get_sender(t_data data, int write_fd)
{
    t_client *tmp_client = data.client;
    char *uuid = NULL;

    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd)
            uuid = strdup(tmp_client->associated_user);
    return uuid;
}
