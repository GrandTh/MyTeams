/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** list_size.c
*/

#include "server.h"

int get_size_teams(t_data data)
{
    int size = 0;
    t_teams *tmp = data.teams;

    for (; tmp; tmp = tmp->next)
        size++;
    return size;
}

int get_size_channels(t_data data, t_client *cli)
{
    int size = 0;
    t_channels *tmp = data.channels;

    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->team, cli->team_use))
            size++;
    return size;
}

int get_size_threads(t_data data, t_client *cli)
{
    int size = 0;
    t_threads *tmp = data.threads;

    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->channel, cli->channel_use))
            size++;
    return size;
}

int get_size_comments(t_data data, t_client *cli)
{
    int size = 0;
    t_threads *tmp = data.threads;
    t_comments *tmp_c;

    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->uuid, cli->thread_use))
            break;
    tmp_c = tmp->comments;
    for (; tmp_c; tmp_c = tmp_c->next)
        size++;
    return size;
}
