/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** subscribe.c
*/

#include "server.h"

t_data *subscribe_to_team(t_data *data, char **array, t_client *cli)
{
    char *team_uuid = clean_username(array[1]);

    if (!check_if_team_exists(data, cli->fd_client, team_uuid) ||
        user_is_already_in(*data, cli->fd_client, team_uuid))
        return data;
    data = add_user_to_team(data, cli, team_uuid);
    data = add_team_to_user(data, cli, team_uuid);
    server_event_user_subscribed(team_uuid, cli->associated_user);
    dprintf(cli->fd_client, "222 %s %s\r\n", cli->associated_user, team_uuid);
    free(team_uuid);
    return data;
}

t_data *subscribe_user(t_data *data, char **array, int write_fd)
{
    t_client *tmp = data->client;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 Use /login before\r\n");
        return data;
    }
    if (count_lines(array) != 2 || double_coat(array[1]) == false
        || strlen(array[1]) != 38) {
        dprintf(write_fd, "500 Bads arguments\r\n");
        return data;
    }
    for (; tmp; tmp = tmp->next)
        if (tmp->fd_client == write_fd)
            data = subscribe_to_team(data, array, tmp);
    return data;
}

t_data *add_user_to_team(t_data *data, t_client *cli, char *team_uuid)
{
    t_teams *tmp_teams = data->teams;

    for (; tmp_teams; tmp_teams = tmp_teams->next)
        if (strcmp(tmp_teams->uuid, team_uuid) == 0)
            tmp_teams->users = add_value_in_array(tmp_teams->users,
            cli->associated_user);
    return data;
}

t_data *add_team_to_user(t_data *data, t_client *cli, char *team_uuid)
{
    t_user *tmp_users = data->user;

    for (; tmp_users; tmp_users = tmp_users->next)
        if (strcmp(tmp_users->uuid, cli->associated_user) == 0)
            tmp_users->team = add_value_in_array(tmp_users->team, team_uuid);
    return data;
}
