/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-mychannels-maxime.simon
** File description:
** channels_parsing.c
*/

#include "server.h"

t_channels *add_channels_in_list(t_channels *channels, char **array)
{
    t_channels *new = calloc(1, sizeof(t_channels));
    t_channels *tmp = channels;

    new->uuid = strdup(array[0]);
    new->name = strdup(array[1]);
    new->description = strdup(array[2]);
    new->team = strdup(array[3]);
    new->users = str_to_array(array[4], "|");
    new->next = NULL;
    if (channels == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return channels;
    }
}

t_data *parse_channels(t_data *data, char *line)
{
    char **separate_channels = str_to_array(line, "`");
    char **one_channel = NULL;

    for (int i = 0; separate_channels[i]; i++) {
        one_channel = str_to_array(separate_channels[i], "~");
        one_channel = retrieve_clean_value(one_channel);
        data->channels = add_channels_in_list(data->channels, one_channel);
        free_array(one_channel);
    }
    free_array(separate_channels);
    if (strlen(data->channels->name) == 0) {
        data->channels = free_channels_list(data->channels);
        return data;
    }
    return data;
}
