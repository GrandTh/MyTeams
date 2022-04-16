/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** stock_channels.c
*/

#include "server.h"

void print_channels_in_file(t_channels *channels, FILE *fd)
{
    for (;channels; channels = channels->next) {
        fprintf(fd, "%s%s~", "uuid^", channels->uuid);
        fprintf(fd, "%s%s~", "name^", channels->name);
        fprintf(fd, "%s%s~", "description^", channels->description);
        fprintf(fd, "%s%s~", "team^", channels->team);
        if (channels->users) {
            fprintf(fd, "%s%s", "users^", channels->users[0]);
            for (int i = 1; channels->users[i]; i++)
                fprintf(fd, "|%s", channels->users[i]);
        } else
            fprintf(fd, "%s", "users^");
        if (channels->next)
            fprintf(fd, "`");
        else
            fprintf(fd, "\n");
    }
}

t_channels *save_channels_in_file(t_channels *channels, FILE *fd)
{
    fprintf(fd, ".channels\n");
    if (channels)
        print_channels_in_file(channels, fd);
    else
        fprintf(fd, "uuid^~name^~description^~team^~users^\n");
    return channels;
}
