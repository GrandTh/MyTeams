/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** generate_timestamp.c
*/

#include "server.h"

char *generate_time(void)
{
    char *buffer = malloc(sizeof(char) * 80);
    time_t timestamp = time(NULL);
    struct tm *pTime = localtime(&timestamp);

    strftime(buffer, 80, "%c", pTime);
    return buffer;
}
