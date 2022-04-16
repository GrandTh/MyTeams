/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_message_unsubscribe.c
*/

#include "client.h"

void print_client_unsubscribe(char **array, int sock)
{
    (void) sock;

    client_print_unsubscribed(array[1], array[2]);
}
