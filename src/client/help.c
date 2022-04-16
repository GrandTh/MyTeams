/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** help.c
*/

#include "client.h"

int print_cli_help(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("       ip is the server ip address on which the server ");
    printf("socket listens.\n");
    printf("       port is the port number on which the server ");
    printf("socket listens.\n");
    return 0;
}
