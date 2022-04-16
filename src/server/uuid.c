/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** uuid.c
*/

#include "server.h"

char *generate_uuid(void)
{
    uuid_t my_binuuid;
    char *uuid = malloc(37);

    uuid_generate_random(my_binuuid);
    uuid_unparse(my_binuuid, uuid);
    return uuid;
}
