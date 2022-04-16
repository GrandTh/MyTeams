/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** choose_what_use.c
*/

#include "server.h"

void use_thread(char **array, int fd, t_client *client)
{
    if ((double_coat(array[1]) == false || strlen(array[1]) != 38)
        || (double_coat(array[2]) == false || strlen(array[2]) != 38)
        || (double_coat(array[3]) == false || strlen(array[3]) != 38)) {
        dprintf(fd,
    "515 Usage: /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”]\r\n");
        return;
    }
    client->team_use = clean_username(array[1]);
    client->channel_use =  clean_username(array[2]);
    client->thread_use = clean_username(array[3]);
    client->use = 1;
    dprintf(fd,
    "210 You are in %s thread, in %s channel, in %s team\r\n",
    client->thread_use, client->channel_use, client->team_use);
}

void use_channel(char **array, int fd, t_client *client)
{
    if ((double_coat(array[1]) == false || strlen(array[1]) != 38)
        || (double_coat(array[2]) == false || strlen(array[2]) != 38)) {
        dprintf(fd,
    "515 Usage: /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”]\r\n");
        return;
    }
    client->team_use = clean_username(array[1]);
    client->channel_use = clean_username(array[2]);
    client->use = 1;
    dprintf(fd,
    "210 You are in %s channel, in %s team\r\n", client->channel_use,
    client->team_use);
}

void use_team(char **array, int fd, t_client *client)
{
    if (double_coat(array[1]) == false || strlen(array[1]) != 38) {
        dprintf(fd,
    "515 Usage: /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”]\r\n");
        return;
    }
    client->team_use = clean_username(array[1]);
    client->use = 1;
    dprintf(fd, "210 You are in %s team\r\n", client->team_use);
}

void use_nothing(int fd, t_client *client)
{
    client->team_use = NULL;
    client->channel_use = NULL;
    client->thread_use = NULL;
    client->use = 1;
    dprintf(fd, "200 Use no team/channel/thread\r\n");
}
