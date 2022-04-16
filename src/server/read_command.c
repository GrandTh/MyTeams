/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** read_command.c
*/

#include "server.h"

static ptr_function function [15] =
{
    &print_my_help,
    &login_user,
    &logout_user,
    &messages_cmd,
    &send_cmd,
    &user_cmd,
    &users_cmd,
    &use_command,
    &create_command,
    &subscribe_user,
    &subscribed_cmd,
    &unsubscribe_cmd,
    &list_cmd,
    &info_cmd,
    &ctrlc_client,
};

static char *cmd[16] =
{
    "/help",
    "/login",
    "/logout",
    "/messages",
    "/send",
    "/User",
    "/Users",
    "/use",
    "/create",
    "/subscribe",
    "/subscribed",
    "/unsubscribe",
    "/list",
    "/info",
    "Goodbye",
    NULL
};

t_data *get_cmd(t_data *data, char **array, int write_fd)
{
    for (int i = 0; cmd[i]; i++) {
        if (array[0] != NULL) {
            if (strcasecmp(array[0], cmd[i]) == 0) {
                function[i](data, array, write_fd);
                return data;
            }
        }
    }
    dprintf(write_fd, "500 command not found.\r\n");
    return data;
}

int write_client(t_data data, int fd)
{
    t_data *tmp = &data;
    int write = 0;

    while (tmp->client) {
        if (tmp->client->fd_client == fd) {
            write = tmp->client->fd_client;
            return write;
        }
        tmp->client = tmp->client->next;
    }
    return write_client(data, fd);
}

int read_from_client(int fd, t_data *data)
{
    char *message = NULL;
    char *cmd = { 0 };
    char **array = NULL;
    int write_fd = 0;

    message = get_next_line(fd);
    if (!message || !strlen(message))
        return 0;
    cmd = clean_str(message);
    array = parse_args_client(cmd);
    write_fd = write_client(*data, fd);
    data = get_cmd(data, array, write_fd);
    free(message);
    return 0;
}
