/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_info_cmd.c
*/

#include "client.h"

void info_user(char **array, int sock)
{
    (void) sock;
    (void) array;
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    getline(&line, &j, stream);
    line = clean_str_client(line);
    info = str_to_array_client(line, "|");
    client_print_user(info[0], info[1], atoi(info[2]));
}

void info_team(char **array, int sock)
{
    (void) sock;
    (void) array;
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    getline(&line, &j, stream);
    line = clean_str_client(line);
    info = str_to_array_client(line, "|");
    client_print_team(info[0], info[1], info[2]);
}

void info_channel(char **array, int sock)
{
    (void) sock;
    (void) array;
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    getline(&line, &j, stream);
    line = clean_str_client(line);
    info = str_to_array_client(line, "|");
    client_print_channel(info[0], info[1], info[2]);
}

void info_thread(char **array, int sock)
{
    (void) sock;
    (void) array;
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    getline(&line, &j, stream);
    line = clean_str_client(line);
    info = str_to_array_client(line, "|");
    client_print_thread(info[0], info[1], convert_char_to_time(info[2]),
        info[3], info[4]);
}
