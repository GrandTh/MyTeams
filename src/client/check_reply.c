/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** check_reply.c
*/

#include "client.h"

static ptr_reply serv_reply [34] =
{
    &print_user_login, &print_message, &print_event_team_create,
    &print_event_channel_create, &print_event_thread_create,
    &print_event_comment_create, &print_all_user, &print_one_user,
    &print_team_created, &print_channel_created, &print_thread_created,
    &print_comment_created, &print_subscribed, &print_teams_sub, &close_client,
    &print_client_subscribe, &print_client_unsubscribe, &print_user_login,
    &print_user_logout, &print_all_messages, &print_teams, &print_channels,
    &print_threads, &print_comments, &info_user, &info_team, &info_channel,
    &info_thread, &user_doesnt_exists, &team_doesnt_exists,
    &channel_doesnt_exists, &thread_doesnt_exists, &print_user_unauthorized,
    &print_already_exists,
};

static char *serv_cmd [35] =
{
    "130", "140", "151", "152", "153", "154",
    "200", "201", "202", "203", "204", "205", "208", "209",
    "221", "222", "223", "230", "231", "241",
    "251", "252", "253", "254", "255", "256", "257", "258",
    "400", "401", "402", "403", "420",
    "501",
    NULL,
};

int check_reply(char **cmd, int sock)
{
    for (int i = 0; serv_cmd[i]; i++) {
        if (cmd != NULL) {
            if (strcasecmp(cmd[0], serv_cmd[i]) == 0)
                serv_reply[i](cmd, sock);
            }
        }
    return 0;
}
