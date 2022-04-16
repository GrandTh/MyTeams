/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** use.c
*/

#include "server.h"

void error_handling_use_args_next(char **array, int write_fd, t_client *client)
{
    if (!array[3])
        use_channel(array, write_fd, client);
    else if (!array[4])
        use_thread(array, write_fd, client);
    else
        dprintf(write_fd,
    "515 Usage: /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”]\r\n");
}

void error_handling_use_args(char **array, int write_fd, t_client *client)
{
    if (!array[1])
        use_nothing(write_fd, client);
    else if (!array[2])
        use_team(array, write_fd, client);
    else
        error_handling_use_args_next(array, write_fd, client);
}

t_data *use_command(t_data *data, char **array, int write_fd)
{
    t_client *tmp = data->client;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 Use /login before\r\n");
        return data;
    }
    for (; tmp; tmp = tmp->next) {
        if (tmp->fd_client == write_fd)
            error_handling_use_args(array, write_fd, tmp);
    }
    return data;
}
