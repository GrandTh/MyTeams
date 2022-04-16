/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** logout.c
*/

#include "server.h"

t_data *logout_user(t_data *data, char **array, int write_fd)
{
    if (count_lines(array) == 1) {
        if (user_associated_null(*data, write_fd) == true) {
            dprintf(write_fd, "420 Use /login before\r\n");
            return data;
        }
        else if (user_associated_null(*data, write_fd) == false) {
            disconnect_user(data, write_fd);
        }
    }
    else
        dprintf(write_fd, "510 Bads arguments\r\n");
    return data;
}

t_data *disconnect_user(t_data *data, int write_fd)
{
    t_user *tmp_user = data->user;
    t_client *tmp_client = data->client;
    char *username = NULL;
    char *name_to_send = NULL;

    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd &&
        tmp_client->associated_user != NULL) {
            username = strdup(tmp_client->associated_user);
            tmp_client->associated_user = NULL;
        }
    for (; tmp_user; tmp_user = tmp_user->next)
        if (strcmp(tmp_user->uuid, username) == 0) {
            tmp_user->connected = 0;
            name_to_send = strdup(tmp_user->name);
        }
    print_event_logout(username, name_to_send, write_fd, *data);
    return data;
}

void print_event_logout(char *uuid, char *name, int write_fd, t_data data)
{
    t_client *print_client = data.client;

    dprintf(write_fd, "231 %s %s user disconnected\r\n", uuid, name);
    for (; print_client; print_client = print_client->next)
        if (print_client->associated_user != NULL)
            dprintf(print_client->fd_client, "231 %s %s user disconnected\r\n",
            uuid, name);
    server_event_user_logged_out(uuid);
}
