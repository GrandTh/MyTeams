/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_list.c
*/

#include "server.h"

void print_users_list(t_user *users)
{
    if (!users)
        return;
    for (int count = 0; users; users = users->next, count++) {
        printf("user %d\n", count);
        printf("uuid:%s\n", users->uuid);
        printf("name:%s\n", users->name);
        printf("status:%d\n", users->connected);
        for (int i = 0; users->team[i]; i++)
            printf("team[%d]:%s\n", i, users->team[i]);
    }
}

void print_teams_list(t_teams *teams)
{
    if (!teams)
        return;
    for (int count = 0; teams; teams = teams->next, count++) {
        printf("team %d\n", count);
        printf("uuid:%s\n", teams->uuid);
        printf("name:%s\n", teams->name);
        printf("description:%s\n", teams->description);
        for (int i = 0; teams->users[i]; i++)
            printf("user[%d]:%s\n", i, teams->users[i]);
    }
}

void print_channels_list(t_channels *channels)
{
    if (!channels)
        return;
    for (int count = 0; channels; channels = channels->next, count++) {
        printf("channel %d\n", count);
        printf("uuid:%s\n", channels->uuid);
        printf("name:%s\n", channels->name);
        printf("description:%s\n", channels->description);
        printf("team:%s\n", channels->team);
        for (int i = 0; channels->users[i]; i++)
            printf("user[%d]:%s\n", i, channels->users[i]);
    }
}

void print_messages_list(t_messages *messages)
{
    if (!messages)
        return;
    for (int i = 0; messages; messages = messages->next, i++) {
        printf("messages %d\n", i);
        printf("message:%s\n", messages->message);
        printf("to:%s\n", messages->to);
        printf("from:%s\n", messages->from);
    }
}

void print_all(t_data *data)
{
    print_users_list(data->user);
    print_teams_list(data->teams);
    print_channels_list(data->channels);
    print_threads_list(data->threads);
    print_messages_list(data->messages);
    print_clients_list(data->client);
}
