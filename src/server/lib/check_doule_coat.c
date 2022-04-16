/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** check_doule_coat.c
*/

#include "server.h"

bool double_coat(char *username)
{
    if (username[0] == '"' && username[strlen(username) - 1] == '"')
        return true;
    return false;
}
