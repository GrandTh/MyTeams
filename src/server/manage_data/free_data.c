/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** free_data.c
*/

#include "server.h"

t_teams *free_teams_list(t_teams *teams)
{
    t_teams *tmp;

    if (!teams)
        return NULL;
    else {
        tmp = teams->next;
        free(teams->name);
        free(teams->uuid);
        free(teams->description);
        if (teams->users) {
            for (int i = 0; teams->users[i]; i++)
                free(teams->users[i]);
            free(teams->users);
        }
        free(teams);
        return free_teams_list(tmp);
    }
}

t_channels *free_channels_list(t_channels *channels)
{
    t_channels *tmp;

    if (!channels)
        return NULL;
    else {
        tmp = channels->next;
        free(channels->uuid);
        free(channels->name);
        free(channels->description);
        free(channels->team);
        if (channels->users) {
            for (int i = 0; channels->users[i]; i++)
                free(channels->users[i]);
            free(channels->users);
        }
        free(channels);
        return free_channels_list(tmp);
    }
}

t_client *free_clients_list(t_client *clients)
{
    t_client *tmp;

    if (!clients)
        return NULL;
    else {
        tmp = clients->next;
        free(clients);
        return free_clients_list(tmp);
    }
}

void free_all_data(t_data *data)
{
    free_users_list(data->user);
    free_teams_list(data->teams);
    free_channels_list(data->channels);
    free_threads_list(data->threads);
    free_messages_list(data->messages);
    free_clients_list(data->client);
    free(data);
}
