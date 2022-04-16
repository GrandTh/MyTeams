/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** main.c
*/

#include "server.h"

int main(int ac, char **av)
{
    t_server serv = init_struct();

    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return print_serv_help();
    if (check_serv_args(ac, av))
        return 84;
    init_socket(atoi(av[1]), serv);
    return 0;
}
