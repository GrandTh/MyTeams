/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** users_parsing.c
*/

#include "server.h"

t_user *add_user_in_list(t_user *user, char **array)
{
    t_user *new = calloc(1, sizeof(t_user));
    t_user *tmp = user;

    new->uuid = strdup(array[0]);
    new->name = strdup(array[1]);
    new->connected = atoi(array[2]);
    new->team = str_to_array(array[3], "|");
    new->next = NULL;
    if (strlen(new->uuid))
        server_event_user_loaded(new->uuid, new->name);
    if (user == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return user;
    }
}

t_data *parse_user(t_data *data, char *line)
{
    char **separate_users = str_to_array(line, "`");
    char **one_user = NULL;

    for (int i = 0; separate_users[i]; i++) {
        one_user = str_to_array(separate_users[i], "~");
        one_user = retrieve_clean_value(one_user);
        data->user = add_user_in_list(data->user, one_user);
        free_array(one_user);
    }
    free_array(separate_users);
    if (strlen(data->user->name) == 0) {
        data->user = free_users_list(data->user);
        return data;
    }
    return data;
}
