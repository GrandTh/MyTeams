/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_user_login_out.c
*/

#include "client.h"

void print_user_login(char **array, int sock)
{
    (void) array;
    (void) sock;

    client_event_logged_in(array[1], array[2]);
}

void print_user_logout(char **array, int sock)
{
    (void) array;
    (void) sock;

    client_event_logged_out(array[1], array[2]);
}
