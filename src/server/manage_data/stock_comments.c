/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** stock_comments.c
*/

#include "server.h"

void print_comments_in_file(t_comments *comments, FILE *fd)
{
    for (; comments; comments = comments->next) {
        fprintf(fd, "%s%s~", "user^", comments->user);
        fprintf(fd, "%s%s~", "message^", comments->message);
        fprintf(fd, "%s%s~", "time^", comments->time);
        fprintf(fd, "%s%s~", "team^", comments->team);
        fprintf(fd, "%s%s", "thread^", comments->thread);
        if (comments->next)
            fprintf(fd, "`");
    }
}

void save_comments_in_file(t_threads *threads, FILE *fd)
{
    int count = 0;
    int save_count = 0;

    fprintf(fd, ".comments\n");
    for (; threads; threads = threads->next) {
        if (threads->comments) {
            count > save_count ? fprintf(fd, "`") : 0;
            save_count = count;
            print_comments_in_file(threads->comments, fd);
            count++;
        }
    }
    if (!count)
        fprintf(fd, "user^~message^~time^~team^~thread^\n");
    else
        fprintf(fd, "\n");
}
