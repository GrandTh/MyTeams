/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** utils_login.c
*/

#include "server.h"

t_user *add_user(t_user *user, char *username, int write_fd, t_data *data)
{
    t_user *new = calloc(1, sizeof(t_user));
    t_user *tmp = user;

    new->uuid = strdup(generate_uuid());
    new->name = strdup(clean_username(username));
    new->connected = 1;
    new->next = NULL;
    server_event_user_created(new->uuid, new->name);
    server_event_user_logged_in(new->uuid);
    print_event_created(*data, write_fd, new->uuid, new->name);
    if (user == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return user;
    }
}

bool user_exists(t_data data, char *username)
{
    t_user *tmp_user = data.user;

    for (; tmp_user; tmp_user = tmp_user->next)
        if (strcmp(tmp_user->name, clean_username(username)) == 0)
            return true;
    return false;
}

bool check_already_connect(t_data data, int write_fd)
{
    t_client *tmp = data.client;

    for (; tmp; tmp = tmp->next)
        if (tmp->fd_client == write_fd && tmp->associated_user != NULL)
            return true;
    return false;
}

char *get_my_uuid(t_data data, char *username)
{
    char *my_uuid = NULL;
    t_user *tmp = data.user;

    for (; tmp; tmp = tmp->next)
        if (strcmp(tmp->name, username) == 0)
            my_uuid = strdup(tmp->uuid);
    return my_uuid;
}
