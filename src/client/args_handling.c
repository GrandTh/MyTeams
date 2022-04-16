/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** args_handling.c
*/

#include "client.h"

int check_cli_args(int ac, char **av)
{
    if (ac != 3) {
        fprintf(stderr, "Wrong arguments.\n");
        return 1;
    }
    for (size_t i = 0; i < strlen(av[2]) - 1; i++)
        if (av[2][i] < '0' || av[2][i] > '9') {
            fprintf(stderr, "Wrong arguments.\n");
            return 1;
        }
    for (size_t i = 0; i < strlen(av[1]) - 1; i++)
        if ((av[1][i] < '0' || av[1][i] > '9') && av[1][i] != '.') {
            fprintf(stderr, "Wrong arguments.\n");
            return 1;
        }
    return 0;
}

int my_exit_failure(char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}
