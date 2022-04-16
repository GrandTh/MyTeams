/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** stock_user.c
*/

#include "server.h"

t_user *put_user_status_to_0(t_user *user)
{
    t_user *tmp = user;

    for (; tmp; tmp = tmp->next)
        tmp->connected = 0;
    return user;
}

void print_user_in_file(t_user *user, FILE *fd)
{
    for (; user; user = user->next) {
        fprintf(fd, "%s%s~", "uuid^", user->uuid);
        fprintf(fd, "%s%s~", "name^", user->name);
        fprintf(fd, "%s%d~", "status^", user->connected);
        if (user->team) {
            fprintf(fd, "%s%s", "team^", user->team[0]);
            for (int i = 1; user->team[i]; i++)
                fprintf(fd, "|%s", user->team[i]);
        } else
            fprintf(fd, "%s", "team^");
        if (user->next)
            fprintf(fd, "`");
        else
            fprintf(fd, "\n");
    }
}

t_user *save_user_in_file(t_user *user, FILE *fd)
{
    user = put_user_status_to_0(user);
    fprintf(fd, ".user\n");
    if (user)
        print_user_in_file(user, fd);
    else
        fprintf(fd, "uuid^~name^~status^~team^\n");
    return user;
}
