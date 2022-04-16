/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** utils_subscribe.c
*/

#include "server.h"

int user_is_already_in(t_data data, int write_fd, char *team_uuid)
{
    t_client *tmp_client = data.client;
    char *uuid = NULL;
    int true_var = 0;

    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd)
            uuid = strdup(tmp_client->associated_user);
    if (check_if_user_in_team(&data, team_uuid, uuid)) {
        true_var = 1,
        dprintf(write_fd, "340 you are already in this team\r\n");
        return true_var;
    }
    return true_var;
}

int user_is_not_already_in(t_data data, int write_fd, char *team_uuid)
{
    t_client *tmp_client = data.client;
    char *uuid = NULL;
    int true_var = 0;

    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd)
            uuid = strdup(tmp_client->associated_user);
    if (!check_if_user_in_team(&data, team_uuid, uuid)) {
        true_var = 1,
        dprintf(write_fd, "340 you are not in this team\r\n");
        return true_var;
    }
    return true_var;
}
