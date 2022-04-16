/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** login.c
*/

#include "server.h"

t_data *connect_user(t_data *data, char *username, int write_fd)
{
    t_user *tmp_user = data->user;
    char *name = NULL;
    char *uuid = NULL;

    if (check_already_connect(*data, write_fd) == true) {
            dprintf(write_fd, "410 a user is already connected\r\n");
            return data;
    }
    else if (check_already_connect(*data, write_fd) == false) {
        for (; tmp_user; tmp_user = tmp_user->next)
            if (strcmp(tmp_user->name, clean_username(username)) == 0) {
                tmp_user->connected = 1;
                name = strdup(tmp_user->name);
                uuid = strdup(tmp_user->uuid);
            }
        add_associated_user(data, username, write_fd);
    }
    print_event_login(*data, uuid, name);
    return data;
}

t_data *create_user(t_data *data, int write_fd, char **array)
{
    t_client *tmp = data->client;

    if (check_already_connect(*data, write_fd) == true) {
            dprintf(write_fd, "410 a user is already connected\r\n");
            return data;
    }
    else if (check_already_connect(*data, write_fd) == false) {
        data->user = add_user(data->user, array[1], write_fd, data);
        for (;tmp; tmp = tmp->next) {
            if (tmp->fd_client == write_fd) {
                tmp->associated_user = strdup(get_my_uuid(*data,
                    clean_username(array[1])));
                break;
            }
        }
    }
    return data;
}

t_data *login_user(t_data *data, char **array, int write_fd)
{
    if (count_lines(array) != 2 || double_coat(array[1]) == false ||
        strlen(clean_username(array[1])) >= MAX_NAME_LENGTH)
        dprintf(write_fd, "510 Bads arguments\r\n");
    else if (count_lines(array) == 2 && user_exists(*data, array[1]) == false)
        create_user(data, write_fd, array);
    else if (count_lines(array) == 2 && user_exists(*data, array[1]) == true)
        connect_user(data, array[1], write_fd);
    return data;
}

t_data *add_associated_user(t_data *data, char *username, int write_fd)
{
    t_client *tmp_client = data->client;

    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd) {
            tmp_client->associated_user = strdup(get_my_uuid(*data,
            clean_username(username)));
        }
    return data;
}
