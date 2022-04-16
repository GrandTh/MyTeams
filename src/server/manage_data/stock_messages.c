/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** stock_messages.c
*/

#include "server.h"

void print_messages_in_file(t_messages *messages, FILE *fd)
{
    for (;messages; messages = messages->next) {
        fprintf(fd, "%s%s~", "message^", messages->message);
        fprintf(fd, "%s%s~", "to^", messages->to);
        fprintf(fd, "%s%s~", "from^", messages->from);
        fprintf(fd, "%s%s", "time^", messages->time);
        if (messages->next)
            fprintf(fd, "`");
        else
            fprintf(fd, "\n");
    }
}

t_messages *save_messages_in_file(t_messages *messages, FILE *fd)
{
    fprintf(fd, ".messages\n");
    if (messages)
        print_messages_in_file(messages, fd);
    else
        fprintf(fd, "message^~to^~from^~time^\n");
    return messages;
}
