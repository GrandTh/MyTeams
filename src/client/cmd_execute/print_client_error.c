/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_client_error.c
*/

#include "client.h"

void print_user_unauthorized(char **array, int sock)
{
    (void) array;
    (void) sock;

    client_error_unauthorized();
}

void print_already_exists(char **array, int sock)
{
    (void) array;
    (void) sock;

    client_error_already_exist();
}
