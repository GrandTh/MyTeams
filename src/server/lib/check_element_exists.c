/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** check_element_exists.c
*/

#include "server.h"

int check_if_user_exists(t_data *data, int fd, char *user_uuid)
{
    t_user *tmp_user = data->user;
    int check = 0;

    for (; tmp_user; tmp_user = tmp_user->next)
        if (!strcmp(tmp_user->uuid, user_uuid))
            check = 1;
    if (!check)
        dprintf(fd, "400 %s No user with this uuid\r\n", user_uuid);
    return check;
}

int check_if_team_exists(t_data *data, int fd, char *team_uuid)
{
    t_teams *tmp_team = data->teams;
    int check = 0;

    for (; tmp_team; tmp_team = tmp_team->next)
        if (!strcmp(tmp_team->uuid, team_uuid))
            check = 1;
    if (!check)
        dprintf(fd, "401 %s No team with this uuid\r\n", team_uuid);
    return check;
}

int check_if_channel_exists(t_data *data, t_client *client)
{
    t_channels *tmp_channel = data->channels;
    int check = 0;

    for (; tmp_channel; tmp_channel = tmp_channel->next)
        if (!strcmp(tmp_channel->uuid, client->channel_use))
            check = 1;
    if (!check)
        dprintf(client->fd_client, "402 %s No channel with this uuid\r\n",
                client->channel_use);
    return check;
}

int check_if_thread_exists(t_data *data, t_client *client)
{
    t_threads *tmp_thread = data->threads;
    int check = 0;

    for (; tmp_thread; tmp_thread = tmp_thread->next)
        if (!strcmp(tmp_thread->uuid, client->thread_use))
            check = 1;
    if (!check)
        dprintf(client->fd_client, "403 %s No thread with this uuid\r\n",
                client->thread_use);
    return check;
}
