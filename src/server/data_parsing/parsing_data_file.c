/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** parsing_data_file.c
*/

#include "server.h"

static parsing_func function [6] =
{
    &parse_user,
    &parse_teams,
    &parse_messages,
    &parse_channels,
    &parse_threads,
    &parse_comments
};

static char *data_pars[6] =
{
    ".user\n",
    ".teams\n",
    ".messages\n",
    ".channels\n",
    ".threads\n",
    ".comments\n",
};

char **retrieve_clean_value(char **array)
{
    char *tmp = NULL;
    char **new = NULL;
    int size = 0;

    for (; array[size]; size++);
    new = calloc(size + 1, sizeof(char *));
    for (int i = 0; array[i]; i++) {
        tmp = strchr(array[i], '^') + 1;
        new[i] = clean_str(tmp);
        free(array[i]);
    }
    free(array);
    return new;
}

t_data *parsing_data(t_data *data)
{
    FILE *fd = fopen("database/data.txt", "r");
    char *line = NULL;
    size_t n = 0;

    if (!fd)
        return data;
    while (getline(&line, &n, fd) != -1)
        for (int i = 0; data_pars[i]; i++)
            if (!strcmp(line, data_pars[i])) {
                getline(&line, &n, fd);
                data = function[i](data, line);
            }
    if (line)
        free(line);
    fclose(fd);
    return data;
}
