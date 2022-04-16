/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** help.c
*/

#include "server.h"

int print_serv_help(void)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("       port is the port number on which the server ");
    printf("socket listens.\n");
    return 0;
}
