/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** info_cmd.c
*/

#include "server.h"

void check_info_env(t_data data, t_client *tmp)
{
    if (tmp->use == 1 && !tmp->team_use)
        print_info_user(data, tmp);
    if (tmp->team_use && !tmp->channel_use)
        print_info_team(data, tmp);
    if (tmp->team_use && tmp->channel_use && !tmp->thread_use)
        print_info_channel(data, tmp);
    if (tmp->team_use && tmp->channel_use && tmp->thread_use)
        print_info_threads(data, tmp);
}

int args_handling(char **array, t_data data, int write_fd)
{
    t_client *tmp = data.client;

    if (count_lines(array) != 1) {
        dprintf(write_fd, "540 Wrong input\r\n");
        return 1;
    }
    for (; tmp; tmp = tmp->next)
        if (tmp->fd_client == write_fd)
            break;
    if (!tmp->use) {
        dprintf(write_fd, "420 Do /use before\r\n");
        return 1;
    }
    return 0;
}

t_data *info_cmd(t_data *data, char **array, int write_fd)
{
    t_client *tmp = data->client;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 use login before logout\r\n");
        return data;
    }
    if (args_handling(array, *data, write_fd) == 1)
        return data;
    for (; tmp; tmp = tmp->next)
        if (tmp->fd_client == write_fd)
            check_info_env(*data, tmp);
    return data;
}
