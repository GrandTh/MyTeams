/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** unsubscribe.c
*/

#include "server.h"

t_data *unsubscribe_cmd(t_data *data, char **array, int write_fd)
{
    char *team_uuid = NULL;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 Use /login before\r\n");
        return data;
    }
    if (count_lines(array) == 2 && double_coat(array[1]) == true
        && strlen(array[1]) == 38) {
            team_uuid = clean_username(array[1]);
        if (check_if_team_exists(data, write_fd, team_uuid) == 1 &&
        user_is_not_already_in(*data, write_fd, team_uuid) == 0) {
            remove_user_to_team(data, write_fd, team_uuid);
            remove_team_to_user(data, write_fd, team_uuid);
        }
    }
    else
        dprintf(write_fd, "510 Bads arguments\r\n");
    return data;
}

t_data *remove_user_to_team(t_data *data, int write_fd, char *team_uuid)
{
    t_client *tmp_client = data->client;
    t_teams *tmp_teams = data->teams;
    char *my_uuid = NULL;

    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd &&
        tmp_client->associated_user != NULL)
            my_uuid = strdup(tmp_client->associated_user);
    for (; tmp_teams; tmp_teams = tmp_teams->next)
        if (strcmp(tmp_teams->uuid, team_uuid) == 0)
            tmp_teams->users = remove_value_in_array(tmp_teams->users,
                my_uuid);
    return data;
}

t_data *remove_team_to_user(t_data *data, int write_fd, char *team_uuid)
{
    t_client *tmp_client = data->client;
    t_user *tmp_users = data->user;
    char *my_uuid = NULL;
    for (; tmp_client; tmp_client = tmp_client->next)
        if (tmp_client->fd_client == write_fd &&
        tmp_client->associated_user != NULL)
            my_uuid = strdup(tmp_client->associated_user);
    for (; tmp_users; tmp_users = tmp_users->next)
        if (strcmp(tmp_users->uuid, my_uuid) == 0)
            tmp_users->team = remove_value_in_array(tmp_users->team,
            team_uuid);
    server_event_user_unsubscribed(team_uuid, my_uuid);
    dprintf(write_fd, "223 %s %s\r\n", my_uuid, team_uuid);
    return data;
}
