/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** list_cmd.c
*/

#include "server.h"

void print_list_team(t_data data, int write_fd)
{
    t_teams *tmp = data.teams;
    int size = get_size_teams(data);

    dprintf(write_fd, "251 %d\r\n", size);
    for (; tmp; tmp = tmp->next) {
        sleep(0.2);
        dprintf(write_fd, "%s|%s|%s\r\n", tmp->uuid, tmp->name,
            tmp->description);
    }
}

void print_list_channel(t_data data, t_client *cli)
{
    t_channels *tmp = data.channels;
    int size = 0;

    if (!check_if_team_exists(&data, cli->fd_client, cli->team_use))
        return;
    size = get_size_channels(data, cli);
    dprintf(cli->fd_client, "252 %d\r\n", size);
    for (; tmp; tmp = tmp->next) {
        sleep(0.2);
        if (!strcmp(tmp->team, cli->team_use))
            dprintf(cli->fd_client, "%s|%s|%s\r\n", tmp->uuid, tmp->name,
                tmp->description);
    }
}

void print_list_thread(t_data data, t_client *cli)
{
    t_threads *tmp = data.threads;
    int size = 0;

    if (!check_if_team_exists(&data, cli->fd_client, cli->team_use)
    || !check_if_channel_exists(&data, cli))
        return ;
    size = get_size_threads(data, cli);
    dprintf(cli->fd_client, "253 %d\r\n", size);
    for (; tmp; tmp = tmp->next) {
        sleep(0.2);
        if (!strcmp(tmp->team, cli->team_use)
            && !strcmp(tmp->channel, cli->channel_use))
            dprintf(cli->fd_client, "%s|%s|%s|%s|%s\r\n",
                tmp->uuid, tmp->users[0], tmp->time, tmp->title, tmp->message);
    }
}

void print_list_replies(t_data data, t_client *cli)
{
    t_threads *tmp = data.threads;
    t_comments *tmp_c;
    int size = 0;

    if (!check_if_team_exists(&data, cli->fd_client, cli->team_use)
    || !check_if_channel_exists(&data, cli)
    || !check_if_thread_exists(&data, cli))
        return;
    size = get_size_comments(data, cli);
    dprintf(cli->fd_client, "254 %d\r\n", size);
    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->uuid, cli->thread_use))
            break;
    tmp_c = tmp->comments;
    for (; tmp_c; tmp_c = tmp_c->next) {
        sleep(0.2);
        dprintf(cli->fd_client, "%s|%s|%s|%s\r\n", tmp_c->thread,
            tmp_c->user, tmp_c->time, tmp_c->message);
    }
}
