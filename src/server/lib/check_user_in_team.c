/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** check_user_in_team.c
*/

#include "server.h"

int check_if_user_in_team(t_data *data, char *team_uuid, char *user_uuid)
{
    t_teams *tmp = data->teams;
    int check = 0;

    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->uuid, team_uuid))
            break;
    if (!tmp->users)
        return check;
    for (int i = 0; tmp->users[i]; i++)
        if (!strcmp(tmp->users[i], user_uuid))
            check = 1;
    return check;
}
