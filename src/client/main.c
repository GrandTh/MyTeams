/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** main.c
*/

#include "client.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return print_cli_help();
    if (check_cli_args(ac, av) == 1)
        return 84;
    if (create_client(av[1], atoi(av[2])) == 1)
        return 84;
    return 0;
}
