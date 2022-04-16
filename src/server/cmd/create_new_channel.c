/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create_new_channel.c
*/

#include "server.h"

void print_server_event_create_channel(t_client *client, t_channels *new)
{
    server_event_channel_created(client->team_use, new->uuid, new->name);
    dprintf(client->fd_client, "203 %s %s %s Channel created successfully\r\n",
        new->uuid, replace_char_in_str(new->name, ' ', '|'),
        replace_char_in_str(new->description, ' ', '|'));
}

t_channels *add_new_channel(t_channels *channels, char **array,
    t_client *client)
{
    t_channels *new = calloc(1, sizeof(t_channels));
    t_channels *tmp = channels;

    new->uuid = generate_uuid();
    new->name = clean_username(array[1]);
    new->description = clean_username(array[2]);
    new->team = strdup(client->team_use);
    new->users = add_value_in_array(new->users, client->associated_user);
    new->next = NULL;
    print_server_event_create_channel(client, new);
    if (channels == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return channels;
    }
}

int error_gestion_create_channel(t_data *data, char **array, t_client *cli)
{
    if (!check_if_team_exists(data, cli->fd_client, cli->team_use))
        return 1;
    if (!check_if_user_in_team(data, cli->team_use, cli->associated_user)) {
        dprintf(cli->fd_client, "420 user not subscribe to the team\r\n");
        return 1;
    }
    if (count_lines(array) != 3 || double_coat(array[1]) == false
        || double_coat(array[2]) == false
        || strlen(clean_username(array[1])) >= MAX_NAME_LENGTH
        || strlen(clean_username(array[2])) >= MAX_DESCRIPTION_LENGTH) {
        dprintf(cli->fd_client,
    "515 Usage: /create [“channel_name”] [“channel_description”]\r\n");
        return 1;
    }
    return 0;
}

t_data *create_new_channel(t_data *data, char **array, t_client *cli)
{
    t_channels *tmp = data->channels;

    if (error_gestion_create_channel(data, array, cli))
        return data;
    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->name, clean_username(array[1]))
            && !strcmp(tmp->team, cli->team_use)) {
            dprintf(cli->fd_client,
                "501 %s This channel already exists\r\n", tmp->name);
                return data;
        }
    data->channels = add_new_channel(data->channels, array, cli);
    print_event_channel_create(data);
    return data;
}
