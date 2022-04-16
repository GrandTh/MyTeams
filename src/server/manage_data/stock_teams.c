/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** stock_teams.c
*/

#include "server.h"

void print_teams_in_file(t_teams *teams, FILE *fd)
{
    for (;teams; teams = teams->next) {
        fprintf(fd, "%s%s~", "uuid^", teams->uuid);
        fprintf(fd, "%s%s~", "name^", teams->name);
        fprintf(fd, "%s%s~", "description^", teams->description);
        if (teams->users) {
            fprintf(fd, "%s%s", "users^", teams->users[0]);
            for (int i = 1; teams->users[i]; i++)
                fprintf(fd, "|%s", teams->users[i]);
        } else
            fprintf(fd, "%s", "users^");
        if (teams->next)
            fprintf(fd, "`");
        else
            fprintf(fd, "\n");
    }
}

t_teams *save_teams_in_file(t_teams *teams, FILE *fd)
{
    fprintf(fd, ".teams\n");
    if (teams)
        print_teams_in_file(teams, fd);
    else
        fprintf(fd, "uuid^~name^~description^~users^\n");
    return teams;
}
