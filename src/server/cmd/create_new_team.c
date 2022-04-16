/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create_new_team.c
*/

#include "server.h"

t_teams *add_new_team(t_teams *teams, char **array, t_client *client)
{
    t_teams *new = calloc(1, sizeof(t_teams));
    t_teams *tmp = teams;

    new->uuid = generate_uuid();
    new->name = clean_username(array[1]);
    new->description = clean_username(array[2]);
    new->users = add_value_in_array(new->users, client->associated_user);
    new->next = NULL;
    server_event_team_created(new->uuid, new->name, client->associated_user);
    dprintf(client->fd_client, "202 %s %s %s Team created successfully\r\n",
    new->uuid, replace_char_in_str(new->name, ' ', '|'),
    replace_char_in_str(new->description, ' ', '|'));
    if (teams == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return teams;
    }
}

int error_gestion_create_team(t_data *data, char **array, t_client *client)
{
    t_teams *tmp = data->teams;

    if (count_lines(array) != 3 || double_coat(array[1]) == false
        || double_coat(array[2]) == false
        || strlen(clean_username(array[1])) >= MAX_NAME_LENGTH
        || strlen(clean_username(array[2])) >= MAX_DESCRIPTION_LENGTH) {
        dprintf(client->fd_client,
    "515 Usage: /create [“team_name”] [“team_description”]\r\n");
        return 1;
    }
    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->name, clean_username(array[1]))) {
            dprintf(client->fd_client,
            "501 %s This team already exists\r\n", tmp->name);
            return 1;
        }
    return 0;
}

t_data *create_new_team(t_data *data, char **array, t_client *client)
{
    t_teams *tmp;

    if (!client->use) {
        dprintf(client->fd_client, "420 Do /use before\r\n");
        return data;
    }
    if (error_gestion_create_team(data, array, client))
        return data;
    data->teams = add_new_team(data->teams, array, client);
    tmp = data->teams;
    for (; tmp->next; tmp = tmp->next);
    data = add_team_to_user(data, client, tmp->uuid);
    print_event_team_create(data);
    return data;
}
