/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_event_element_create.c
*/

#include "server.h"

void print_event_team_create(t_data *data)
{
    t_client *tmp = data->client;
    t_teams *tmp_t = data->teams;

    for (; tmp_t->next; tmp_t = tmp_t->next);
    for (; tmp; tmp = tmp->next)
        if (tmp->associated_user)
            dprintf(tmp->fd_client, "151 %s %s %s a team was created\r\n",
                tmp_t->uuid, replace_char_in_str(tmp_t->name, ' ', '|'),
                replace_char_in_str(tmp_t->description, ' ', '|'));
}

void print_event_channel_create(t_data *data)
{
    t_client *tmp = data->client;
    t_channels *tmp_c = data->channels;

    for (; tmp_c->next; tmp_c = tmp_c->next);
    for (; tmp; tmp = tmp->next) {
        if (tmp->associated_user
            && check_if_team_in_user(data, tmp_c->team, tmp->associated_user))
            dprintf(tmp->fd_client, "152 %s %s %s a channel was created\r\n",
                tmp_c->uuid, replace_char_in_str(tmp_c->name, ' ', '|'),
                replace_char_in_str(tmp_c->description, ' ', '|'));
    }
}

void print_event_thread_create(t_data *data)
{
    t_client *tmp = data->client;
    t_threads *tmp_t = data->threads;

    for (; tmp_t->next; tmp_t = tmp_t->next);
    for (; tmp; tmp = tmp->next)
        if (tmp->associated_user
            && check_if_team_in_user(data, tmp_t->team, tmp->associated_user))
            dprintf(tmp->fd_client,
                "153 %s %s %s %s %s a thread was created\r\n", tmp_t->uuid,
                tmp_t->users[0], replace_char_in_str(tmp_t->time, ' ', '|'),
                replace_char_in_str(tmp_t->title, ' ', '|'),
                replace_char_in_str(tmp_t->message, ' ', '|'));
}

void print_event_comment_create(t_data *data, char *uuid_thread)
{
    t_client *tmp = data->client;
    t_threads *tmp_t = data->threads;
    t_comments *tmp_c;

    for (; tmp_t->next; tmp_t = tmp_t->next)
        if (!strcmp(tmp_t->uuid, uuid_thread))
            break;
    tmp_c = tmp_t->comments;
    for (; tmp_c->next; tmp_c = tmp_c->next);
    for (; tmp; tmp = tmp->next)
        if (tmp->associated_user
            && check_if_team_in_user(data, tmp_c->team, tmp->associated_user))
            dprintf(tmp->fd_client,
                "154 %s %s %s %s a reply was created\r\n", tmp_c->team,
                tmp_c->thread, tmp_c->user,
                replace_char_in_str(tmp_c->message, ' ', '|'));
}
