/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** free_users_list.c
*/

#include "server.h"

t_user *free_users_list(t_user *user)
{
    t_user *tmp;

    if (!user)
        return NULL;
    else {
        tmp = user->next;
        free(user->name);
        free(user->uuid);
        if (user->team) {
            for (int i = 0; user->team[i]; i++)
                free(user->team[i]);
            free(user->team);
        }
        free(user);
        return free_users_list(tmp);
    }
}
