/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** ctrlc_client.c
*/

#include "server.h"

void free_one_client(t_client *client)
{
    if (client->team_use)
        free(client->team_use);
    if (client->channel_use)
        free(client->channel_use);
    if (client->thread_use)
        free(client->thread_use);
    if (client->associated_user)
        free(client->associated_user);
    free(client);
}

t_client *delete_client(t_client *client, int write_fd)
{
    t_client *tmp;
    t_client *before = client;

    if (!client)
        return NULL;
    if (before->fd_client == write_fd) {
        client = before->next;
        free_one_client(before);
        return client;
    }
    tmp = before->next;
    for (; tmp; tmp = tmp->next) {
        if (tmp->fd_client == write_fd) {
            before->next = tmp->next;
            free_one_client(tmp);
            return client;
        }
        before = tmp;
    }
    return client;
}

t_data *ctrlc_client(t_data *data, char **array, int write_fd)
{
    (void) array;

    if (user_associated_null(*data, write_fd) == false) {
        disconnect_user(data, write_fd);
    }
    data->client = delete_client(data->client, write_fd);
    return data;
}
