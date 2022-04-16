/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** close_end.c
*/

#include "server.h"

void close_all(t_data data, t_server serv, fd_set *read_fd_set)
{
    for (; data.client; data.client = data.client->next) {
        if (FD_ISSET(data.client->fd_client, read_fd_set)) {
            dprintf(data.client->fd_client, "221 Good Bye.\r\n");
            close(data.client->fd_client);
        }
    }
    close(serv.socket_server);
}
