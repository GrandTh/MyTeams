/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** print_subs_info.c
*/

#include "server.h"

void print_user_info(t_data data, char *user_uuid, int write_fd)
{
    t_user *tmp = data.user;

    for (; tmp; tmp = tmp->next) {
        if (strcmp(user_uuid, tmp->uuid) == 0) {
            sleep(0.2);
            dprintf(write_fd, "%s|%s|%d\r\n", tmp->uuid, tmp->name,
                tmp->connected);
        }
    }
}
