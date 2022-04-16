/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create_new_thread.c
*/

#include "server.h"

void print_server_event_create_thread(t_client *cli, t_threads *new)
{
    server_event_thread_created(cli->channel_use, new->uuid,
        cli->associated_user, new->title, new->message);
    dprintf(cli->fd_client,
        "204 %s %s %s %s %s Thread created successfully\r\n",
        new->uuid, cli->associated_user,
        replace_char_in_str(new->time, ' ', '|'),
        replace_char_in_str(new->title, ' ', '|'),
        replace_char_in_str(new->message, ' ', '|'));
}

t_threads *add_new_thread(t_threads *threads, char **array, t_client *cli)
{
    t_threads *new = calloc(1, sizeof(t_threads));
    t_threads *tmp = threads;

    new->uuid = generate_uuid();
    new->title = clean_username(array[1]);
    new->message = clean_username(array[2]);
    new->time = generate_time();
    new->team = strdup(cli->team_use);
    new->channel = strdup(cli->channel_use);
    new->users = add_value_in_array(new->users, cli->associated_user);
    new->comments = NULL;
    new->next = NULL;
    print_server_event_create_thread(cli, new);
    if (threads == NULL)
        return new;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = new;
        return threads;
    }
}

int error_gestion_create_thread(t_data *data, char **array, t_client *cli)
{
    if (!check_if_team_exists(data, cli->fd_client, cli->team_use)
    || !check_if_channel_exists(data, cli))
        return 1;
    if (!check_if_user_in_team(data, cli->team_use, cli->associated_user)) {
        dprintf(cli->fd_client, "420 user not subscribe to the team\r\n");
        return 1;
    }
    if (count_lines(array) != 3 || double_coat(array[1]) == false
        || double_coat(array[2]) == false
        || strlen(clean_username(array[1])) >= MAX_NAME_LENGTH
        || strlen(clean_username(array[2])) >= MAX_BODY_LENGTH) {
        dprintf(cli->fd_client,
    "515 Usage: /create [“thread_title”] [“thread_message”]\r\n");
        return 1;
    }
    return 0;
}

t_data *create_new_thread(t_data *data, char **array, t_client *cli)
{
    t_threads *tmp = data->threads;

    if (error_gestion_create_thread(data, array, cli))
        return data;
    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->title, clean_username(array[1]))
            &&!strcmp(tmp->channel, cli->channel_use)) {
            dprintf(cli->fd_client,
                "501 %s This thread already exists\r\n", tmp->title);
                return data;
        }
    data->threads = add_new_thread(data->threads, array, cli);
    print_event_thread_create(data);
    return data;
}
