/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_threads_list.c
*/

#include "server.h"

void print_threads_list(t_threads *threads)
{
    if (!threads)
        return;
    for (int count = 0; threads; threads = threads->next, count++) {
        printf("thread %d\n", count);
        printf("uuid:%s\n", threads->uuid);
        printf("title:%s\n", threads->title);
        printf("message:%s\n", threads->message);
        printf("time:%s\n", threads->time);
        printf("team:%s\n", threads->team);
        printf("channel:%s\n", threads->channel);
        if (threads->users)
            for (int i = 0; threads->users[i]; i++)
                printf("user[%d]:%s\n", i, threads->users[i]);
        if (threads->comments)
            print_comments_list(threads->comments);
    }
}

void print_comments_list(t_comments *comments)
{
    if (!comments)
        return;
    for (int i = 0; comments; comments = comments->next, i++) {
        printf("comment %d\n", i);
        printf("user %s\n", comments->user);
        printf("message %s\n", comments->message);
        printf("time:%s\n", comments->time);
        printf("team:%s\n", comments->team);
        printf("thread %s\n", comments->thread);
    }
}
