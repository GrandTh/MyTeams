/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_event_create.c
*/

#include "client.h"

void print_event_team_create(char **array, int sock)
{
    (void)sock;

    client_event_team_created(array[1],
        replace_char_in_str(array[2], '|', ' '),
        replace_char_in_str(array[3], '|', ' '));
}

void print_event_channel_create(char **array, int sock)
{
    (void) sock;

    client_event_channel_created(array[1],
        replace_char_in_str(array[2], '|', ' '),
        replace_char_in_str(array[3], '|', ' '));
}

void print_event_thread_create(char **array, int sock)
{
    (void) sock;

    client_event_thread_created(array[1], array[2],
        convert_char_to_time(replace_char_in_str(array[3], '|', ' ')),
        replace_char_in_str(array[4], '|', ' '),
        replace_char_in_str(array[5], '|', ' '));
}

void print_event_comment_create(char **array, int sock)
{
    (void) sock;

    client_event_thread_reply_received(array[1], array[2], array[3],
        replace_char_in_str(array[4], '|', ' '));
}
