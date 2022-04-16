/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** error_handling.c
*/

#include "server.h"

int check_serv_args(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "Wrong arguments.\n");
        return 1;
    }
    for (size_t i = 0; i < strlen(av[1]) - 1; i++)
        if (av[1][i] < '0' || av[1][i] > '9') {
            fprintf(stderr, "Wrong arguments.\n");
            return 1;
        }
    return 0;
}
