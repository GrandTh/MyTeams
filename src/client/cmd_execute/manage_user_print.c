/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** manage_user_print.c
*/

#include "client.h"

void print_all_user(char **cmd, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    for (int i = 0; i < atoi(cmd[1]); i++) {
        getline(&line, &j, stream);
        info = str_to_array_client(line, " ");
        client_print_users(info[0], info[1], atoi(info[2]));
    }
}

void print_one_user(char **cmd, int sock)
{
    (void)sock;

    if (count_line_client(cmd) == 4) {
        client_print_user(cmd[1], cmd[2], atoi(cmd[3]));
    }
}
