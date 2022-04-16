/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** free_messages_list.c
*/

#include "server.h"

t_messages *free_messages_list(t_messages *messages)
{
    t_messages *tmp;

    if (!messages)
        return NULL;
    else {
        tmp = messages->next;
        free(messages->message);
        free(messages->from);
        free(messages->to);
        free(messages->time);
        free(messages);
        return free_messages_list(tmp);
    }
}
