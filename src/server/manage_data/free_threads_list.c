/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** free_threads_list.c
*/

#include "server.h"

void free_thread_occurence(t_threads *threads)
{
    free(threads->uuid);
    free(threads->title);
    free(threads->message);
    free(threads->time);
    free(threads->team);
    free(threads->channel);
}

t_threads *free_threads_list(t_threads *threads)
{
    t_threads *tmp;

    if (!threads)
        return NULL;
    else {
        tmp = threads->next;
        free_thread_occurence(threads);
        if (threads->users) {
            for (int i = 0; threads->users[i]; i++)
                free(threads->users[i]);
            free(threads->users);
        }
        if (threads->comments)
            free_comments_list(threads->comments);
        free(threads);
        return free_threads_list(tmp);
    }
}
