/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_message_client.c
*/

#include "client.h"

void print_message(char **array, int sock)
{
    (void) sock;
    (void) array;
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    getline(&line, &j, stream);
    info = str_to_array_client(line, "|");
    for (int k = 0; info[k]; k++) {
        info[k] = clean_str_client(info[k]);
    }
    client_event_private_message_received(info[0], info[1]);
}
