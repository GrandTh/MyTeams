/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** list_cmd.c
*/

#include "server.h"

void check_env_next(t_data data, t_client *tmp)
{
    if (tmp->team_use && tmp->channel_use && !tmp->thread_use)
        print_list_thread(data, tmp);
    else if (tmp->team_use && tmp->channel_use && tmp->thread_use)
        print_list_replies(data, tmp);
}

void check_env(t_data data, t_client *tmp)
{
    if (tmp->use == 1 && !tmp->team_use)
        print_list_team(data, tmp->fd_client);
    else if (tmp->team_use && !tmp->channel_use)
        print_list_channel(data, tmp);
    else
        check_env_next(data, tmp);
}

t_data *list_cmd(t_data *data, char **array, int write_fd)
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
            check_env(*data, tmp);
    return data;
}
