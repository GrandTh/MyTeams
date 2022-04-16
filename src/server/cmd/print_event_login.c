/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_event_login.c
*/

#include "server.h"

void print_event_created(t_data data, int write_fd, char *uuid, char *name)
{
    t_client *tmp_client = data.client;

    dprintf(write_fd, "130 %s %s user created\r\n", uuid, name);
    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->associated_user != NULL)
            dprintf(tmp_client->fd_client, "130 %s %s user created\r\n",
            uuid, name);
}

void print_event_login(t_data data, char *uuid, char *name)
{
    t_client *print_client = data.client;

    for (; print_client; print_client = print_client->next)
        if (print_client->associated_user != NULL)
            dprintf(print_client->fd_client,
            "230 %s %s user connected\r\n", uuid, name);
    server_event_user_logged_in(uuid);
}
