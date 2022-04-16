/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** teams_parsing.c
*/

#include "server.h"

t_teams *add_teams_in_list(t_teams *teams, char **array)
{
    t_teams *new = calloc(1, sizeof(t_teams));
    t_teams *tmp = teams;

    new->uuid = strdup(array[0]);
    new->name = strdup(array[1]);
    new->description = strdup(array[2]);
    new->users = str_to_array(array[3], "|");
    new->next = NULL;
    if (teams == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return teams;
    }
}

t_data *parse_teams(t_data *data, char *line)
{
    char **separate_teams = str_to_array(line, "`");
    char **one_team = NULL;

    for (int i = 0; separate_teams[i]; i++) {
        one_team = str_to_array(separate_teams[i], "~");
        one_team = retrieve_clean_value(one_team);
        data->teams = add_teams_in_list(data->teams, one_team);
        free_array(one_team);
    }
    free_array(separate_teams);
    if (strlen(data->teams->name) == 0) {
        data->teams = free_teams_list(data->teams);
        return data;
    }
    return data;
}
