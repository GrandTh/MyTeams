/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create.c
*/

#include "server.h"

t_data *create_gestion_next(t_data *data, char **array, t_client *tmp)
{
    if (tmp->team_use && tmp->channel_use && !tmp->thread_use)
        return create_new_thread(data, array, tmp);
    else if (tmp->team_use && tmp->channel_use && tmp->thread_use)
        return create_new_comment(data, array, tmp);
    return data;
}

t_data *create_gestion(t_data *data, char **array, t_client *tmp)
{
    if (!tmp->team_use)
        return create_new_team(data, array, tmp);
    else if (tmp->team_use && !tmp->channel_use)
        return create_new_channel(data, array, tmp);
    return create_gestion_next(data, array, tmp);
}

t_data *create_command(t_data *data, char **array, int write_fd)
{
    t_client *tmp = data->client;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 Use /login before\r\n");
        return data;
    }
    for (; tmp; tmp = tmp->next) {
        if (tmp->fd_client == write_fd)
            data = create_gestion(data, array, tmp);
    }
    return data;
}
