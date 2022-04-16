/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_list.c
*/

#include "client.h"

void print_teams(char **array, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    if (atoi(array[1]) == 0)
        printf("There is no teams\r\n");
    else {
        for (int i = 0; i < atoi(array[1]); i++) {
            getline(&line, &j, stream);
            line = clean_str_client(line);
            info = str_to_array_client(line, "|");
            client_print_team(info[0], info[1], info[2]);
        }
    }
}

void print_channels(char **array, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    if (atoi(array[1]) == 0)
        printf("There is no channel\r\n");
    else {
        for (int i = 0; i < atoi(array[1]); i++) {
            getline(&line, &j, stream);
            line = clean_str_client(line);
            info = str_to_array_client(line, "|");
            client_print_channel(info[0], info[1], info[2]);
        }
    }
}

void print_threads(char **array, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    if (atoi(array[1]) == 0)
        printf("There is no threads\r\n");
    else {
        for (int i = 0; i < atoi(array[1]); i++) {
            getline(&line, &j, stream);
            line = clean_str_client(line);
            info = str_to_array_client(line, "|");
            client_print_thread(info[0], info[1],
                convert_char_to_time(info[2]), info[3], info[4]);
        }
    }
}

void print_comments(char **array, int sock)
{
    size_t j = 0;
    FILE *stream = 0;
    char *line = NULL;
    char **info = NULL;

    stream = fdopen(sock, "r");
    if (atoi(array[1]) == 0)
        printf("There is no replies\r\n");
    else {
        for (int i = 0; i < atoi(array[1]); i++) {
            getline(&line, &j, stream);
            line = clean_str_client(line);
            info = str_to_array_client(line, "|");
            client_thread_print_replies(info[0], info[1],
                convert_char_to_time(info[2]), info[3]);
        }
    }
}
