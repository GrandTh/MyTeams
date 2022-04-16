/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** subscribed_cmd.c
*/

#include "server.h"

int how_much_is_sub(t_data data, char *uuid_team)
{
    t_teams *tmp = data.teams;
    int nb_subscribed = 0;

    for (; tmp; tmp = tmp->next) {
        if (strcmp(uuid_team, tmp->uuid) == 0) {
            nb_subscribed = count_lines(tmp->users);
        }
    }
    return nb_subscribed;
}

void print_subs(t_data data, char *uuid_team, int write_fd)
{
    t_teams *tmp = data.teams;
    char *uuid_user = NULL;
    int size = 0;

    size = how_much_is_sub(data, uuid_team);
    dprintf(write_fd, "208 %d\r\n", size);
    for (; tmp; tmp = tmp->next) {
        if (strcmp(uuid_team, tmp->uuid) == 0) {
            for (int i = 0; tmp->users[i]; i++) {
                uuid_user = tmp->users[i];
                print_user_info(data, uuid_user, write_fd);
            }
        }
    }
}

void print_teams(t_data data, int write_fd)
{
    t_teams *tmp = data.teams;
    int size = 0;

    for (; tmp; tmp = tmp->next)
        size++;
    dprintf(write_fd, "209 %d\r\n", size);
    for (; data.teams; data.teams = data.teams->next) {
        sleep(0.2);
        dprintf(write_fd, "%s|%s|%s\r\n", data.teams->uuid, data.teams->name,
            data.teams->description);
    }
}

t_data *subscribed_cmd(t_data *data, char **array, int write_fd)
{
    char *uuid_team = NULL;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 User /login before\r\n");
        return data;
    }
    if (count_lines(array) > 2)
        dprintf(write_fd, "515 Usage: /subscribed [\"uuid_team\"]\r\n");
    if (array[1] == NULL)
        print_teams(*data, write_fd);
    if (count_lines(array) == 2 && strlen(array[1]) == 38
        && double_coat(array[1]) == true) {
        uuid_team = clean_username(array[1]);
        if (check_if_team_exists(data, write_fd, uuid_team))
            print_subs(*data, uuid_team, write_fd);
    }
    return data;
}
