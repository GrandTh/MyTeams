/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_all_messages.c
*/

#include "client.h"

void print_all_messages(char **array, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    if (atoi(array[1]) == 0) {
        printf("There's no messages with this user\r\n");
    }
    else {
        for (int i = 0; i < atoi(array[1]); i++) {
            getline(&line, &j, stream);
            info = str_to_array_client(line, "/");
            for (int k = 0; info[k]; k++) {
                info[k] = clean_str_client(info[k]);
            }
            client_private_message_print_messages(info[0],
                convert_char_to_time(info[1]), info[2]);
        }
    }
}
