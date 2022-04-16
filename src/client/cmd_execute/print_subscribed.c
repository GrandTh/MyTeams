/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_subscribed.c
*/

#include "client.h"

void print_subscribed(char **cmd, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    if (atoi(cmd[1]) == 0)
        printf("There's nobody in this team\r\n");
    else {
        for (int i = 0; i < atoi(cmd[1]); i++) {
            getline(&line, &j, stream);
            info = str_to_array_client(line, "|");
            for (int i = 0; info[i]; i++)
                info[i] = (clean_str_client(info[i]));
            client_print_users(info[0], info[1], atoi(info[2]));
        }
    }
}

void print_teams_sub(char **cmd, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    if (atoi(cmd[1]) == 0)
        printf("There's no team\r\n");
    else {
        for (int i = 0; i < atoi(cmd[1]); i++) {
            getline(&line, &j, stream);
            info = str_to_array_client(line, "|");
            for (int i = 0; info[i]; i++)
                info[i] = (clean_str_client(info[i]));
            client_print_teams(info[0], info[1], info[2]);
        }
    }
}
