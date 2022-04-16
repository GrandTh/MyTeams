/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** user.c
*/

#include "server.h"

void print_all_users(t_data data, int write_fd)
{
    int i = 0;
    t_user *tmp = data.user;
    size_t size = 0;

    for (; tmp; tmp = tmp->next) {
        i++;
        size += strlen(tmp->uuid) + strlen(tmp->name) + 1 + 5;
    }
    dprintf(write_fd, "200 %d\n", i);
    sleep(0.5);
    for (; data.user; data.user = data.user->next)
        dprintf(write_fd, "%s %s %d\n", data.user->uuid, data.user->name,
            data.user->connected);
}

void print_one_user(t_user *user, char *uuid, int write_fd)
{
    bool check = false;

    for (;user; user = user->next) {
        if (strcmp(uuid, user->uuid) == 0) {
            dprintf(write_fd, "201 %s %s %d\r\n", uuid, user->name,
                user->connected);
                check = true;
        }
    }
    if (check == false)
        dprintf(write_fd, "400 %s No user with this uuid\r\n", uuid);
}

t_data *users_cmd(t_data *data, char **array, int write_fd)
{
    (void) array;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 User /login before\r\n");
        return data;
    }
    if (count_lines(array) == 1)
        print_all_users(*data, write_fd);
    else
        dprintf(write_fd, "515 Usage : /users\r\n");
    return data;
}

t_data *user_cmd(t_data *data, char **array, int write_fd)
{
    char *uuid = calloc(38, sizeof(char));

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 User /login before\r\n");
        return data;
    }
    if (count_lines(array) == 2 && count_char(array[1]) == 38 &&
        double_coat(array[1]) == true) {
        uuid = clean_username(array[1]);
        print_one_user(data->user, uuid, write_fd);
        free(uuid);
    }
    else
        dprintf(write_fd, "515 Usage: /user[\"user_uuid\"]\r\n");
    return data;
}
