/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** info_cmd.c
*/

#include "server.h"

void print_info_user(t_data data, t_client *cli)
{
    t_user *tmp = data.user;

    for (; tmp; tmp = tmp->next) {
        if (strcmp(cli->associated_user, tmp->uuid) == 0) {
            dprintf(cli->fd_client, "255\r\n");
            sleep(0.2);
            dprintf(cli->fd_client, "%s|%s|%d\r\n", tmp->uuid, tmp->name,
                tmp->connected);
        }
    }
}

void print_info_team(t_data data, t_client *cli)
{
    t_teams *tmp = data.teams;

    if (!check_if_team_exists(&data, cli->fd_client, cli->team_use))
        return;
    for (; tmp; tmp = tmp->next) {
        if (strcmp(cli->team_use, tmp->uuid) == 0) {
            dprintf(cli->fd_client, "256\r\n");
            sleep(0.2);
            dprintf(cli->fd_client, "%s|%s|%s\r\n", tmp->uuid, tmp->name,
                tmp->description);
        }
    }
}

void print_info_channel(t_data data, t_client *cli)
{
    t_channels *tmp = data.channels;

    if (!check_if_team_exists(&data, cli->fd_client, cli->team_use)
    || !check_if_channel_exists(&data, cli))
        return ;
    for (; tmp; tmp = tmp->next) {
        if (strcmp(cli->channel_use, tmp->uuid) == 0) {
            dprintf(cli->fd_client, "257\r\n");
            sleep(0.2);
            dprintf(cli->fd_client, "%s|%s|%s\r\n", tmp->uuid, tmp->name,
                tmp->description);
        }
    }
}

void print_info_threads(t_data data, t_client *cli)
{
    t_threads *tmp = data.threads;

    if (!check_if_team_exists(&data, cli->fd_client, cli->team_use)
    || !check_if_channel_exists(&data, cli)
    || !check_if_thread_exists(&data, cli))
        return;
    for (; tmp; tmp = tmp->next) {
        if (strcmp(cli->thread_use, tmp->uuid) == 0) {
            dprintf(cli->fd_client, "258\r\n");
            sleep(0.2);
            dprintf(cli->fd_client, "%s|%s|%s|%s|%s\r\n", tmp->uuid,
                tmp->users[0], tmp->time, tmp->title, tmp->message);
        }
    }
}
