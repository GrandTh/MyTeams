/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** stock_threads.c
*/

#include "server.h"

void print_threads_in_file(t_threads *threads, FILE *fd)
{
    for (;threads; threads = threads->next) {
        fprintf(fd, "%s%s~", "uuid^", threads->uuid);
        fprintf(fd, "%s%s~", "title^", threads->title);
        fprintf(fd, "%s%s~", "message^", threads->message);
        fprintf(fd, "%s%s~", "time^", threads->time);
        fprintf(fd, "%s%s~", "team^", threads->team);
        fprintf(fd, "%s%s~", "channel^", threads->channel);
        if (threads->users) {
            fprintf(fd, "%s%s", "users^", threads->users[0]);
            for (int i = 1; threads->users[i]; i++)
                fprintf(fd, "|%s", threads->users[i]);
        } else
            fprintf(fd, "%s", "users^");
        if (threads->next)
            fprintf(fd, "`");
        else
            fprintf(fd, "\n");
    }
}

t_threads *save_threads_in_file(t_threads *threads, FILE *fd)
{
    fprintf(fd, ".threads\n");
    if (threads)
        print_threads_in_file(threads, fd);
    else
        fprintf(fd, "uuid^~title^~message^~time^~team^~channel^~users^\n");
    return threads;
}
