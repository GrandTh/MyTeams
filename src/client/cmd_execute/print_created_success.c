/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_created_success.c
*/

#include "client.h"

void print_team_created(char **array, int sock)
{
    (void) sock;

    client_print_team_created(array[1],
        replace_char_in_str(array[2], '|', ' '),
        replace_char_in_str(array[3], '|', ' '));
}

void print_channel_created(char **array, int sock)
{
    (void) sock;

    client_print_channel_created(array[1],
        replace_char_in_str(array[2], '|', ' '),
        replace_char_in_str(array[3], '|', ' '));
}

void print_thread_created(char **array, int sock)
{
    (void) sock;

    client_print_thread_created(array[1], array[2],
        convert_char_to_time(replace_char_in_str(array[3], '|', ' ')),
        replace_char_in_str(array[4], '|', ' '),
        replace_char_in_str(array[5], '|', ' '));
}

void print_comment_created(char **array, int sock)
{
    (void) sock;

    client_print_reply_created(array[1], array[2],
    convert_char_to_time(replace_char_in_str(array[3], '|', ' ')),
    replace_char_in_str(array[4], '|', ' '));
}
