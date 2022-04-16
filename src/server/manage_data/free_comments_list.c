/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** free_comments_list.c
*/

#include "server.h"

t_comments *free_comments_list(t_comments *comments)
{
    t_comments *tmp;

    if (!comments)
        return NULL;
    else {
        tmp = comments->next;
        free(comments->message);
        free(comments->user);
        free(comments->time);
        free(comments->team);
        free(comments->thread);
        free(comments);
        return free_comments_list(tmp);
    }
}
