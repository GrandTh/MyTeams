/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** messages_parsing.c
*/

#include "server.h"

t_messages *add_message_in_list(t_messages *message, char **array)
{
    t_messages *new = calloc(1, sizeof(t_messages));
    t_messages *tmp = message;

    new->message = strdup(array[0]);
    new->to = strdup(array[1]);
    new->from = strdup(array[2]);
    new->time = strdup(array[3]);
    new->next = NULL;
    if (message == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return message;
    }
}

t_data *parse_messages(t_data *data, char *line)
{
    char **separate_messages = str_to_array(line, "`");
    char **one_message = NULL;

    for (int i = 0; separate_messages[i]; i++) {
        one_message = str_to_array(separate_messages[i], "~");
        one_message = retrieve_clean_value(one_message);
        data->messages = add_message_in_list(data->messages, one_message);
        free_array(one_message);
    }
    free_array(separate_messages);
    if (strlen(data->messages->message) == 0) {
        data->messages = free_messages_list(data->messages);
        return data;
    }
    return data;
}
