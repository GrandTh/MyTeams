/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** parse_args_client.c
*/

#include "server.h"

int count_args(char *str)
{
    int count = 0;
    int coat = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '"')
            coat = (coat == 1) ? 2 : 1;
        if (str[i] == ' ' && coat != 1)
            count++;
    }
    return count + 1;
}

char *fill_array_with_coat(char *line, int *j, int *i, int *x)
{
    static int coat = 0;
    char *new = NULL;

    if (line[*i] == '"')
        coat = (coat == 1) ? 2 : 1;
    if ((line[*i] == ' ' || !line[*i + 1]) && coat != 1) {
        new = calloc(*j + 2, sizeof(char));
        for (int y = 0; y <= *j; y++)
            new[y] = line[*i - *j + y];
        if (new[*j] == ' ')
            new[*j] = '\0';
        (*x)++;
        *j = -1;
    }
    return new;
}

char **parse_args_client(char *line)
{
    char **test = NULL;

    if ((count_occurences(line, '"') - 1) % 2 != 0)
        return str_to_array(line, " ");
    test = calloc(count_args(line) + 1, sizeof(char *));
    for (int i = 0, x = 0, j = 0; line[i]; i++, j++) {
        test[x] = fill_array_with_coat(line, &j, &i, &x);
    }
    return test;
}
