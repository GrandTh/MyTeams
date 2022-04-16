/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** my_help.c
*/

#include "server.h"

int check_help_args(t_client *client, char **array)
{
    if (array[1] == NULL)
        return 0;
    else {
        dprintf(client->fd_client, "515 - Usage: [/help]\r\n");
        return 1;
    }
}

t_data *print_my_help(t_data *data, char **array, int write_fd)
{
    (void) array;
    (void) write_fd;

    if (check_help_args(data->client, array) == 0)
        dprintf(write_fd, HELP);
    return data;
}
