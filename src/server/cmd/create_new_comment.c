/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create_new_comment.c
*/

#include "server.h"

void print_server_event_create_comment(t_client *cli, t_comments *new)
{
    server_event_reply_created(new->thread, new->user, new->message);
    dprintf(cli->fd_client, "205 %s %s %s %s Reply created successfully\r\n",
        new->thread, new->user, replace_char_in_str(new->time, ' ', '|'),
        replace_char_in_str(new->message, ' ', '|'));
}

void add_new_comment(t_comments **comments, char **array, t_client *cli)
{
    t_comments *new = calloc(1, sizeof(t_comments));

    new->user = strdup(cli->associated_user);
    new->message = clean_username(array[1]);
    new->time = generate_time();
    new->team = strdup(cli->team_use);
    new->thread = strdup(cli->thread_use);
    new->next = NULL;
    print_server_event_create_comment(cli, new);
    while (*comments)
        comments = &((*comments)->next);
    *comments = new;
}

t_data *create_new_comment(t_data *data, char **array, t_client *cli)
{
    t_threads *tmp = data->threads;

    if (!check_if_team_exists(data, cli->fd_client, cli->team_use)
    || !check_if_channel_exists(data, cli)
    || !check_if_thread_exists(data, cli))
        return data;
    if (!check_if_user_in_team(data, cli->team_use, cli->associated_user)) {
        dprintf(cli->fd_client, "420 user not subscribe to the team\r\n");
        return data;
    }
    if (count_lines(array) != 2 || double_coat(array[1]) == false
        || strlen(clean_username(array[1])) >= MAX_BODY_LENGTH) {
        dprintf(cli->fd_client, "515 Usage: /create [“comment_body”]\r\n");
        return data;
    }
    for (; tmp; tmp = tmp->next)
        if (!strcmp(tmp->uuid, cli->thread_use)) {
            add_new_comment(&tmp->comments, array, cli);
            break;
        }
    print_event_comment_create(data, tmp->uuid);
    return data;
}
