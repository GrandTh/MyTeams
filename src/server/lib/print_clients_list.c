/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_clients_list.c
*/

#include "server.h"

void print_clients_list(t_client *clients)
{
    if (!clients)
        return;
    for (int i = 0; clients; clients = clients->next, i++) {
        printf("clients %d\n", i);
        printf("fd:%d\n", clients->fd_client);
        printf("user:%s\n", clients->associated_user);
        printf("use:%d\n", clients->use);
        printf("team_use:%s\n", clients->team_use);
        printf("channel_use:%s\n", clients->channel_use);
        printf("thread_use:%s\n", clients->thread_use);
    }
}
