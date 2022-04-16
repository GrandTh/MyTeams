/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** element_doesnt_exists.c
*/

#include "client.h"

void user_doesnt_exists(char **array, int sock)
{
    (void) sock;

    client_error_unknown_user(array[1]);
}

void team_doesnt_exists(char **array, int sock)
{
    (void) sock;

    client_error_unknown_team(array[1]);
}

void channel_doesnt_exists(char **array, int sock)
{
    (void) sock;

    client_error_unknown_channel(array[1]);
}

void thread_doesnt_exists(char **array, int sock)
{
    (void) sock;

    client_error_unknown_thread(array[1]);
}
