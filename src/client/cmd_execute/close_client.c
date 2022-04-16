/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** close_client.c
*/

#include "client.h"

void close_client(char **array, int sock)
{
    (void) array;

    close(sock);
}
