/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** user_associated_exists.c
*/

#include "server.h"

bool user_associated_null(t_data data, int write_fd)
{
    t_client *tmp_client = data.client;

    for (;tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd &&
        tmp_client->associated_user == NULL)
            return true;
    return false;
}
