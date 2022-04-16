/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** ctrlc_gestion.c
*/

#include "client.h"

bool ctrlc_active(int new)
{
    static bool status;

    if (new != -1)
        status = new;
    return status;
}

void inthandler(int sig)
{
    (void) sig;
    ctrlc_active(0);
}
