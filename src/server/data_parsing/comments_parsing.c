/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** comments_parsing.c
*/

#include "server.h"

void add_comments_in_list(t_comments **comments, char **array)
{
    t_comments *new = calloc(1, sizeof(t_comments));

    new->user = strdup(array[0]);
    new->message = strdup(array[1]);
    new->time = strdup(array[2]);
    new->team = strdup(array[3]);
    new->thread = strdup(array[4]);
    new->next = NULL;
    while (*comments)
        comments = &((*comments)->next);
    *comments = new;
}

t_data *parse_comments(t_data *data, char *line)
{
    char **separate_comments = str_to_array(line, "`");
    char **one_comment = NULL;
    t_threads *tmp = data->threads;

    for (int i = 0; separate_comments[i]; i++) {
        one_comment = str_to_array(separate_comments[i], "~");
        one_comment = retrieve_clean_value(one_comment);
        for (; tmp; tmp = tmp->next)
            if (!strcmp(tmp->uuid, one_comment[4]))
                add_comments_in_list(&tmp->comments, one_comment);
        tmp = data->threads;
        free_array(one_comment);
    }
    free_array(separate_comments);
    for (; tmp; tmp = tmp->next)
        if (tmp->comments && strlen(tmp->comments->user) == 0)
            tmp->comments = free_comments_list(tmp->comments);
    return data;
}
