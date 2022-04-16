/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** threads_parsing.c
*/

#include "server.h"

t_threads *add_threads_in_list(t_threads *threads, char **array)
{
    t_threads *new = calloc(1, sizeof(t_threads));
    t_threads *tmp = threads;

    new->uuid = strdup(array[0]);
    new->title = strdup(array[1]);
    new->message = strdup(array[2]);
    new->time = strdup(array[3]);
    new->team = strdup(array[4]);
    new->channel = strdup(array[5]);
    new->users = str_to_array(array[6], "|");
    new->comments = NULL;
    new->next = NULL;
    if (threads == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return threads;
    }
}

t_data *parse_threads(t_data *data, char *line)
{
    char **separate_threads = str_to_array(line, "`");
    char **one_thread = NULL;

    for (int i = 0; separate_threads[i]; i++) {
        one_thread = str_to_array(separate_threads[i], "~");
        one_thread = retrieve_clean_value(one_thread);
        data->threads = add_threads_in_list(data->threads, one_thread);
        free_array(one_thread);
    }
    free_array(separate_threads);
    if (strlen(data->threads->title) == 0) {
        data->threads = free_threads_list(data->threads);
        return data;
    }
    return data;
}
