/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** stock_data_file.c
*/

#include "server.h"

void stock_data_in_file(t_data *data)
{
    FILE *fd = fopen("database/data.txt", "w+");

    if (!fd)
        return;
    save_user_in_file(data->user, fd);
    save_teams_in_file(data->teams, fd);
    save_channels_in_file(data->channels, fd);
    save_threads_in_file(data->threads, fd);
    save_comments_in_file(data->threads, fd);
    save_messages_in_file(data->messages, fd);
    fclose(fd);
}
