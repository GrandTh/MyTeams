/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** check_team_in_user.c
*/

#include "server.h"

int check_if_team_in_user(t_data *data, char *team_uuid, char *user_uuid)
{
    t_user *tmp = data->user;
    int check = 0;

    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->uuid, user_uuid))
            break;
    if (!tmp->team)
        return check;
    for (int i = 0; tmp->team[i]; i++)
        if (!strcmp(tmp->team[i], team_uuid))
            check = 1;
    return check;
}
